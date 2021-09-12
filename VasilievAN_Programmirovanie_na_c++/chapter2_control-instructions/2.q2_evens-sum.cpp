/*
 * =====================================================================================
 *
 *       Filename:  2.q2_evens-sum.cpp
 *
 *    Description: computing evens sum using do-while operator
 *
 *        Version:  1.0
 *        Created:  05/09/20 16:37:20
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
    const int n = 3;

    int sum = 0,
        i = 0;
    do {
        sum += i * 2;
        i++;
    } while (i <= n);

    cout << "The sum of " << n << " evens: " << sum << endl;
    return 0;
}
