/*
 * =====================================================================================
 *
 *       Filename:  1.q13_odds-sum.cpp
 *
 *    Description: output sum of odd integers 
 *
 *        Version:  1.0
 *        Created:  05/05/20 17:56:53
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

int sum_evens(int n)
{
    static int sum = 0;
    if (n > 0) {
        sum += 2;
        int _ = sum;
        return _ + sum_evens(n - 1);
    } 
    return 0;
}

int main()
{
    int n;
        cout << "How many odd integers will be summed? ";
        cin >> n;
        if (n < 0) {
            cout << "ERROR:\tincorrect input" << endl;
            return 1;
        }

    cout << "sum: " << sum_evens(n) - n << endl;    // n * n
    return 0;
}
