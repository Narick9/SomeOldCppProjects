/*
 * =====================================================================================
 *
 *       Filename:  2.3_for-extra_squares-sum.cpp
 *
 *    Description: computing sum squares with for that have only conditional
 *
 *        Version:  1.0
 *        Created:  05/06/20 16:42:38
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
    int sum = 0,
        i = 0, n;
        cout << "Enter the top border of the sum: ";
        cin >> n;

    for (; i <= n;) {
        sum += i * i;
        i++;
    }

    cout << "The squares sum of numbers from 1 to " << n << ": " << sum << endl;
    return 0;
}
