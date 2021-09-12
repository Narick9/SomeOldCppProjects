/*
 * =====================================================================================
 *
 *       Filename:  3.q6_square-mx-trace.cpp
 *
 *    Description: creates a two-dimensional array and computes its trace 
 *
 *        Version:  1.0
 *        Created:  05/19/20 21:01:53
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
    srand(8);
    const int dim_size = 5;

    int mx_nums[dim_size][dim_size];
        for (int y = 0; y < dim_size; y++) {
            for (int x = 0; x < dim_size; x++) {
                mx_nums[y][x] = rand() % 10;
                cout << mx_nums[y][x] << ", ";
            }
            cout << endl;
        }
    int trace = 0;
        for (int i = 0; i < dim_size; i++)
            trace += mx_nums[i][i];

    cout << "The trace is " << trace << endl;
    return 0;
}
