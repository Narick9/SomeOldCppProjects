/*
 * =====================================================================================
 *
 *       Filename:  1.q7_km-m-to-miles-ft.cpp
 *
 *    Description: convert input km and m to miles and feet 
 *
 *        Version:  1.0
 *        Created:  05/05/20 15:46:15
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
    const int ftInMile = 5280;
    const double kmInMile = 1.609344;

    int _km, _m;
        cout << "Km: ";
        cin >> _km;
        cout << "m:  ";
        cin >> _m;

    double dKm   = _km + (double)_m/1000,
           dMile = dKm / kmInMile;

    cout << "Miles: " << (int)dMile << endl;
    cout << "Feet:  " << (dMile - (int)dMile) * ftInMile << endl;
    return 0; 
}
