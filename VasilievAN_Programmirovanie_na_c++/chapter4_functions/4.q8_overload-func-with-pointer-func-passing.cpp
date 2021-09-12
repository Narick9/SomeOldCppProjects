/*
 * =====================================================================================
 *
 *       Filename:  4.q8_overload-func-with-pointer-func-passing.cpp
 *
 *    Description: creates a int arr and passes it to a overload func with func
 *                 agregator or num instead for applying it to each item 
 *
 *        Version:  1.0
 *        Created:  06/01/20 22:23:26
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

const int size = 4;

void aggregate(int arr[size], int (*aggregator)(int));
int increase(int num);


int main()
{
    int nums[size];
        for (int i = 0; i < size; i++) {
            nums[i] = size - i;
            cout << nums[i] << ", ";
        } cout << endl;


    aggregate(nums, increase);

    for (int &x: nums)
        cout << x << ", ";
    cout << endl;
    return 0;
}


void aggregate(int arr[size], int (*aggregator)(int))
{
    for (int i = 0; i < size; i++)      // for - даже при записи int arr[size],
        arr[i] = aggregator(arr[i]);    //   которая вроде как должна была дать
}                                       //   полную инфу, цикл по коллекции не 
                                        //   работает.
int increase(int num)                   // int arr[size] - size тут видимо
{                                       //   вообще не даёт ничего, т.к. на
    return num + 1;                     //   вход легко поступают массивы с
}                                       //   меньшими и большими размерами.
                                        //   Тестил с g++. Странно, я почему то
                                        //   думал, что оно блокирует это
