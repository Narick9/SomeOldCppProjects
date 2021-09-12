/*
 * =====================================================================================
 *
 *       Filename:  4.16_function-pointer_demonstrate.cpp
 *
 *    Description: creates three pointers to funcs and demonstrates them
 *
 *        Version:  1.0
 *        Created:  05/31/20 13:11:35
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cmath>
using namespace std;

double hyper_power(double _n, int _degree);
double super_power(double _n, int _degree);
char alphabet_get(int _n);
char alphabet_reverse_get(int _n);


int main()
{
    double d = 2;
    int n = 3;
    
    double (*fd_di)(double, int);   // f_d_i - типа func, возвращающая double
    char (*fc_i)(int);              //     с аргументами double и int
    double (*fd_d)(double);

    fd_di = hyper_power;
        cout << "| " << fd_di(d, n) << " | ";
    fd_di = super_power;
        cout << fd_di(d, n) << " | ";

    fc_i = alphabet_get;
        cout << fc_i(n) << " | ";
    fc_i = alphabet_reverse_get;
        cout << fc_i(n) << " | ";

    fd_d = exp;
        cout << fd_d(d/2) << " | ";
    fd_d = log;
        cout << fd_d(d) << " | ";

    cout << endl;
    return 0;
}


double hyper_power(double _n, int _degree)
{
    double sum = 1;
    for (int i = 1; i <= _degree; i++)
        sum *= (1 + _n);
    return sum;
}

double super_power(double _n, int _degree)
{
    double sum = 1;
    for (int i = 1; i <= _degree; i++)
        sum *= _n/i;
    return sum;
}

char alphabet_get(int _n)
{
    return 'A' + _n;
}

char alphabet_reverse_get(int _n)
{
    return 'Z' - _n;
}
