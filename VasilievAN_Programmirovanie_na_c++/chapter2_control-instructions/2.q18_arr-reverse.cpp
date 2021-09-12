/*
 * =====================================================================================
 *
 *       Filename:  2.q18_arr-reverse.cpp
 *
 *    Description: creates an array and fills it using random and then reverse
 *                 it
 *
 *        Version:  1.0
 *        Created:  05/13/20 22:43:44
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    const int n = 7;
    srand(3);

    int arr[n];
        for (int &x: arr) {
            x = rand() % 10;
            cout << x << ", ";
        }
        cout << endl;

    int last = n - 1,
        i = 0,
        temp;
    while (i < n/2) {
        temp = arr[i];
        arr[i] = arr[last - i];
        arr[last - i] = temp;
        i++;
    }

    for (int &x: arr)
        cout << x << ", ";
    cout << endl;
    return 0;
}
