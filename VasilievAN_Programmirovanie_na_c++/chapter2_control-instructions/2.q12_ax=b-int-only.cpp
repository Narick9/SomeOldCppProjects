/*
 * =====================================================================================
 *
 *       Filename:  2.q12_ax=b-int-only.cpp
 *
 *    Description: gets A and B and outputs a solution of Ax = B equation
 *                 if it is int otherwise a message that there are not
 *                 solutions
 *
 *        Version:  1.0
 *        Created:  05/10/20 23:03:44
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
    cout << "Solving of Ax = B equation (only integers)" << endl;
    
    int _A, _B;
        cout << "A: ";
        cin >> _A;
        cout << "B: ";
        cin >> _B;
    double ans;

    try {
        if (_A == 0 && _B == 0)   throw "The solution is any number";
        if (_A == 0 && _B != 0)   throw "There are not solutions";
        ans = (double)_B / _A;
        if (ans != (int)ans)      throw "There are not solutions";
        cout << "The solution is " << ans << endl;
    } catch (const char* e) {
        cout << e << endl;
    }
    return 0;
}
