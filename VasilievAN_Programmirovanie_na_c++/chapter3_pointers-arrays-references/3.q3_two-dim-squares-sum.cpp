/*
 * =====================================================================================
 *
 *       Filename:  3.q3_two-dim-squares-sum.cpp
 *
 *    Description: creates matrix and computes squares sum of its elements 
 *
 *        Version:  1.0
 *        Created:  05/19/20 15:51:49
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
    srand(5);
    const int width  = 5,
              height = 2;

    int mx_nums[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                mx_nums[y][x] = rand() % 10;
                cout << mx_nums[y][x] << ", ";
            }
            cout << endl;
        }
    int sum = 0;
    
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            sum += mx_nums[y][x] * mx_nums[y][x];

    cout << "The squares sum is " << sum << endl;
    return 0;
}
