/*
 * =====================================================================================
 *
 *       Filename:  2.q8_sin-hiper.cpp
 *
 *    Description: gets an angle in radians and outputs its sinus hiperbolic
 *
 *        Version:  1.0
 *        Created:  05/10/20 20:24:27
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
    double sh = _angle,
           delta = _angle;

    int b_inc = 3;
    for (int _ = 1; _ < accuracy; _++) {
        delta *= _angle * _angle / ((b_inc - 1) * b_inc);
        b_inc += 2;
        sh += delta;
    }
    
    cout << "sh: " << sh << endl;
    return 0;
}
