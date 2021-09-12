/*
 * =====================================================================================
 *
 *       Filename:  2.q7_cos.cpp
 *
 *    Description: gets an angle in radians and outputs its cos
 *
 *        Version:  1.0
 *        Created:  05/10/20 19:41:42
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
    const int accuracy = 100;

    double _angle;
        cout << "Angle (in radians): ";
        cin >> _angle;
    double cos = 1,
           delta = 1;

    int b_inc = 2;
    for (int _ = 1; _ < accuracy; _++) {
        delta *= (-1) * _angle * _angle / ((b_inc - 1) * b_inc);
        b_inc += 2;
        cos += delta;
    }
    
    cout << "cos: " << cos << endl;
    return 0;

}
