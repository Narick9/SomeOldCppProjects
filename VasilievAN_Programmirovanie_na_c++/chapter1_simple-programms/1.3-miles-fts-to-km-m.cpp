/*
 * =====================================================================================
 *
 *       Filename:  1.3-miles-fts-to-km-m.cpp
 *
 *    Description: convert miles and foonts to km and m 
 *
 *        Version:  1.0
 *        Created:  05/04/20 22:14:54
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
    const int ftInMile = 5280;
    const double kmInMile = 1.609344;
    int dMile, dFt, dKm, dM;
    
    cout << "Distation in miles and foonts." << endl;
    cout << "Miles: ";
        cin >> dMile;
    cout << "Foots: ";
        cin >> dFt;

    double distMile = dMile + (double)dFt/ftInMile,
           distKm   = distMile * kmInMile;
    dKm = (int)distKm;
    dM  = (int)((distKm - dKm) * 1000);

    cout << "Distation in km and m" << endl;
    cout << "Km: " << dKm << endl;
    cout << "M: " << dM << endl;

    return 0;
}
