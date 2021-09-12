/*
 * =====================================================================================
 *
 *       Filename:  2.q4_greatest-common-factor.cpp
 *
 *    Description: gets two numbers and outputs their greatest common factor 
 *
 *        Version:  1.0
 *        Created:  05/09/20 17:14:24
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

int coef(double _fraction)
{
    int i = 1;
    while (i * _fraction != (int)(i * _fraction))   i++;
    return i;
}

int main()
{
    int _fst, _snd;
        cout << "First number: ";
        cin >> _fst;
        cout << "Second number: ";
        cin >> _snd;

    double frac = (double)_fst / _snd;
    int id = coef(frac);
    cout << "The greatest common fatcor: " << _snd / id << endl;
    return 0;
}
