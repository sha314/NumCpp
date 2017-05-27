
#ifndef NUMCPP_MATRIX_TEST_H
#define NUMCPP_MATRIX_TEST_H

#include <iostream>
using namespace std;

void test_1(){
     cout << endl <<  "######################## Test 1 ####################" << endl;
     std::vector<double> vec;
     for(size_t i =0 ; i < 9 ; i++){
         vec.push_back(i*i);
     }
     Matrix mat(vec, 3, 3);
     cout << endl << "matA" << endl;
     mat.view();
     cout << endl << "The identity matrix (matB)" << endl;
     Matrix mat2 = mat.identity(3);
     mat2.view();
     cout << endl <<  "performing the dot product" << endl;
     mat = dot(mat, mat2);
     mat = dot_straight(mat, mat2);
     cout << endl <<  "Displaying the dot product result" << endl;
     mat.view();
 }

void test_2(){
    cout << endl <<  "######################## Test 2 ####################" << endl;
    std::vector<double> vec;
    for(size_t i =0 ; i < 9 ; i++){
        vec.push_back(i*i);
    }
    nArray mat(vec, 3, 3);
    cout << endl << "matA" << endl;
    mat.view();

    nArray mat2(mat);
    cout << mat.get_row() << "\t" << mat.get_col() << endl;
    mat2.view();
}

void test_3(){
    cout << endl <<  "######################## Test 3 ####################" << endl;
    std::vector<double> v{1,2,3,4,5,6,7,8,9};
    Matrix mat(v, 3, 3);
    mat.view();
    mat.subMatrix(0,2,0,2).view();
    mat.subMatrix(0,3,0,2).view();
    mat.subMatrix(0,2,1,3).view();
    mat.subMatrix(1,2,0,3).view();
    mat.subMatrix(0,3,0,1).view();
}

void test_4(){
    std::vector<double> v1{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}, v2{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    Matrix mat1(v1, 4, 4), mat2(v2, 4, 4);
    dot_strassen(mat1, mat2);
    mat1.view();
    mat2.view();
}

void test_5(){
    std::vector<double> v{1,0,9,4,0,6,3,8,-1};
    nArray mat(v, 3, 3);
    cout << det(mat);
}

#endif