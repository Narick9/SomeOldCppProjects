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
#include <cstdlib>
using namespace std;

int coef(double _fraction)
{
    int i = 1;
    while (i * _fraction != (int)(i * _fraction))   i++;
    return i;
}

int main()
{
    system("chcp 65001 > nul");
    cout << "               Muslimov Arthur, 9 May 2020" << endl << endl;

    int _fst, _snd, id;
    double frac;
    while (true) {
        cout << "First number: ";
            cin >> _fst;
        cout << "Second number: ";
            cin >> _snd;

        frac = abs((double)_fst / _snd);
        id = coef(frac);

        cout << "The greatest common fatcor: " << _snd / id << endl << endl;
    }

    return 0;
}
