/*
 * =====================================================================================
 *
 *       Filename:  3.q12_strange-dif-mx-composition.cpp
 *
 *    Description: creates two matrices and multiples them 
 *
 *        Version:  1.0
 *        Created:  05/22/20 19:48:39
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
    srand(1);
    const int mx_left_height = 2,
              mx_common_size = 4,
              mx_right_width = 8;

    int mx_left[mx_left_height][mx_common_size];
        for (int y = 0; y < mx_left_height; y++) {
            for (int x = 0; x < mx_common_size; x++) {
                mx_left[y][x] = rand() % 10;
                cout << mx_left[y][x] << ", ";
            }
            cout << endl;
        }
        cout << endl;
    int mx_right[mx_common_size][mx_right_width];
        for (int y = 0; y < mx_common_size; y++) {
            for (int x = 0; x < mx_right_width; x++) {
                mx_right[y][x] = rand() % 10;
                cout << mx_right[y][x] << ", ";
            }
            cout << endl;
        }
        cout << endl;
    int mx_comp[mx_left_height][mx_right_width] = {0};

    for (int y = 0; y < mx_left_height; y++)
        for (int x = 0; x < mx_right_width; x++)
            for (int i = 0; i < mx_common_size; i++)
                mx_comp[y][x] += mx_left[y][i] * mx_right[i][x];

    for (int y = 0; y < mx_left_height; y++) {
        for (int x = 0; x < mx_right_width; x++)
            printf("%3i, ", mx_comp[y][x]);
        cout << endl;
    }
    return 0;
}
