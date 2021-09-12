/*
 * =====================================================================================
 *
 *       Filename:  2-miles-to-km.cpp
 *
 *    Description: convert miles to km
 *
 *        Version:  1.0
 *        Created:  05/04/20 17:43:09
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

int main()
{
    const double kmInMile = 1.609344;
    double distMile,
           distKm;
        cout << "Укажите расстояние в милях: ";
        cin >> distMile;

    distKm = distMile * kmInMile;

    cout << "Расстояние (в км): " << distKm << endl;
    return 0;
}
