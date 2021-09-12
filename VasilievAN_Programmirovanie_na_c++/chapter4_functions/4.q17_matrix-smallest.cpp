/*
 * =====================================================================================
 *
 *       Filename:  4.q17_matrix-smallest.cpp
 *
 *    Description:  finds the smallest item of a matrix 
 *
 *        Version:  1.0
 *        Created:  06/04/20 17:47:08
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

int& mx_smallest(int mx[height][width]);


int main()
{
    int mx[height][width] = { {0, 5, 2},    // {} - да, я просто копировал весь
                              {9, 2, 5},    //   файл
                              {6, 4, 8},
                              {0, 3, 6} };
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++)
                cout << mx[y][x] << ", ";
            cout << endl;
        }

    cout << "The smallest item is " << mx_smallest(mx) << endl;

    return 0;
}


int& mx_smallest(int mx[height][width])
{
    int &smallest = mx[0][0];
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            if (mx[y][x] < smallest)
                smallest = mx[y][x];
    return smallest;
}
