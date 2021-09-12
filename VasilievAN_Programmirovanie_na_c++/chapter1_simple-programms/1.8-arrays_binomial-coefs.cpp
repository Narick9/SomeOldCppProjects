/*
 * =====================================================================================
 *
 *       Filename:  8-arrays_binomial-coefs.cpp
 *
 *    Description: computing binomial coefficients 
 *
 *        Version:  1.0
 *        Created:  05/04/20 18:48:59
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
    const int n = 10;
    int bnm[n + 1];

    bnm[0] = 1;
    int i = 0;
    while (i < n) {
        bnm[i + 1] = bnm[i] * (n - i) / (i + 1);
        i++;
    }

    cout << bnm[0];
    i = 1;
    while (i < n + 1) {
        cout << " " << bnm[i];
        i++;
    }
    cout << endl;
    return 0;
}
