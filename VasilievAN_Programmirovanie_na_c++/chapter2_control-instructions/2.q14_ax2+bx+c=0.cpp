/*
 * =====================================================================================
 *
 *       Filename:  2.q14_ax2+bx+c=0.cpp
 *
 *    Description: computs ax^2 + bx + c = 0 equation using different methods 
 *
 *        Version:  1.0
 *        Created:  05/11/20 12:49:21
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

void error(const char *_msg, int _err)
{
    cout << "ERROR " << _err << "   " << _msg << endl;
    exit(_err);
}

int main()
{
    cout << "Solving of Ax^2 + Bx + C = 0" << endl;

    cout << endl;
    int _method;
    cout <<
"What method to use? \n\
 1 - classic method  \n\
 2 - use k-method    \n\
choice: ";
    cin >> _method;
        if (!(1 <= _method && _method <= 2))   error("Invalid choice", 1);

    cout << endl;
    double _A, _B, _C;
        cout << "A: ";
        cin >> _A;
        cout << "B: ";
        cin >> _B;
        cout << "C: ";
        cin >> _C;

    double D, k;
    switch (_method) {
        case 1:
            D = _B*_B - 4*_A*_C;
            break;
        case 2:
            k = _B / 2;
            D = k*k - _A*_C;
            break;
    }
    if (D < 0)   error("There are not solutions", 2);

    double x1, x2;
    switch (_method) {
        case 1:
            x1 = ((-1)*_B - sqrt(D)) / (2*_A);
            x2 = ((-1)*_B + sqrt(D)) / (2*_A);
            break;
        case 2:
            x1 = ((-1)*k - sqrt(D)) / _A;
            x2 = ((-1)*k + sqrt(D)) / _A;
            break;
    }
    
    cout << endl;
    cout << "D:  " << D << endl;
    cout << "x1: " << x1 << endl;
    cout << "x2: " << x2 << endl;
    return 0;
}
