/*
 * =====================================================================================
 *
 *       Filename:  4.17_func-pass_integral.cpp
 *
 *    Description: computes integral with func which takes function-pointer as
 *                 parameter 
 *
 *        Version:  1.0
 *        Created:  05/31/20 14:51:40
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

double integrate(double (*F)(double), double a, double b);
double func(double x);
double inverse(double x);

const int accuracy = 1000;


int main()
{
    cout << integrate(func, 0, 1) << endl;
    cout << integrate(inverse, 1, 2) << endl;
    return 0;
}


double integrate(double (*F)(double), double a, double b)
{                                           // integrate - а ведь
    double dx = (b - a)/accuracy;           //   раньше программисты знали
    double sum = (F(a) + F(b))*dx/2;        //   математику... Ну так говорят
    for (int i = 1; i <= accuracy - 1; i++) //   люди постарше
        sum += F(a + dx*i)*dx;
    return sum;
}

double func(double x)       // x - да, я решил отказаться от подчёркивания
{                           //   перед именами принимаемых переменных. Может
    return x*(1 - x);       //   это и пригодится в функциях посложнее, но тут
}                           //   это больше вредит
                            // func - я не знаю как это ещё назвать
double inverse(double x)
{
    return 1/x;
}
