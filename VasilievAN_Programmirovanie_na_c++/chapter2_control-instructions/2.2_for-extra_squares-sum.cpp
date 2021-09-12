/*
 * =====================================================================================
 *
 *       Filename:  2.2_for-extra_squares-sum.cpp
 *
 *    Description: computing squares sum without code block in cycle 
 *
 *        Version:  1.0
 *        Created:  05/06/20 16:32:43
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
    int sum, n,
        i = 0;
        cout << "Enter the top border of the sum: ";
        cin >> n;

    for (i = 1, sum = 0; i <= n; sum += i * i, i++);

    cout << "The squares sum of numbers from 1 to " << n << ": " << sum << endl;
    return 0;
}
