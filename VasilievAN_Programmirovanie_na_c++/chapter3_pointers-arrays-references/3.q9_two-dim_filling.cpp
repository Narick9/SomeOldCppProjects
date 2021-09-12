/*
 * =====================================================================================
 *
 *       Filename:  3.q9_two-dim_filling.cpp
 *
 *    Description: creates an array and fills it with the input 
 *
 *        Version:  1.0
 *        Created:  05/22/20 17:58:43
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
    for (y = 0; y < _cur_y; y++) {
        for (int x = 0; x < width; x++)
            cout << _arr[y][x] << ", ";
        cout << endl;
    }
    for (x = 0; x < _cur_x + 1; x++)
        cout << _arr[y][x] << ", ";
    if (_cur_x == width - 1)
        cout << endl;
}

int main()
{
    int mx_nums[height][width];

    int _n;
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++) {
                cin >> _n;
                mx_nums[y][x] = _n;
                cout << endl;
                mx_show_incomplete(mx_nums, y, x);
            }

    return 0;
}
