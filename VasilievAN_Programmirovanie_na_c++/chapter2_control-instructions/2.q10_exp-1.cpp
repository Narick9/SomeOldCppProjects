/*
 * =====================================================================================
 *
 *       Filename:  2.q10_exp-1.cpp
 *
 *    Description: gets an angle x and computs exp(x) - 1
 *
 *        Version:  1.0
 *        Created:  05/10/20 21:26:42
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
    double sub = 1,
           delta = 1;

    int b_inc = 2;
    for (int _ = 1; _ < accuracy; _++) {
        delta *= _angle / b_inc;
        sub += delta;
        b_inc++;
    }
    
    cout << "(exp(x) - 1)/x: " << sub << endl;
    return 0;
}
