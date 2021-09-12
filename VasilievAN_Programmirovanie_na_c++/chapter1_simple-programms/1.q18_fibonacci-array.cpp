/*
 * =====================================================================================
 *
 *       Filename:  1.q18_fibonacci-array.cpp
 *
 *    Description: create an array and fills it with fibonacci numbers 
 *
 *        Version:  1.0
 *        Created:  05/05/20 23:08:47
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

    int fib[n] = {1, 1};
    int i = 2;
    while (i < n) {
        fib[i] = fib[i - 1] + fib[i - 2];
        i++;
    }

    i = 0;
    while (i < n) {
        cout << fib[i] << ", ";
        i++;
    }
    cout << endl;
    return 0;
}
