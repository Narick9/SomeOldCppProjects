/*
 * =====================================================================================
 *
 *       Filename:  4.q17_matrix-mean.cpp
 *
 *    Description:  finds a mean of a matrix 
 *
 *        Version:  1.0
 *        Created:  06/04/20 17:50:08
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

float mx_mean(int mx[height][width]);


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

    cout << "The mean is " << mx_mean(mx) << endl;

    return 0;
}


float mx_mean(int mx[height][width])    // float - у меня такое ощущение, что
{                                       //   автор книги его не знает
    int sum = mx[0][0];
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            sum += mx[y][x];
    return (float) sum / (height * width);
}
