/*
 * =====================================================================================
 *
 *       Filename:  1.q11_mps-to-kmph.cpp
 *
 *    Description: convert input m/s to km/h using funcs
 *
 *        Version:  1.0
 *        Created:  05/05/20 16:58:36
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

double kmpsFromMps(double _mps)
{
    return _mps * 3.6;
}

int main()
{
    double _mps;
        cout << "M/s: ";
        cin >> _mps;

    cout << kmpsFromMps(_mps) << endl;
    return 0;
}
