/*
 * =====================================================================================
 *
 *       Filename:  2.q11_ax=b.cpp
 *
 *    Description: gets A and B and computes equation Ax = B using if-levels
 *
 *        Version:  1.0
 *        Created:  05/10/20 22:49:20
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
    cout << "Solving of the Ax = B equation" << endl;

    double A, B;
        cout << "A: ";
        cin >> A;
        cout << "B: ";
        cin >> B;

    if (A == 0) {
        if (B == 0)
            cout << "The solution is any number" << endl;
        else
            cout << "There are not solutions" << endl;
    } else {
        cout << "The solution is " << B / A << endl;
    }
    return 0;
}
