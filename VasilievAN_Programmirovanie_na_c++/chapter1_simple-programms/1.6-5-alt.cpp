/*
 * =====================================================================================
 *
 *       Filename:  6-5-alt.cpp
 *
 *    Description: 5 alternative
 *
 *        Version:  1.0
 *        Created:  05/04/20 18:33:34
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
    int n = 10,
        s = 0;

    while (n) {
        s += n * n;
        n--;
    }

    cout << "Squares sum: " << s << endl;
    return 0;
}
