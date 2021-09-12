/*
 * =====================================================================================
 *
 *       Filename:  1.q6_km-to-mile.cpp
 *
 *    Description: convert km to miles
 *
 *        Version:  1.0
 *        Created:  05/05/20 15:37:14
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
    const double kmInMile = 1.609344;
    int km;
        cout << "Km: ";
        cin >> km;

    cout << "Miles: " << km / kmInMile << endl;
    return 0;
}
