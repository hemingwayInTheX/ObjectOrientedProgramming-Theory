#include <iostream>
using namespace std;

#ifndef Hospital_h
#define Hospital_h

class Hospital {
    Dept* dept;
public:
    Hospital() {
        dept = new Dept[3];
    }
    ~Hospital() { delete[] dept; }
    void start();
};

class Dept {

};

#endif
