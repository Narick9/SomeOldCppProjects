/*
 * =====================================================================================
 *
 *       Filename:  2.1_for_squares-sum.cpp
 *
 *    Description: output squares sum with cycle for 
 *
 *        Version:  1.0
 *        Created:  05/06/20 16:15:25
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
        n;
        cout << "Enter the top border of the sum: ";
        cin >> n;

    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }

    cout << "The squares sum of numbers from 1 to " << n << ": " << sum << endl;
}
