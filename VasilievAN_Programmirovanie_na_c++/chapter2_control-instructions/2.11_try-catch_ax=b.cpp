/*
 * =====================================================================================
 *
 *       Filename:  12.11_try-catch_ax=b.cpp
 *
 *    Description: gets A and B and outputs the value of x by the equation
 *                 Ax = B 
 *
 *        Version:  1.0
 *        Created:  05/08/20 21:36:55
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

    try {
        if (A != 0)     throw A;
        if (B != 0)     throw "There are not solutions";
        cout << "The solution is any number" << endl;
    } catch (double e) {
        cout << "The solution of the equation is " << B / e << endl;
    } catch (const char *e) {
        cout << e << endl;
    }

    return 0;
}
