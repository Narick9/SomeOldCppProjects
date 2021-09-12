/*
 * =====================================================================================
 *
 *       Filename:  3.q7_array-min-max.cpp
 *
 *    Description: creates an array and output its min and min id 
 *
 *        Version:  1.0
 *        Created:  05/19/20 21:39:13
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
    srand(9);
    const int size = 6;

    int nums[size];
        for (int &x: nums) {
            x = rand() % 10;
            cout << x << ", ";
        }
        cout << endl;
    int min_id = 0;

    for (int i = 1; i < size; i++)
        if (nums[i] < nums[min_id])
            min_id = i;

    printf("Array min is %i with id %i\n", nums[min_id], min_id);
    return 0;
}
