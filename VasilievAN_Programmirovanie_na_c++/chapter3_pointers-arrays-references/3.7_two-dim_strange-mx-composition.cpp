/*
 * =====================================================================================
 *
 *       Filename:  3.7_two-dim_strange-mx-composition.cpp
 *
 *    Description: creates two matrix and multiplies them using interesting
 *                 method
 *
 *        Version:  1.0
 *        Created:  05/18/20 17:44:20
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <cstdio>
using namespace std;

const int dim_capacity = 3;

void show(int _arr[dim_capacity][dim_capacity])
{
    for (int y = 0; y < dim_capacity; y++) {
        for (int x = 0; x < dim_capacity; x++)
            printf("%4d", _arr[y][x]);          // d - это значит decimal -
         printf("\n");                          //     десятичной. В отличии от
    }                                           //     i, он работает только с
}                                               //     с ними. i же может
                                                //     принимать ещё 0-числа,
                                                //     т.е. восьмиричные, и
                                                //     0x-числа, т.е
                                                //     шестнадцатиричные.
                                                //     В printf() разницы нет,
                                                //     но при вводе в scanf()
                                                //     это может играть роль

int main()
{
    int mx_a[dim_capacity][dim_capacity] = {{1, -2, 1},
                                            {2, 0, -1},
                                            {2, 3, -1}};
        printf("Matrix A:\n");
        show (mx_a);
    int mx_b[dim_capacity][dim_capacity] = {{2, 1, -1},
                                            {1, 3, 1},
                                            {-2, 1, 4}};
        printf("Matrix B:\n");
        show(mx_b);
    int mx_c[dim_capacity][dim_capacity];
        for (int y = 0; y < dim_capacity; y++)
            for (int x = 0; x < dim_capacity; x++) {
                mx_c[y][x] = 0;
                for (int i = 0; i < dim_capacity; i++)
                    mx_c[y][x] += mx_a[y][i] * mx_b[i][x];
            }
        printf("Matrix C (equivalent to A * B):\n");
        show(mx_c);

    return 0;
}
