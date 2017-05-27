
#ifndef NUMCPP_ODE_H
#define NUMCPP_ODE_H

#include <cstdlib> // for size_t
#include <fstream> //for std::ofstream


/*
    d/dt(d/dt x) = -x

    here
    x[0] -> x
    x[1] -> v
    dx[0] -> dx/dt
    dx[1] -> dv/dt

*/
/*******************************************************
*   t       -> independent variable
*   x[]     -> array of dependent variable
*   dx[]    -> array of corresponding dependent variable
********************************************************/
void dnx(double dx[], double x[], double t);

/************************************************************
*   Runge-Kutta method of 4-th order for solving
*   Coupled Differential Equation.
*   This is the generalized method but it requires a function
*   with parameter as
*   void dnx(double dx[], double x[], double t)
*   Where
*   t       -> independent variable
*   x[]     -> array of dependent variable
*   dx[]    -> array of corresponding dependent variable
*************************************************************/
void rk4(
    void dnx(double dx[], double x[], double t),
    double xi[], size_t xi_len, double t, double dt
    );

void rk4(
    void dnx(double dx[], double x[], double t),
    double xi[], size_t xi_len, double t_i, double t_f, double dt,
    std::ofstream &fout
    );

#endif