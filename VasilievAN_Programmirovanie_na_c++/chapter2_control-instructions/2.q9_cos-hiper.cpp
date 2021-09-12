/*
 * =====================================================================================
 *
 *       Filename:  2.q9_cos-hiper.cpp
 *
 *    Description: gets an angle in radians and outputs its cosinus hiperbolic
 *
 *        Version:  1.0
 *        Created:  05/10/20 20:34:30
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

int main()
{
    int accuracy = 100;

    double _angle;
        cout << "Angle (in radians): ";
        cin >> _angle;
    double ch = 1,
           delta = 1;

    int b_inc = 2;
    for (int _ = 1; _ < accuracy; _++) {
        delta *= _angle * _angle / ((b_inc - 1) * b_inc);
        ch += delta;
        b_inc += 2;
    }
    
    cout << "ch: " << ch << endl;
    return 0;
}
