// Name     : Mandelbrot.h

#ifndef MANDELBROT_H_
#define MANDELBROT_H_


namespace fgen{

class Mandelbrot{
        public:
            static const int MAX_ITERATIONS = 3000;

        public:
            Mandelbrot();
            virtual ~Mandelbrot();

            static int getIterations(double x, double y);
};

}; // end namespace fgen

#endif /* MANDELBROT_H_ */