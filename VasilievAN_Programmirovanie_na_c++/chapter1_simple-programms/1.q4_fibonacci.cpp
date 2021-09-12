/*
 * =====================================================================================
 *
 *       Filename:  1.q4_fibonacci.cpp
 *
 *    Description: displays as long fibonacci numbers as entered 
 *
 *        Version:  1.0
 *        Created:  05/05/20 14:51:46
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
    int n = 0;
        cout << "How many fibonacci numbers do you want to see? ";
        cin >> n;

    cout << 1;
    int last  = 1,
        sLast = 0,
        cur;
    while (0 < n) {
        cur = last + sLast;
        cout << ", " << cur;
        sLast = last;
        last = cur;
        n--;
    }
    cout << endl;

    return 0;
}
