/*
 * =====================================================================================
 *
 *       Filename:  1.4_2-with-funcs.cpp
 *
 *    Description: convert miles to km with funcs 
 *
 *        Version:  1.0
 *        Created:  05/04/20 22:32:11
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

double getDistMile()
{
    double dist;
    cout << "Set distation in miles: ";
        cin >> dist;
    return dist;
}

double getDistKm(double dist)
{
    double kmInMile = 1.609344;
    return dist * kmInMile;
}

int main()
{
    double distMile = getDistMile();

    cout << "Distation in km: " << getDistKm(distMile) << endl;
    return 0;
}
