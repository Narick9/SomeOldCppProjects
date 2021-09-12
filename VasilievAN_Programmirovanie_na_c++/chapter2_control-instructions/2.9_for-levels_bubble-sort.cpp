/*
 * =====================================================================================
 *
 *       Filename:  2.9_for-levels_bubble-sort.cpp
 *
 *    Description: creates an array with random numbers and sort it using
 *                 bubble sort 
 *
 *        Version:  1.0
 *        Created:  05/07/20 23:00:17
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
    srand(2);
    const int n = 10;

    int lim, i, buff;
    int arr[n];
        cout << "The array before sorting\n";
        for (i = 0; i < n; i++) {
            arr[i] = rand() % 10;
            cout << "| " << arr[i] << " ";
        }
        cout << "|" << endl;
    
    for (lim = n - 1; lim > 0; lim--)
        for (i = 0; i < lim; i++)
            if (arr[i] > arr[i + 1]) {
                buff = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buff;
            }

    cout << "The array after sorting:\n";
    for (i = 0; i < n; i++)
         cout << "| " << arr[i] << " ";
    cout << "|" << endl;
    return 0;
}
