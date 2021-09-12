/*
 * =====================================================================================
 *
 *       Filename:  3.q17_biggests-array-from-two.cpp
 *
 *    Description: creates two arrays and fills them with random. Then creates
 *                 thirth array with biggest nums from first and second by each
 *                 id 
 *
 *        Version:  1.0
 *        Created:  05/25/20 17:57:49
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

void arr_show(int *_arr, int _size)
{
    for (int i = 0; i < _size; i++)
        cout << _arr[i] << ", ";
    cout << endl;
}

int main()
{
    const int size = 8;
    srand(6);

    int nums_a[size],
        nums_b[size];
        for (int i = 0; i < size; i++) {
            nums_a[i] = rand() % 10;
            nums_b[i] = rand() % 10;
        }
        arr_show(nums_a, size);
        arr_show(nums_b, size);
    int _nums_biggest[size];
    
    for (int i = 0; i < size; i++)
        _nums_biggest[i] = nums_a[i] > nums_b[i] ? nums_a[i] : nums_b[i];

    cout << "The array of biggest:" << endl;
    arr_show(_nums_biggest, size);
    return 0;
}
