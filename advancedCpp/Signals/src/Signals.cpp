#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <chrono>
#include <thread>
#include <memory>
#include <execinfo.h>

 
struct sigaction act;

static void dump_trace() {
    void * buffer[255];
    const int calls = backtrace(buffer,
        sizeof(buffer) / sizeof(void *));
    backtrace_symbols_fd(buffer, calls, 1);
    //exit(EXIT_FAILURE);
}

void sighandler(int signum, siginfo_t *info, void *ptr)
{
    printf("Received signal %d\n", signum);
    printf("Signal originates from process %lu\n",
        (unsigned long)info->si_pid);
    dump_trace();
    printf("Your mother will abort not me!\n");
}



void wait_A()
{
    printf("Enter wait A \n");
    std::chrono::milliseconds timespan(1000); // or whatever
    std::this_thread::sleep_for(timespan);
}

void wait_B()
{
    printf("Enter wait B \n");
    std::chrono::milliseconds timespan(2000); // or whatever
    std::this_thread::sleep_for(timespan);
}

int main()
{
    printf("I am %lu\n", (unsigned long)getpid());

    memset(&act, 0, sizeof(act));

    act.sa_sigaction = sighandler;
    act.sa_flags = SA_SIGINFO;

    sigaction(SIGABRT, &act, NULL);

    // Waiting for CTRL+C...
    //std::chrono::milliseconds timespan(111605); // or whatever
    //std::this_thread::sleep_for(timespan);
    printf("Starting process \n");

    while(1)
    {
        wait_A();
        wait_B();
        printf("Ticking \n");
    }

    return 0;
}

