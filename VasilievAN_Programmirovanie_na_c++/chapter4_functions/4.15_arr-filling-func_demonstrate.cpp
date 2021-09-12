/*
 * =====================================================================================
 *
 *       Filename:  4.15_arr-filling-func_demonstrate.cpp
 *
 *    Description:  creates a dynamic array and fills it with two funcs
 *
 *        Version:  1.0
 *        Created:  05/31/20 12:21:55
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

void fibs_fill(int* _arr, int _size);
void rands_fill(int* _arr, int _size);


int main()
{
    srand(3);
    const int size = 15;

    int arr[size];

    fibs_fill(arr, size);
        for (int i = 0; i < size; i++)
            cout << arr[i] << ", ";
        cout << endl;
    
    rands_fill(arr, size);
        for (int i = 0; i < size; i++)
            cout << arr[i] << ", ";
        cout << endl;

    return 0;
}


void fibs_fill(int* _arr, int _size)
{
    if (_size > 0)
        _arr[0] = 1;
    if (_size > 1)
        _arr[1] = 1;
    for (int i = 2; i < _size; i++)
        _arr[i] = _arr[i - 2] + _arr[i - 1];
}

void rands_fill(int* _arr, int _size)
{
    for (int i = 0; i < _size; i++)
        _arr[i] = rand() % 10;
}
