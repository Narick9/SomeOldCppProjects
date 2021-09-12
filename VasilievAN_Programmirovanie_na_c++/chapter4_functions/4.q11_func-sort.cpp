/*
 * =====================================================================================
 *
 *       Filename:  4.q11_func-sort.cpp
 *
 *    Description: sortes an array with func 
 *
 *        Version:  1.0
 *        Created:  06/03/20 17:46:32
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

const int size = 5;

int* my_sort(int nums[size]);


int main()
{
    int nums[size] = { 5, 4, 9, 7, 1 };
        for (int &x: nums)
            cout << x << ", ";
        cout << endl;

    cout << "The biggest item of this array is " << *my_sort(nums) << endl;
    cout << "Sorted arr:" << endl;
        for (int &x: nums)
            cout << x << ", ";
        cout << endl;

    return 0;
}


int* my_sort(int nums[size])    // my_sort - тут конечно можно было намудрить
{                               //   что-то с рекурсией, с привлечением static,
    int temp;                   //   но я выбрал лёгкий путь
    for (int i = 1; i < size; i++)
        for (int k = 0; k < size - i; k++)
            if (nums[k + 1] < nums[k]) {
                temp = nums[k];
                nums[k] = nums[k + 1];
                nums[k + 1] = temp;
            }
    return &nums[size - 1];
}
