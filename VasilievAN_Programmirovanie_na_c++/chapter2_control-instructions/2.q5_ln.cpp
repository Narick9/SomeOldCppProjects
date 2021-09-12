/*
 * =====================================================================================
 *
 *       Filename:  2.q5_ln.cpp
 *
 *    Description: gets a value and computes ln for it 
 *
 *        Version:  1.0
 *        Created:  05/10/20 15:34:29
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int accuracy = 10;

    double ln = 0,
           _x;
        cout << "x: ";
        cin >> _x;

    _x -= 1;
    for (int i = 1, k; i <= accuracy; i++) {
        k = pow(-1, i + 1);
        ln += k * pow(_x, i) / i;
    }

    cout << "ln: " << ln << endl;
    return 0;
}
