/*
 * =====================================================================================
 *
 *       Filename:  1.q8_fathoms-to-m.cpp
 *
 *    Description: convert input fathoms to m 
 *
 *        Version:  1.0
 *        Created:  05/05/20 16:17:19
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
    const double mInFathoms = 2.16;

    int fathoms;
        cout << "Fathoms: ";
        cin >> fathoms;

    cout << "m: " << fathoms * mInFathoms << endl;
    return 0;
}
