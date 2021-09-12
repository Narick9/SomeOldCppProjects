/*
 * =====================================================================================
 *
 *       Filename:  2.q1_odds-sum.cpp
 *
 *    Description: computing odds sum using for cycle 
 *
 *        Version:  1.0
 *        Created:  05/09/20 16:28:50
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
    const int n = 4;

    int sum = 0;
    for (int i = 1; i < n * 2; i += 2) {
        sum += i;
    }

    cout << "The sum of " << n << " odds: " << sum << endl;
    return 0;
}
