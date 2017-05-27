//
// Created by shahnoor on 5/8/2017.
//
/**
    Author     : shahnoor
    mail       : shahnoor3pl@gmail.com
    date       : May 8, 2017
*/
#include "nArray.h"


#include <iostream>
#include <iomanip>

nArray::nArray() {
    this->row = 1;
    this->column = 1;
    this->array = std::vector<double>(row*column);
}

nArray::nArray(size_t row, size_t column) {
    this->row = row;
    this->column = column;
    this->array = std::vector<double>(row*column);
}

nArray::nArray(std::vector<double> array, size_t row, size_t column) {
    if(row * column > array.size()){
        std::cout << std::endl << "!!!Row Column size misarrayched!!!" << std::endl;
        std::cout << "Setting row = 1 to prevent initial errors" << std::endl;
        row = 1;
        column = array.size();
    }
    this->row = row;
    this->column = column;
    this->array.reserve(array.size());
    for(size_t r=0 ; r < this->row ; r++){
        for (int c = 0; c < this->column; ++c) {
            this->array[r * this->column + c] = array[r * this->column + c];
        }
    }
}

nArray::nArray(const nArray &nArrayOb) {
    this->row = nArrayOb.row;
    this->column = nArrayOb.column;
    size_t size = this->row * this->column;
    this->array.resize(size);
    for(size_t i=0 ; i < size ; i++){
        this->array[i] = nArrayOb.array[i];
    }
}

nArray::~nArray(){
//    std::cout << "Destructur" << std::endl;
    array.clear();
}

size_t nArray::get_row(){
    return row;
}

size_t nArray::get_col(){
    return column;
}

void nArray::set(size_t row, size_t column, double value) {
    this->array[row * this->column + column] = value;
}

double nArray::get(size_t row, size_t column) {
    return this->array[row * this->column + column];
}

double & nArray::operator[](size_t index){
    return this->array[index];
}

void nArray::view() {
    std::cout << std::endl; // initial newline to ensure better visual
    if(this->row == 1 && this->column >=1)
    {
        std::cout << "[" ;
        for(int i=0 ; i< column ; i++){
            std::cout << std::setw(WIDTH) << this->array[i] << ",";
        }
        std::cout << "\b]" ;
    }
    else if(this->row >= 1 && this->column ==1)
    {

        std::cout << "[" ;
        for(int i=0 ; i< row ; i++){
            if (i != 0) std::cout << "\n"  << " ";
            std::cout << "[" << std::setw(WIDTH) << this->array[i] ;
            if( i == row-1) {
                std::cout << "]";
                break;
            }
            std::cout <<",],";
        }

        std::cout << "]" ;
    }
    else // when both row and column is greater than 1
    {
        std::cout << "[" ;
        for(int i=0 ; i< row ; i++){
            if (i != 0) std::cout << "\n" << " ";
            std::cout << "[" ;
            for(int j=0; j < column ; j++){
                std::cout << std::setw(WIDTH) << this->array[i * column + j] << ",";
            }
            std::cout << "\b],";
        }

        std::cout << "\b]" ;
    }

}

int *nArray::shape() {
    int *s = new int[2];
    s[0] = int(row);
    s[1] = int(column);
    return s;
}

std::string nArray::shape_str() {
    std::string shp;
    shp.append("(");
    shp.append(std::to_string(row));
    shp.append(",");
    shp.append(std::to_string(column));
    shp.append(")");
    return std::string();
}

nArray nArray::subArray(size_t row_i, size_t row_f, size_t col_i, size_t col_f) {
        // row_i > 0 && row_f <= row_number
        // col_i > 0 && col_f <= col_number
        // row_f > row_i
        // col_f > col_i

        size_t row = row_f - row_i;
        size_t col = col_f - col_i;
        size_t i = 0;
        nArray a(row, col);
        for(size_t r=row_i ; r < row_f ; r++){
            for(size_t c=col_i ; c < col_f ; c++){
                a[i++] = get(r, c);
            }
        }
    return a;
}

