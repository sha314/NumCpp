#include <iostream>
#include "matrix/matrix.h"
#include "matrix/nArray.h"

//test headers
#include "tests/matrix_test.h"
#include "tests/ode_test.h"
#include "tests/math_test.h"

using namespace std;

void matrix_tests(){
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
}


void ode_tests(){
    ode_test_1();
    ode_test_2();
}

void math_tests(){
    // math_test_1();
    math_test_2();
}

int main(int argc, char ** argv) {
    // matrix_tests();
    // ode_tests();
    math_tests();


    return 0;
}
