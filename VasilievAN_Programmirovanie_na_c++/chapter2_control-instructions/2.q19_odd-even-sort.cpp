/*
 * =====================================================================================
 *
 *       Filename:  2.q19_odd-even-sort.cpp
 *
 *    Description: creates an array and fills it with random. Then divides it
 *                 into evens and odds and sort them. The result ouptuts 
 *
 *        Version:  1.0
 *        Created:  05/15/20 17:14:17
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

void bubbleSort(int *_arr, int _n)
{
    int temp;
    for (int m = 1; m < _n; m++)
        for (int i = 0; i < _n - m; i++)
            if (_arr[i] > _arr[i + 1]) {
                temp = _arr[i];
                _arr[i] = _arr[i + 1];
                _arr[i + 1] = temp;
            }
}

int main()
{
    const int n = 10;
    srand(6);

    int arr[n];
        for (int &x: arr) {
            x = rand() % 10;
            cout << x << ", ";
        }
        cout << endl;

    int i = 0,
        forodd = 0,
        temp;
    while (i < n) {
        if (arr[i] % 2) {
            temp = arr[forodd];
            arr[forodd] = arr[i];
            arr[i] = temp;
            forodd++;
        }
        i++;
    }
    bubbleSort(arr, forodd);
    bubbleSort(arr + forodd, n - forodd);

    for (int &x: arr)
        cout << x << ", ";
    cout << endl;
    return 0;
}
