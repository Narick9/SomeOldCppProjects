/*
 * =====================================================================================
 *
 *       Filename:  3.q2_array-squares-sum.cpp
 *
 *    Description: create an array and computes squares sum of its elements 
 *
 *        Version:  1.0
 *        Created:  05/19/20 15:36:37
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
    srand(6);
    const int size = 5;
    
    int nums[size];
        for (int &x: nums) {
            x = rand() % 10;
            cout << x << ", ";
        }
        cout << endl;
    int sum = 0;

    for (int &x: nums)
        sum += x * x;

    cout << "The squares sum is " << sum << endl;
    return 0;
}
