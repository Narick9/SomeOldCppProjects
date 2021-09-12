/*
 * =====================================================================================
 *
 *       Filename:  1.q5_binomial-coefs.cpp
 *
 *    Description: displays binomial coefs without using arrays 
 *
 *        Version:  1.0
 *        Created:  05/05/20 15:09:30
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
        cout << "How many binomial numbers do you want to display? ";
        cin >> n;

    
    cout << 1;
    int lastBnm = 1,
        i       = 0,
        cur;
    while (i < n) {
        cur = lastBnm * (n - i) / (i + 1);
        cout << ", " << cur;
        lastBnm = cur;
        i++;
    }
    cout << endl;

    return 0;
}
