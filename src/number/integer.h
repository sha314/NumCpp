/**

Author : Shahnoor
Email  : shahnoor3pl@gmail.com
Date   : 2017.06.25

**/

#ifndef INTEGER_H
#define INTEGER_H

#include <string>
#include <vector>
#include "count.h"

using namespace std;

class NArray{
    //  basic parameter
    /**
    * possible value max chunk 
    * 9 or 99 or 999 or 9999 or 99999 or 999999 or 9999999 or 99999999 or 999999999
    * it depends on programmer's choice and side of int in the system
    */
    unsigned max_chunk = 999;
    unsigned _divider   = max_chunk + 1;

    //  number storage
    vector<unsigned> _num;                       // holds the number
    int _sign = 1;

public:
    NArray(): _num{0} {}               // default constructor
    NArray(int a);
    NArray(std::vector<unsigned>& a, int sign=1);
    NArray(string a);

    void print();

    unsigned operator[](unsigned index) const {return index < _num.size() ? _num[index] : 0;}
    unsigned& operator[](unsigned index) {return _num[index];}

    size_t size() const {return _num.size();}
    size_t chunk_width() const {return number_of_digit(max_chunk);}
    void push_back(unsigned a) {_num.push_back(a);}

    unsigned divider() const {return _divider;}

    friend ostream& operator<<(ostream& os, const NArray & a);
};


/*******************************************
Integer class

Author : Shahnoor
Email  : shahnoor3pl@gmail.com

uses an array of integer to represent large number
make good use of every bit available in an int
also the fundamental mathematical operation,
i.e., +, -, *, /, %, +=, -=, *=, /=, %= ,
are also defined


********************************************/

class Integer : public NArray{
private:
    Integer add(const Integer & b) const;
    Integer subtract(const Integer & b) const;
    Integer multiply(const Integer & b) const;
    Integer divide(const Integer & b) const;
    Integer modulus(const Integer & b) const;
public:
    Integer();
    Integer(int a);
    Integer(std::vector<unsigned>& a, int sign=1);
    Integer(string a);

};

Integer operator+(const Integer& a, const Integer& b);

#endif /* INTEGER_H */