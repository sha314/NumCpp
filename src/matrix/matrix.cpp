
//
// Created by shahnoor on 5/2/2017.
//

#include <iostream>
#include <iomanip>
#include "matrix.h"
#include "../flags.h"


Matrix::Matrix() : nArray() {}

Matrix::Matrix(size_t row, size_t column) : nArray(row, column) {}

Matrix::Matrix(std::vector<double> mat, size_t row, size_t column) : nArray(mat, row, column) {}

Matrix::Matrix(const Matrix &matOb) : nArray(matOb){}

Matrix::Matrix(const nArray &nArrayOb) : nArray(nArrayOb) {}

Matrix Matrix::identity(size_t order) {
    std::vector<double> mat(order * order);
    for(size_t i=0; i < order ; i++){
        for(size_t j=0 ; j < order ; j++){
            if(i==j)
                mat[i * order + j] = 1;
            else
                mat[i * order + j] = 0;
        }
    }
    return Matrix(mat, order, order);
}

Matrix Matrix::subMatrix(size_t row_i, size_t row_f, size_t col_i, size_t col_f) {
    return Matrix(this->subArray(row_i, row_f, col_i, col_f));
}


Matrix Matrix::operator+(Matrix matB) {
    if(row != matB.row || column != matB.column){
        std::cout << "Array size mismatched : (file, line) " << __FILE__ << "," <<  __LINE__ << std::endl;
    }
    size_t a = row*column;
    std::vector<double> v(a);
    for(size_t i=0 ; i < a ; i++){
        v[i] = array[i] + matB.array[i];
    }
    return Matrix(v, row, column);
}

Matrix Matrix::operator-(Matrix matB) {
    if(row != matB.row || column != matB.column){
        std::cout << "Array size mismatched : (file, line) " << __FILE__ << "," <<  __LINE__ << std::endl;
    }
    size_t a = row*column;
    std::vector<double> v(a);
    for(size_t i=0 ; i < a ; i++){
        v[i] = array[i] - matB.array[i];
    }
    return Matrix(v, row, column);
}

Matrix Matrix::operator*(Matrix matB) {
    if(row != matB.row || column != matB.column){
        std::cout << "Array size mismatched : (file, line) " << __FILE__ << "," <<  __LINE__ << std::endl;
    }
    size_t a = row*column;
    std::vector<double> v(a);
    for(size_t i=0 ; i < a ; i++){
        v[i] = array[i] * matB.array[i];
    }
    return Matrix(v, row, column);
}

Matrix Matrix::operator*(double value) {
    size_t a = row*column;
    std::vector<double> v(a);
    for(size_t i=0 ; i < a ; i++){
        v[i] = array[i] * value;
    }
    return Matrix(v, row, column);
}

double trace(Matrix &matA) {//TODO
    return 0;
}

Matrix transpose(Matrix &matA) {//TODO
    return Matrix();
}

Matrix adjoint(Matrix &matA) {//TODO
    return Matrix();
}

/*******************************************
* Dot product Algorithms or DPA
********************************************/

/**
*   Evaluates dot product of two matrices
*/
Matrix dot(Matrix &matA, Matrix &matB) {
    nArray matC(matA.get_row(), matB.get_col());
    // double a=0, b=0, c=0;
    for(size_t i=0 ; i < matC.get_row() ; i++){
        for(size_t j=0 ; j < matC.get_col() ; j++){
            matC[i * matC.get_col() + j] = 0;
            for(size_t k=0 ; k < matA.get_col() ; k++){
                matC[i * matC.get_col() + j] += matA.get(i, k) * matB.get(k, j);
            }
        }
    }
    return matC;
}

//The straight forward formula : DPA[0]
nArray dot_straight(nArray &matA, nArray &matB) {
    // Matrix matC(matA.get_row(), matB.get_col());
    size_t r = matA.get_row();
    size_t c = matB.get_col();
    nArray matC(r, c);
    for(size_t i=0 ; i < r ; i++){
        for(size_t j=0 ; j < c ; j++){
            matC[i * matC.get_col() + j] = 0;
            for(size_t k=0 ; k < matA.get_col() ; k++){
                matC[i * matC.get_col() + j] += matA.get(i, k)  * matB.get(k, j);
            }
        }
    }
    return matC;
}

//The straight forward formula : DPA[0]
Matrix dot_straight(Matrix &matA, Matrix &matB) {
    // Matrix matC(matA.get_row(), matB.get_col());
    size_t r = matA.get_row();
    size_t c = matB.get_col();
    Matrix matC(r, c);
    for(size_t i=0 ; i < r ; i++){
        for(size_t j=0 ; j < c ; j++){
            matC[i * matC.get_col() + j] = 0;
            for(size_t k=0 ; k < matA.get_col() ; k++){
                matC[i * matC.get_col() + j] += matA.get(i, k)  * matB.get(k, j);
            }
        }
    }
    return matC;
}



//The Strassen's Algorithm : DPA[1]
nArray dot_strassen(nArray &matA, nArray &matB) {//TODO
    // TODO
    // Find 10 S matrices

    /*
     * rA -> row index of the four sub-matrix of A
     * cA -> column index of the four sub-matrix of A
     *
     * rB -> row index of the four sub-matrix of B
     * cB -> column index of the four sub-matrix of B
     */

    // if matrices row and column is divisible by 2 then divide otherwise perform the straight forward method
    size_t r[4], c[4];
    if(matA.get_row() % 2 != 0)
        std::cout << "row A is not divisible by 2 : " << __LINE__ << std::endl;
    r[0] = matA.get_row() / 2;
    r[1] = matA.get_row();

    if(matA.get_col() % 2 != 0)
        std::cout << "col A is not divisible by 2 : " << __LINE__ << std::endl;
    c[0] = matA.get_col() / 2;
    c[1] = matA.get_col();

    if(matB.get_row() % 2 != 0)
        std::cout << "row B is not divisible by 2 : " << __LINE__ << std::endl;
    r[2] = matB.get_row() / 2;
    r[3] = matB.get_row();

    if(matB.get_col() % 2 != 0)
        std::cout << "col B is not divisible by 2 : " << __LINE__ << std::endl;
    c[2] = matB.get_col() / 2;
    c[3] = matB.get_col();

    std::cout << "Calculated indices" << std::endl;
    std::cout << "matrix A : (r0, r1, c0, c1) : " << r[0] << ", " << r[1] << ", " << c[0] << ", " << c[1] << std::endl;
    std::cout << "matrix B : (r0, r1, c0, c1) : " << r[2] << ", " << r[3] << ", " << c[2] << ", " << c[3] << std::endl;

    nArray S[10];
    S[0] = matB.subArray(0, r[2], c[2], c[3]);


    return nArray();
}

/*
 *  00  01  02  00  01
 *  10  11  12  10  11
 *  20  21  22  20  21
 *
 *  determinant = 00*11*22 + 01*12*20 + 02*10*21 - 20*11*02 - 21*12*00 - 22*10*01
 */
double det(nArray &matA) {//TODO
    double sum = 0, upper=1, lower=1;
    const size_t r=matA.get_row(), c=matA.get_col();
    size_t r1=0, r2= r-1, c12 = 0;//size_t is non-negative integer

    for(size_t i=0; i<r ; i++){
        c12 = i;
        for(size_t j=0 ; j<c ; j++){
            //checking
            if(r1 >= r)  r1 = 0;
            if(c12 >= c)  c12 = 0;

            if(debugging){
                std::cout << "(r1,c) = " << r1 << "," << c12;
                std::cout << " (r2,c) = " << r2 << "," << c12 << std::endl;
            }

            upper *= matA.get(r1, c12);
            lower *= matA.get(r2, c12);

            //checking here (after required task is completed) since size_t cannot be negative
            if(r2 == 0)  r2 = r ;

            c12 ++;
            r1 ++;
            r2--;
        }
        sum += upper - lower;

        //reset upper and lower variable
        upper = 1;
        lower = 1;
    }
    return sum;
}

double det(Matrix &matA) {//TODO
    double sum = 0, upper=1, lower=1;
    const size_t r=matA.get_row(), c=matA.get_col();
    size_t r1=0, r2= r-1, c12 = 0;//size_t is non-negative integer

    for(size_t i=0; i<r ; i++){
        c12 = i;
        for(size_t j=0 ; j<c ; j++){
            //checking
            if(r1 >= r)  r1 = 0;
            if(c12 >= c)  c12 = 0;

            if(debugging){
                std::cout << "(r1,c) = " << r1 << "," << c12;
                std::cout << " (r2,c) = " << r2 << "," << c12 << std::endl;
            }

            upper *= matA.get(r1, c12);
            lower *= matA.get(r2, c12);

            //checking here (after required task is completed) since size_t cannot be negative
            if(r2 == 0)  r2 = r ;

            c12 ++;
            r1 ++;
            r2--;
        }
        sum += upper - lower;
        //reset upper and lower variable
        upper = 1;
        lower = 1;
    }
    return sum;
}






