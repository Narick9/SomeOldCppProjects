/*
 * =====================================================================================
 *
 *       Filename:  1.q14_evens-array.cpp
 *
 *    Description: creates an array and fills it with even ingeres 
 *
 *        Version:  1.0
 *        Created:  05/05/20 22:46:18
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

    int evens[n] = {2};
    int i = 1;
    while (i < n) {
        evens[i] = evens[i - 1] + 2;
        i++;
    }

    i = 0;
    while (i < n) {
        cout << evens[i] << ", ";
        i++;
    }
    cout << endl;
    return 0;
}
