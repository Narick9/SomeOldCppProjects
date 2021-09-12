/*
 * =====================================================================================
 *
 *       Filename:  5-while_squares-sum.cpp
 *
 *    Description: computing squares sum (integers)
 *
 *        Version:  1.0
 *        Created:  05/04/20 18:27:04
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
        s = 0,
        k = 1;
    
    while (k <= n) {
        s += k * k;
        k++;
    }

    cout << "Squares sum from 1 to " << n << ": " << s << endl;
    return 0;
}
