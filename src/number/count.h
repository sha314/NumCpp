
#ifndef COUNT_H
#define COUNT_H

#include <iostream>

using namespace std;

/***
*   if chunk = 9    -> number_of_digit(9)       == 1
*   if chunk = 15   -> number_of_digit(15)      == 2
*   if chunk = 909  -> number_of_digit(909)     == 3
*   if chunk = 1592 -> number_of_digit(1592)    == 4
*/
unsigned number_of_digit(unsigned chunk, unsigned divider=10);


    // character to integer decimal.
// if c is not a decimal character return -1
int ctoi(char c);

//integer to character
char itoc(unsigned c);

string int_to_str(unsigned n, unsigned divider=10);

/**
    fill function fills a string with zeros to fit width
    if n=2      and with=3       --return-> 002
    if n=22     and with=3       --return-> 022
    if n=222    and with=3       --return-> 222
    if n=2      and with=9       --return-> 000000002
    if n=23456  and with=6       --return-> 023456
**/
string fill(unsigned n, unsigned width);

#endif /* COUNT_H */

