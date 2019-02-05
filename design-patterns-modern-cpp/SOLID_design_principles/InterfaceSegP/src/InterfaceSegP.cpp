//Interface Segregation Principle
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Document;

//struct IMachine
//{
//  virtual void print(Document &doc) = 0;
//  virtual void fax(Document &doc) = 0;
//  virtual void scan(Document &doc) = 0;
//};
//
//struct Printer : IMachine
//{
//  void print(Document &doc) override
//  {
//    //OK
//  }
//
//  void fax(Document &doc) override
//  {
//    //We don't need blank
//  }
//
//  void scan(Document &doc) override
//  {
//    //We don't need throw exception
//  }
//
//};

struct iPrint
{
  virtual void print(Document &doc) = 0;
};

struct iFax
{
  virtual void fax(Document &doc) = 0;
};

struct iScan
{
  virtual void scan(Document &doc) = 0;
};

struct Printer : iPrint
{
  void print(Document &doc) override{
    //Ok
  }
};

struct Fax : iFax
{
  void fax(Document &doc) override{
    //OK
  }
};

struct Scan : iScan
{
  void scan(Document &doc) override{
    //Ok
  }
};

struct iMachine : iPrint, iScan {};

struct Machine : iMachine
{
  Printer& printer;
  Scan& scanner;

  Machine(Printer &printer, Scan &scanner) : printer(printer), scanner(scanner) {};

  void print(Document &doc) override{
    printer.print(doc);
  }

  void scan(Document &doc) override{
    scanner.scan(doc);
  }
};


int main()
{
  
};