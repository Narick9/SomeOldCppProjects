/*
 * =====================================================================================
 *
 *       Filename:  3.q10_two-dim_filling-top-to-down.cpp
 *
 *    Description: creates an array and fills it in columns with user input
 *
 *        Version:  1.0
 *        Created:  05/22/20 18:22:59
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

const int width  = 4,
          height = 2;

void mx_show_incomplete(int _arr[height][width], int _cur_y, int _cur_x)
{
    int y, x;
    for (y = 0; y < _cur_y + 1; y++) {
        for (x = 0; x < _cur_x + 1; x++)
            cout << _arr[y][x] << ", ";
        cout << endl;
    }
    for (; y < height; y++) {
        for (x = 0; x < _cur_x; x++)
            cout << _arr[y][x] << ", ";
        cout << endl;
    }
}

int main()
{
    int mx_nums[height][width] = {9};

    int _n;
    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++) {
            cin >> _n;
            mx_nums[y][x] = _n;
            cout << endl;
            mx_show_incomplete(mx_nums, y, x);
        }
    return 0;
}
