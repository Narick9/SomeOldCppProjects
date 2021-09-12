/*
 * =====================================================================================
 *
 *       Filename:  1.q9_fathoms-arsh-to-m-cm.cpp
 *
 *    Description: convert input fathoms and arshins to m and cm 
 *
 *        Version:  1.0
 *        Created:  05/05/20 16:33:55
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
    const double mInFathom = 2.16;
    const int arshInFathom = 3;

    int _fathoms, _arshs;
        cout << "Fathoms: ";
        cin >> _fathoms;
        cout << "Arshins: ";
        cin >> _arshs;

    double distFathoms = _fathoms + (double)_arshs/arshInFathom,
           distM       = distFathoms * mInFathom;

    cout << "m: " << (int)distM << endl;
    cout << "cm: " << (distM - (int)distM)*100 << endl;
    return 0;
}
