//
// Created by shahnoor on 5/8/2017.
//

/**
    Author     : shahnoor
    mail       : shahnoor3pl@gmail.com
    date       : May 8, 2017
*/

#ifndef NUMCPP_NARRAY_H
#define NUMCPP_NARRAY_H

#include <cstdlib>
#include <vector>
#include <string>

/**
    Final Target is to create a multidimensional Template array
*/
//double data structure
class nArray{
protected:
    std::vector<double> array;
    size_t row      =   1   ;
    size_t column   =   1   ;
    //constants
    int WIDTH = 8;
    int PREC = 5;
public:
    nArray();
    nArray(size_t row, size_t column);
    nArray(std::vector<double> array, size_t row, size_t column);
    nArray(const nArray &nArrayOb); // copy constructor
    ~nArray();

    size_t get_row();
    size_t get_col();

    void set(size_t row, size_t column, double value);
    double get(size_t row, size_t column);

    double & operator[](size_t index);

    void view();
    std::string shape_str();
    int *shape();

    nArray subArray(size_t row_i, size_t row_f, size_t col_i, size_t col_f);

};

#endif //NUMCPP_NARRAY_H
