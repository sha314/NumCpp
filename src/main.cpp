#include <iostream>
#include "matrix/matrix.h"
#include "matrix/nArray.h"

//test headers
#include "tests/matrix_test.h"
#include "tests/ode_test.h"

using namespace std;

void matrix_test(){
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
}


void ode_test(){
    ode_test_1();
    ode_test_2();
}

int main(int argc, char ** argv) {
    // matrix_test();
    ode_test();


    return 0;
}
