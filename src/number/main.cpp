/**

Author : Shahnoor
Email  : shahnoor3pl@gmail.com
Date   : 2017.06.25

**/

#include <iostream>

#include "integer.h"
#include "count.h"

using  namespace std;

void test_narray(){
    cout << "In test_narray() : __LINE__ " << __LINE__ << endl;

    NArray a(9999999);
    a.print();

    NArray b(999999);
    b.print();

    NArray c("9999");
    c.print();
    
    NArray d("9999999999999999999999999999999999999999999999999");
    d.print();
}

void test_integer(){
    cout << "In test_integer() : __LINE__ " << __LINE__ << endl;

    Integer a(9999999);
    a.print();

    Integer b(999999);
    b.print();

    Integer c("9999");
    c.print();
    
    Integer d("10000000099");    // 15 9's
    d.print();
    cout << d << endl;

    cout << "adding " << endl;
    cout << a << "+" << b << " = " << a + b << endl;
    cout << a << "+" << c << " = " << a + c << endl;
    cout << a << "+" << d << " = " << a + d << endl;
    Integer e = c+d;
    cout << c << "+" << d << " = " << e << endl;
    e.print();
    

}

void test_count(){
    cout << "test_count" << endl;
    cout << int_to_str(100) << endl;
    cout << fill(1, 3) << endl;
    cout << fill(10, 3) << endl;
    cout << fill(100, 3) << endl;
    cout << fill(23, 4) << endl;
    cout << fill(966, 6) << endl;
}

int main(){
    cout << "Integer class" << endl;
    
    // test_narray();
    
    test_integer();

    // test_count();

    // cout << "number_of_digit " << a.number_of_digit(9) << endl;
    // cout << "number_of_digit " << a.number_of_digit(99) << endl;
    // cout << "number_of_digit " << a.number_of_digit(9999) << endl;

    return 0;
}