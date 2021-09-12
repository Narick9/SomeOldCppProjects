/*
 * =====================================================================================
 *
 *       Filename:  3.q1_sum-comp-arrays.cpp
 *
 *    Description: creates two int arrays and summarizes their pairwise
 *                 products 
 *
 *        Version:  1.0
 *        Created:  05/19/20 14:41:09
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

int main()
{
    srand(5);
    const int size = 5;

    int lefts[size];
        for (int &x: lefts) {
            x = rand() % 10;
            cout << x << ", ";
        }
        cout << endl;
    int rights[size];
        for (int &x: rights) {
            x = rand() % 10;
            cout << x << ", ";
        }
        cout << endl;
    int sum = 0;

    for (int i = 0; i < size; i++)
        sum += lefts[i] * rights[i];
    cout << "The sum is " << sum << endl;
    return 0;
}
