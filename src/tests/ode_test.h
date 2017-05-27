
#include <iostream>
#include <fstream>

#include "../ode/ode.h"

using namespace std;


void ode_test_1(){
 cout << "########### ode test_1 ###########" << endl;
    ofstream fout("test1.txt");
    double x[2]={0, 1};
    fout << "<t>\t<x>\t<v>" << endl;
    for(double t=0 ; t <= 10000 ; t += 0.1 ){

        //write to file
        fout << t << "\t";
        for(size_t j=0; j<2 ; j++){
            fout << x[j] << "\t" ;
        }
        fout << std::endl;
        rk4(dnx, x, 2, t, 0.01);
    }
    fout.close();
}

void ode_test_2(){
    cout << "########### ode test_2 ###########" << endl;
    ofstream fout("test2.txt");
    double t=0;
    double x[2]={0, 1};
    fout << "<t>\t<x>\t<v>" << endl;
    rk4(dnx, x, 2, t, 1000, 0.01, fout);
 
    fout.close();
}