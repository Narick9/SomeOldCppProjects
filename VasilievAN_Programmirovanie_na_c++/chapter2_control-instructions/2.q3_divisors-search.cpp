/*
 * =====================================================================================
 *
 *       Filename:  2.q3_divisors-search.cpp
 *
 *    Description: gets a number and output all numbers by which it is
 *                 divisible without remainder 
 *
 *        Version:  1.0
 *        Created:  05/09/20 16:54:22
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
    int _inp;
        cout << "Give a number: ";
        cin >> _inp;

    for (int i = _inp; i > 0; i--) {
        cout << (double)_inp / i << ", ";
    }
    cout << endl;
    return 0;
}
