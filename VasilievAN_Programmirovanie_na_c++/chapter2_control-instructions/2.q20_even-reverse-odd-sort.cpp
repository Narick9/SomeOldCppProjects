/*
 * =====================================================================================
 *
 *       Filename:  2.q20_even-reverse-odd-sort.cpp
 *
 *    Description: creates an array and fills it with random. Then, divide it
 *                 into even and odd numbers and sorts evens descending, and
 *                 odds ascending 
 *
 *        Version:  1.0
 *        Created:  05/15/20 19:16:01
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

void selectSort(int *_arr, int _n, bool _reverse=false)
{
    int targetid,
        temp;
    for (int cur = 0; cur < _n; cur++) {
        targetid = cur;
        for (int i = cur + 1; i < _n; i++) {
            if (_reverse && _arr[i] > _arr[targetid] ||
                !_reverse && _arr[i] < _arr[targetid])
                targetid = i;
        }
        temp = _arr[cur];
        _arr[cur] = _arr[targetid];
        _arr[targetid] = temp;
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
    foreven = 0,
    temp;
    while (i < n) {
        if (arr[i] % 2 == 0) {
            temp = arr[foreven];
            arr[foreven] = arr[i];
            arr[i] = temp;
            foreven++;
        }
        i++;
    }

    selectSort(arr, foreven, true);
    selectSort(arr + foreven, n - foreven);

    for (int &x: arr)
        cout << x << ", ";
    cout << endl;
    return 0;
}
