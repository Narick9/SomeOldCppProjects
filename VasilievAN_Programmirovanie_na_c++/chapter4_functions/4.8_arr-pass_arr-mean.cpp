/*
 * =====================================================================================
 *
 *       Filename:  4.8_arr-pass_arr-mean.cpp
 *
 *    Description: creates two arrays and computes their means with func 
 *
 *        Version:  1.0
 *        Created:  05/29/20 18:01:25
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

double mean(int *_arr, int _size);


int main()
{
    int nums_a[]  = {1, 3, 8, -2, 4};
        for (int &x: nums_a)
            cout << x << ", ";
        cout << endl;
    int nums_b[] = {4, 6, 2};
        for (int &x: nums_b)
            cout << x << ", ";
        cout << endl;

    cout << "First array mean:  " << mean(nums_a, 5) << endl;
    cout << "Second array mean: " << mean(nums_b, 3) << endl;

    return 0;
}


double mean(int *_arr, int _size)
{
    int sum = 0;
    for (int i = 0; i < _size; i++)
        sum += _arr[i];
    return (double)sum / _size;
}
