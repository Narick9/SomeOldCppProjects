/*
 * =====================================================================================
 *
 *       Filename:  4.q16_matrix-biggest.cpp
 *
 *    Description:  finds the biggest item of a matrix 
 *
 *        Version:  1.0
 *        Created:  06/03/20 21:01:08
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

const int height = 4,
          width  = 3;

int& mx_biggest(int mx[height][width]);


int main()
{
    int mx[height][width] = { {0, 5, 2},
                              {9, 2, 5},
                              {6, 4, 8},
                              {0, 3, 6} };
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++)
                cout << mx[y][x] << ", ";
            cout << endl;
        }

    cout << "The biggest item is " << mx_biggest(mx) << endl;

    return 0;
}


int& mx_biggest(int mx[height][width])
{
    int &biggest = mx[0][0];
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            if (mx[y][x] > biggest)
                biggest = mx[y][x];
    return biggest;
}
