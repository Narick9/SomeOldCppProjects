/*
 * =====================================================================================
 *
 *       Filename:  1.q10_kmph-to-mps.cpp
 *
 *    Description: converts km/h to m/s 
 *
 *        Version:  1.0
 *        Created:  05/05/20 16:44:26
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
    const int mInKm  = 1000,
              sInMin = 60,
              minInH = 60;

    double _kmps;
        cout << "Km/s: ";
        cin >> _kmps;

    cout << "m/s: " << (double)(_kmps * mInKm)/(minInH * sInMin) << endl;
    return 0;
}
