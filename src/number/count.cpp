

#include <iostream>
#include <algorithm>

#include "count.h"
using namespace std;

/***
*   if chunk = 9    -> number_of_digit(9)       == 1
*   if chunk = 15   -> number_of_digit(15)      == 2
*   if chunk = 909  -> number_of_digit(909)     == 3
*   if chunk = 1592 -> number_of_digit(1592)    == 4
*/
unsigned number_of_digit(unsigned chunk, unsigned divider){
    // TODO cannot find number of digits if it is a multiple of 10
    if(chunk == 0) return 1;
    int remainder = chunk % divider;
    // int quotient  = chunk / divider;
    unsigned  count = 0;
    while(chunk || remainder){
        // cout << remainder << endl;
        ++count;
        chunk /= divider;
        remainder = chunk % divider;
    }
    if(count==0){
        cout << "number_of_digit cannot be zero. __LINE__ " << __LINE__ << endl; // #exception
    }
    // cout << "number_of_digit " << count << endl;
    return count;
}


    // character to integer decimal.
// if c is not a decimal character return -1
int ctoi(char c){
    switch(c){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return -1;        
    }
}

//integer to character
char itoc(unsigned c){
    switch(c){
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        default: return '-';        
    }
}

string int_to_str(unsigned n, unsigned divider){
    // unsigned nod = number_of_digit(n);
    string a;
    int remainder= n % divider;
    while(n || remainder){
        a += itoc(remainder);
        // cout << remainder << endl;//////
        n /= divider;
        remainder= n % divider;
    }
    reverse(a.begin(), a.end());
    return a;
}

/**
    fill function fills a string with zeros to fit width
    if n=2      and with=3       --return-> 002
    if n=22     and with=3       --return-> 022
    if n=222    and with=3       --return-> 222
    if n=2      and with=9       --return-> 000000002
    if n=23456  and with=6       --return-> 023456
**/
string fill(unsigned n, unsigned width){
    unsigned nod = number_of_digit(n);
    if(nod > width){
        // #exception
        cout << "error number_of_digit > width file:line = " << __FILE__ << " : " << __LINE__ << endl;
        return "OVER_FLOW";
    }
    string a;
    int l = width - nod;
    for(unsigned i=0 ; i<l ; ++i){
        a += '0';
    }
    a += int_to_str(n);
    return a;
}

