/*
 * =====================================================================================
 *
 *       Filename:  1.q17_2-pwr2.cpp
 *
 *    Description: create an array and fills it with powers of two 
 *
 *        Version:  1.0
 *        Created:  05/05/20 23:03:01
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
    const int n = 10;

    int powers[n] = {1};
    int i = 1;
    while (i < n) {
        powers[i] = powers[i - 1] * 2;
        i++;
    }

    i = 0;
    while (i < n) {
        cout << powers[i] << ", ";
        i++;
    }
    cout << endl;
    return 0;
}
