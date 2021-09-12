/*
 * =====================================================================================
 *
 *       Filename:  4.q12_func-sort-reverse.cpp
 *
 *    Description: sortes descending an array with func 
 *
 *        Version:  1.0
 *        Created:  06/03/20 18:32:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

const int size = 6;

int& sort_reverse(int arr[size]);


int main()
{
    int nums[size] = { 1, 5, 3, 8, 2, 9 };
        for (int &x: nums)
            cout << x << ", ";
        cout << endl;

    cout << "The smallest item of this array is " << sort_reverse(nums) << endl;
    cout << "Sorted descending arr:" << endl;
        for (int &x: nums)
            cout << x << ", ";
        cout << endl;

    return 0;
}


int& sort_reverse(int arr[size])
{
    static int done = 0;        // static - раз уж здесь нужна практически та
    if (done == size - 1) {     //   же программа, то здесь я реализовал, то,
        done = 0;               //   от чего отказался в прошлой
        return arr[size - 1];
    }

    int temp;
    for (int i = 1; i < size - done; i++)
        if (arr[i - 1] < arr[i]) {
            temp = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = temp;
        }
    done++;
    return sort_reverse(arr);
}
