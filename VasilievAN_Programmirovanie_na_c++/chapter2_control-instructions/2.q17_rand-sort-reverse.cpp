/*
 * =====================================================================================
 *
 *       Filename:  2.q17_rand-sort-reverse.cpp
 *
 *    Description: creates an array and sort it with reverse order 
 *
 *        Version:  1.0
 *        Created:  05/11/20 18:48:08
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

void quicksort(int* _arr, int _left, int _right)
{
    if (_left >= _right)
        return;
    int pivot = _arr[_left],
        i = _left,
        j = _right,
        temp;
    while (i <= j) {
        while (_arr[i] > pivot)  i++;
        while (_arr[j] < pivot)  j--;
        if (i >= j)
            break;
        temp = _arr[i];
        _arr[i] = _arr[j];
        _arr[j] = temp;
        i++;
        j--;
    }
    quicksort(_arr, _left, j);
    quicksort(_arr, j + 1, _right);
}

int main()
{
    srand(2);
    const int n = 5;

    int arr[n];
        for (int &x: arr) {
            x = rand() % 10;
            cout << x << ", ";
        }
    cout << endl;

    quicksort(arr, 0, n - 1);

    for (int &x: arr)
        cout << x << ", ";
    cout << endl;
    return 0;
}
