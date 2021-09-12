/*
 * =====================================================================================
 *
 *       Filename:  4.14_dynamic-arr-as-func-result_demonstrate.cpp
 *
 *    Description: creates two dynamic arrays with functions 
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

int* fibs_create(int _size);
int* rands_create(int _size);


int main()
{
    srand(3);

    int fibs_size  = 10,
        rands_size = 15;
    int *arr;

    arr = fibs_create(fibs_size);
        for (int i = 0; i < fibs_size; i++)
            cout << arr[i] << ", ";
        cout << endl;
        delete [] arr;
    
    arr = rands_create(rands_size);
        for (int i = 0; i < rands_size; i++)
            cout << arr[i] << ", ";
        cout << endl;
        delete [] arr;

    return 0;
}


int* fibs_create(int _size)
{
    int *fibs = new int[_size];
    if (_size > 0)
        fibs[0] = 1;
    if (_size > 1)
        fibs[1] = 1;
    for (int i = 2; i < _size; i++)
        fibs[i] = fibs[i - 2] + fibs[i - 1];
    return fibs;
}

int* rands_create(int _size)
{
    int *rands = new int[_size];
    for (int i = 0; i < _size; i++)
        rands[i] = rand() % 10;
    return rands;
}
