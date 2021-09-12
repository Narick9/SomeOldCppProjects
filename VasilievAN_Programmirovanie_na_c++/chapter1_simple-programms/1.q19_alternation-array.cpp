/*
 * =====================================================================================
 *
 *       Filename:  1.q19_alternation-array.cpp
 *
 *    Description: creates an array and fills it so: even indexes get
 *                 the index as value and odd indexes get square of
 *                 the index as value 
 *
 *        Version:  1.0
 *        Created:  05/06/20 15:48:09
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
        if (i % 2)
            arr[i] = i * i;
        else
            arr[i] = i;
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
