/*
 * =====================================================================================
 *
 *       Filename:  3.6_two-dim-arrays_demonstration.cpp
 *
 *    Description: creates a two-dimensional array and fills it with random
 *                 letters 
 *
 *        Version:  1.0
 *        Created:  05/17/20 23:43:09
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
    srand(2);
    const int width  = 9,
              height = 5;

    char mx_letters[width][height];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            mx_letters[y][x] = 'A' + rand() % 26;
            cout << mx_letters[y][x] << " ";
        }
        cout << endl;
    }

    return 0;
}
