/**

Author : Shahnoor
Email  : shahnoor3pl@gmail.com
Date   : 2017.06.25

**/

#include <iostream>
#include <cmath>

#include "integer.h"
#include "count.h"


using namespace std;


NArray::NArray(int a){
    cout << "Constructor -> NArray::NArray(int) __LINE__ " << __LINE__ << endl;
    _sign = (a < 0) ? -1 : 1;
    a *= _sign;  // making sure that a is positive
    if(a > max_chunk){
        int remainder= a % _divider;
        while(remainder){
            // cout << "remainder " << remainder << endl;
            _num.push_back(remainder);
            a /= _divider;
            remainder= a % _divider;
        }
    }
    else _num.push_back(a);
}

NArray::NArray(std::vector<unsigned>& a, int sign){
    this->_sign = (sign < 0) ? -1 : 1;
    _num = a;
}

NArray::NArray(string a){
    cout << "Constructor -> NArray::NArray(string) __LINE__ " << __LINE__ << endl;
    int place = 1;
    int len = a.size();
    unsigned chunk_len = number_of_digit(max_chunk); // chunk length or number of digit in a chunk
    unsigned num_size = ceil((double) a.size() / chunk_len);
    cout << "chunk len " << chunk_len << " __LINE__ : " << __LINE__ << endl;
    cout << "num_size " << num_size << " __LINE__ : " << __LINE__ << endl;
    int k=0;
    _num.resize(num_size);
    int j=1;
    for(int i=len-1 ; i >=0 ; --i, ++j){
        _num[k] += ctoi(a[i]) * place;
        place *= 10;
        if(j % chunk_len==0){
            ++k;
            place = 1;
        }
    }
}

void NArray::print(){
        cout << "_num.size() " << _num.size() << endl;
        for(int i=_num.size()-1 ; i>=0 ; --i){
            cout << "[" << _num[i] << "]";
        }
        cout << endl;
}

ostream& operator<<(ostream& os, const NArray & a){
    // vector<int> n = a.getn();
    // unsigned chunk_len = a.number_of_digit(a.max_chunk);
    unsigned width = a.chunk_width();
    cout << "width " << width << endl;
    os << a._num[a._num.size()-1];
    for(int i= a._num.size()-2 ; i>=0 ; --i){
        os << fill(a._num[i], width);
    }
    return os;
}

Integer::Integer(): NArray(){ }

Integer::Integer(int a): NArray(a){}

Integer::Integer(std::vector<unsigned>& a, int sign): NArray(a, sign){ }

Integer::Integer(string a): NArray(a){ }


Integer operator+(const Integer& a, const Integer& b){
    // size of a and b need not be equal. if out ranged element is accessed 0 is returned
    int len = (a.size() > b.size()) ? a.size() : b.size();
    int sum {};
    std::vector<unsigned> new_num;
    unsigned c=0, remainder=0;
    unsigned divider = a.divider();
    cout << "operator+ : start " << endl;
    for(int i=0; i < len ; ++i){
        cout << a[i] << " + " << b[i] << " + " << c << " = ";
        sum = a[i] + b[i] + c;
        remainder = sum % divider;
        cout << remainder << endl;
        c = sum / divider;
        new_num.push_back(remainder);
        // process sum and assign it to b
    }
    if(c){
        cout << "remainder " << c << endl;
        new_num.push_back(c);
    }
    cout << endl << "operator+ : end" << endl;
    return Integer(new_num);
}
