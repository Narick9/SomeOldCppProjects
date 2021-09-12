/*
 * =====================================================================================
 *
 *       Filename:  2.4_for-empty_squares-sum.cpp
 *
 *    Description: computing squares sum using empty for 
 *
 *        Version:  1.0
 *        Created:  05/06/20 16:51:55
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
        i = 1, n;
        cout << "Enter the top border of the sum: ";
        cin >> n;

    for (;;) {              // for - пустой второй блок эквивалентен true
        if (i <= n) {
            sum += i * i;
            i++;
        } else {
            break;
        }
    }

    cout << "The squares sum of numbers from 1 to " << n << ": " << sum << endl;
    return 0;
}
