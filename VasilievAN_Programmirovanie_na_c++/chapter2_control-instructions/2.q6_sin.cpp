/*
 * =====================================================================================
 *
 *       Filename:  2.q6_sin.cpp
 *
 *    Description: gets an angle in radians and output its sinus
 *
 *        Version:  1.0
 *        Created:  05/10/20 17:13:22
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
    double sin = _angle,
           delta = _angle;

    int b_inc = 3;
    for (int _ = 1; _ < accuracy; _++) {
        delta *= (-1) * _angle * _angle / ((b_inc - 1) * b_inc);
        b_inc += 2;
        sin += delta;
    }
    
    cout << "sin: " << sin << endl;
    return 0;
}
