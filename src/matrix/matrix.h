//
// Created by shahnoor on 5/2/2017.
//

#ifndef NUMCPP_MATRIX_H
#define NUMCPP_MATRIX_H

#include "nArray.h"
#include <vector>
#include <cstdlib>


enum DPA {
    // DPA -> Dot Product Algorithm
    StraightForward=0,
    StrassenAlgorithm=1
};

class Matrix: public nArray{
private:

public:
    Matrix();
    Matrix(size_t row, size_t column);
    Matrix(std::vector<double> mat, size_t row, size_t column);
    Matrix(const Matrix &matOb); // copy constructor
    Matrix(const nArray &nArrayOb);

    Matrix identity(size_t order);

    Matrix subMatrix(size_t row_i, size_t row_f, size_t col_i, size_t col_f);

    // performs operation with the corresponding elements
    Matrix operator+(Matrix matB);
    Matrix operator-(Matrix matB);
    Matrix operator*(Matrix matB);
    Matrix operator*(double value);
};

//default method is the most efficient methods
Matrix dot(Matrix &matA, Matrix &matB);
Matrix transpose(Matrix &matA);
Matrix adjoint(Matrix &matA);
double trace(Matrix &matA);

/*
 *  Every possible methods are available as static method and the
 *  most efficient method is called when the dot() method is called
 */
//dot product using normal formula -> O(n^3)
nArray dot_straight(nArray &matA, nArray &matB);
Matrix dot_straight(Matrix &matA, Matrix &matB);

//dot product using Strassen's Algorithm -> O(n^2.807355)
nArray dot_strassen(nArray &matA, nArray &matB);
//    static Matrix dot_strassen(Matrix &matA, Matrix &matB);

//determinant of a matrix
double det(nArray &matA);
double det(Matrix &matA);

#endif //NUMCPP_MATRIX_H
