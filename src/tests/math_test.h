
#include <iostream>
#include <iomanip>
#include "../math/math.h"

using namespace std;

void math_test_1(){
    cout << "********** math test 1 **********" << endl;
    cout.precision(50);
    for(size_t i=0 ; i<= 50 ; i++){
        cout << "factorial(" << i << ") = " << factorial(i) << endl;
    }
    for(double i=0 ; i<= 50 ; i++){
        cout << "ffactorial(" << i << ") = " << ffactorial(i) << endl;
    }
}

void math_test_2(){
    cout << "********** math test 2 **********" << endl;
    cout << "permutation nPr" << endl;
    cout << "nPr(5, 2)  : " << nPr(5, 2) << endl;
    cout << "fnPr(5, 2) : " << fnPr(5, 2) << endl;
    cout << "nPr(5, 3)  : " << nPr(5, 3) << endl;
    cout << "fnPr(5, 3) : " << fnPr(5, 3) << endl;
    cout << "nPr(10, 8)  : " << nPr(10, 8) << endl;
    cout << "fnPr(10, 8) : " << fnPr(10, 8) << endl;
    cout << "nPr(10, 5)  : " << nPr(10, 5) << endl;
    cout << "fnPr(10, 5) : " << fnPr(10, 5) << endl;
}