
#include <iostream>

#include "ode.h"
#include "../flags.h"


/*
    d/dt(d/dt x) = -x

    here
    x[0] -> x
    x[1] -> v
    dx[0] -> dx/dt
    dx[1] -> dv/dt

*/
void dnx(double dx[], double x[], double t){
    dx[0] = x[1];
    dx[1] = -x[0];
}


void rk4(
    void dnx(double dx[], double x[], double t),
    double xi[], size_t xi_len, double t, double dt
    )
{
    double k[xi_len][4];
    double dx[xi_len], x[xi_len], x_dummy[xi_len];
    //copying to new variable
    for(size_t i=0; i<xi_len; i++){
        x[i] = xi[i];
    }

    //updating the value of
    dnx(dx, x, t);
    for(size_t i=0 ; i < xi_len ; i++){
        k[i][0] = dx[i]*dt;
        x[i] = xi[i] + k[i][0]/2;
    }

    dnx(dx, x, t + dt/2);
    for(size_t i=0 ; i < xi_len ; i++){
        k[i][1] = dx[i]*dt;
        x[i] = xi[i] +  k[i][1]/2;
    }

    dnx(dx, x, t + dt/2);
    for(size_t i=0 ; i < xi_len ; i++){
        k[i][2] = dx[i]*dt;
        x[i] = xi[i] +  k[i][2];
    }

    dnx(dx, x, t + dt);
    for(size_t i=0 ; i < xi_len ; i++){
        k[i][3] = dx[i]*dt;
    }

    for(size_t i=0; i<xi_len; i++){
        xi[i] += k[i][0]/6 + k[i][1]/3 + k[i][2]/3 + k[i][3]/6;
    }
    
}

void rk4(
    void dnx(double dx[], double x[], double t),
    double xi[], size_t xi_len, double t_i, double t_f, double dt,
    std::ofstream &fout
    )
{
    double k[xi_len][4];
    double dx[xi_len], x[xi_len], x_dummy[xi_len];
    //copying to new variable
    for(size_t i=0; i<xi_len; i++){
        x[i] = xi[i];
    }
    
    for(double t=t_i ; t <= t_f ; t += dt ){
        if(debugging){
            std::cout << "ti, tf, dt , t-> " << t_i <<","<< t_f << "," << dt << "," << t << std::endl;
        }

        //write to file
        fout << t << "\t";
        for(size_t j=0; j<2 ; j++){
            fout << x[j] << "\t" ;
        }
        fout << std::endl;

        // update x[]
        rk4(dnx, x, xi_len, t, dt);
    }
}