class Container{
    public:
        Container(int s) :elem{new double[s]},sz{s}{};    // construct a Container
        double& operator[](int i){return elem[i];}  // element access
        int size() {return sz;}

    private:
        double* elem;   // pointer to the elements
        int sz;       // the number of elements
};