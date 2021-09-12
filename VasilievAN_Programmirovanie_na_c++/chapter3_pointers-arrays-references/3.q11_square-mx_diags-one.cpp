/*
 * =====================================================================================
 *
 *       Filename:  3.q11_square-mx_diags-one.cpp
 *
 *    Description: creates a square matrix with identity diagonals 
 *
 *        Version:  1.0
 *        Created:  05/22/20 19:37:33
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
    const int dim_size = 5;

    int mx_nums[dim_size][dim_size] = {0};

    for (int i = 0; i < dim_size; i++)
        mx_nums[i][i] = mx_nums[i][dim_size - 1 - i] = 1;

    for (int y = 0; y < dim_size; y++) {
        for (int x = 0; x < dim_size; x++)
            cout << mx_nums[y][x] << "  ";
        cout << endl;
    }
    cout << endl;
    return 0;
}
