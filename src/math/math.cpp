
#include "math.h"
#include <iostream>

//finds the factorial of a number
size_t factorial(size_t n){
    if( n > 20){
        std::cout << "Too large number to calculate factorial" << std::endl;
        return 1;
    }
    size_t a=1;
    while(n > 0) a *= n--;
    return a;
}

//finds the permutation function nPr
size_t nPr(size_t n, size_t r){
    size_t a=1;
    while(n > r)
        a *= n--;
    return a;
    // return factorial(n) / factorial(r);
}

//finds the Combination function nCr
size_t nCr(size_t n, size_t r){
    return nPr(n,r)/factorial(n-r);
    // return factorial(n) / (factorial(r) * factorial(n-r));
}

//finds the factorial of a number
double ffactorial(double n){
    double a=1;
    while(n > 0) a *= n--;
    return a;
}

//finds the permutation function nPr
double fnPr(double n, double r){
    double a=1;
    while(n > r)
        a *= n--;
    return a;
    // return factorial(n) / factorial(r);
}

//finds the Combination function nCr
double fnCr(double n, double r){
    return fnPr(n,r)/factorial(n-r);
    // return factorial(n) / (factorial(r) * factorial(n-r));
}

