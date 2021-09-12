/*
 * =====================================================================================
 *
 *       Filename:  3.q14_two-dim-min-max-for-cols-rows.cpp
 *
 *    Description: creates a matrix, fills it and computes min and max for
 *                 each row and columns 
 *
 *        Version:  1.0
 *        Created:  05/23/20 23:40:32
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
    const int width  = 8,
              height = 3;

    int mx_nums[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                mx_nums[y][x] = rand() % 10;
                cout << mx_nums[y][x] << ", ";
            }
            cout << endl;
        }
    int _row_mins[height],
        _row_maxs[height];
            for (int y = 0; y < height; y++) {
                _row_mins[y] = _row_maxs[y] = mx_nums[y][0];
                for (int x = 0; x < width; x++) {
                    if (mx_nums[y][x] < _row_mins[y])
                        _row_mins[y] = mx_nums[y][x];
                    if (mx_nums[y][x] > _row_maxs[y])
                        _row_maxs[y] = mx_nums[y][x];
                }
            }
    int _col_mins[width],
        _col_maxs[width];
            for (int x = 0; x < width; x++) {
                _col_mins[x] = _col_maxs[x] = mx_nums[0][x];
                for (int y = 0; y < height; y++) {
                    if (mx_nums[y][x] < _col_mins[x])
                        _col_mins[x] = mx_nums[y][x];
                    if (mx_nums[y][x] > _col_maxs[x])
                        _col_maxs[x] = mx_nums[y][x];
                }
            }

    cout << "row mins: ";
    for (int &x: _row_mins)
        cout << x << ", ";
    cout << endl;
    cout << "row maxs: ";
    for (int &x: _row_maxs)
        cout << x << ", ";
    cout << endl;
    cout << "column mins: ";
    for (int &x: _col_mins)
        cout << x << ", ";
    cout << endl;
    cout << "column maxs: ";
    for (int &x: _col_maxs)
        cout << x << ", ";
    cout << endl;
    return 0;
}
