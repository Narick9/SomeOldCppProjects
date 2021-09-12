/*
 * =====================================================================================
 *
 *       Filename:  1.q16_squares-array.cpp
 *
 *    Description: creates an array and fills it with squares 
 *
 *        Version:  1.0
 *        Created:  05/05/20 22:56:58
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

    int squares[n];
    int i = 1;
    while (i <= n) {
        squares[i - 1] = i * i;
        i++;
    }
    
    i = 0;
    while (i < n) {
        cout << squares[i] << ", ";
        i++;
    }
    cout << endl;
    return 0;
}
