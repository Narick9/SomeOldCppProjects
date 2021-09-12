/*
 * =====================================================================================
 *
 *       Filename:  1.q15_odd-array.cpp
 *
 *    Description: creates an array and fills it with odd integers 
 *
 *        Version:  1.0
 *        Created:  05/05/20 22:50:42
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

    int odds[n] = {1};
    int i = 1;
    while (i < n) {
        odds[i] = odds[i - 1] + 2;
        i++;
    }

    i = 0;
    while (i < n) {
        cout << odds[i] << ", ";
        i++;
    }
    cout << endl;
    return 0;
}
