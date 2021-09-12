/*
 * =====================================================================================
 *
 *       Filename:  3.q4_square-mx-transpose.cpp
 *
 *    Description: creates a square matrix and transposes it 
 *
 *        Version:  1.0
 *        Created:  05/19/20 16:09:58
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

const int dim_size = 5;

void mx_show(int _mx[dim_size][dim_size])
{
    for (int y = 0; y < dim_size; y++) {
        for (int x = 0; x < dim_size; x++)
            cout << _mx[y][x] << ", ";
        cout << endl;
    }
}

int main()
{
    srand(7);

    int mx_nums[dim_size][dim_size];
        cout << "The reference" << endl;
        for (int y = 0; y < dim_size; y++)
            for (int x = 0; x < dim_size; x++)
                mx_nums[y][x] = rand() % 10;
        mx_show(mx_nums);

    for (int y = 0; y < dim_size - 1; y++)
        for (int x = y + 1, buf; x < dim_size; x++) {
            buf = mx_nums[x][y];
            mx_nums[x][y] = mx_nums[y][x];
            mx_nums[y][x] = buf;
        }

    cout << "A transpose version" << endl;
    mx_show(mx_nums);
    return 0;
}
