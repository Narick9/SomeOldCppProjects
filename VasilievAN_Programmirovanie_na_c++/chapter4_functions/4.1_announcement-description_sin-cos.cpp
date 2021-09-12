/*
 * =====================================================================================
 *
 *       Filename:  4.1_announcement-description_sin-cos.cpp
 *
 *    Description: computes sine and cosine and then check result with cmath
 *
 *        Version:  1.0
 *        Created:  05/27/20 22:57:15
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

const int Accuracy = 100;

void show_sin_cos(double);  // объявления наших функции. Имена аргументов
double my_cos(double);      // можно не указывать. Такие мелочи иногда
double my_sin(double);      // забываются. Это называется прототипы


int main()
{
    const double pi = 3.141592;

    show_sin_cos(pi/6);     cout << endl;
    show_sin_cos(pi/4);     cout << endl;
    show_sin_cos(pi/3);     cout << endl;
    show_sin_cos(pi/2);

    return 0;
}


void show_sin_cos(double _x)
{
    cout << "Argument: " << _x << endl;
    cout << "It cosine: " << my_cos(_x) << " vs. " << cos(_x) << endl;
    cout << "It sine: " << my_sin(_x) << " vs. " << sin(_x) << endl;
}

double my_cos(double _x)
{
    double _sum = 0,
           add  = 1;
    for (int i = 0; i < Accuracy; i++) {
        _sum += add;
        add = -1 * add * _x * _x / ((2*i + 1) * (2*i + 2));
    }
    return _sum;
}

double my_sin(double _x)
{
    double _sum = 0,
           add  = _x;
    for (int i = 0; i < Accuracy; i++) {
        _sum += add;
        add = -1 * add * _x * _x / ((2*i + 2) * (2*i + 3));
    }
    return _sum;
}
