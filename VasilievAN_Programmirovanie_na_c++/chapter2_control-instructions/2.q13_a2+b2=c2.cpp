/*
 * =====================================================================================
 *
 *       Filename:  2.q13_a2+b2=c2.cpp
 *
 *    Description: computs first 100 a, b and c for which a^2 + b^2 = c^2 
 *
 *        Version:  1.0
 *        Created:  05/11/20 12:19:21
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
    double c;
    for (int a = 1; a <= 100; a++)
        for (int b = 1; b <= 100; b++) {
            c = sqrt(a*a + b*b);
            if (c == (int)c)
                cout << a << ", " << b << " and " << c << endl;
        }

    return 0;
}
