/*
 * =====================================================================================
 *
 *       Filename:  1.q20-input-array.cpp
 *
 *    Description: creates an array and fills it with input by user values 
 *
 *        Version:  1.0
 *        Created:  05/06/20 15:55:22
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

    int arr[n];
    int i = 0;
    while (i < n) {
        cout << i << ": ";
        cin >> arr[i];
        i++;
    }

    i = 0;
    while (i < n) {
        cout << arr[i] << ", ";
        i++;
    }
    cout << endl;
    return 0;
}
