/*
 * =====================================================================================
 *
 *       Filename:  3.q20_two-dim-to-smaller-to-dim.cpp
 *
 *    Description: creates two-dim array and fills it with random. Then creates
 *                 another two-dim array from first but without one row and col 
 *
 *        Version:  1.0
 *        Created:  05/25/20 18:58:25
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

void mx_show(int **_mx, int _height, int _width)
{
    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++)
            cout << _mx[y][x] << ", ";
        cout << endl;
    }
}

void is_good(bool _condition, const char *_err_msg, int _err)
{
    if (_condition)
        return;
    printf("ERROR %i\t %s\n", _err, _err_msg);
    exit(_err);
}

int main()
{
    srand(9);
    const int width  = 6,
              height = 3;

    int **mx_nums = new int*[height];       // int** - наладить двумерный
        for (int y = 0; y < height; y++) {  //   массив можно двумя способами:
            mx_nums[y] = new int[width];    //   "хребет" и "линейный массив".
            for (int x = 0; x < width; x++) //   Хребет как раз здесь и описан,
                mx_nums[y][x] = rand() % 10;//   т.е. мы просто создали основу,
        }                                   //   которая, собственно, хребет,
                                            //   хранящую динамические массивы
                                            //   чисел. Линейный массив - это
                                            //   уже натуральный массив, но,
                                            //   правда, выглядящий как
                                            //   костыль. Определяется он так:
                                            //   int arr[y * x], а к элементам
                                            //   обращаются у него так:
                                            //   arr[i*n + j]. Вот такие
                                            //   существуют эмуляции
        mx_show(mx_nums, height, width);
    int row_id;
        cout << "Row to delete:     ";  cin >> row_id;
        is_good(0 <= row_id && row_id < height, "Invalid row id", 1);
    int col_id;
        cout << "Columns to delete: ";  cin >> col_id;
        is_good(0 <= col_id && col_id < width, "Invalid column id", 2);
    int **_mx_nums_mode = new int*[height];
        for (int y = 0; y < height; y++)
            _mx_nums_mode[y] = new int[width];

    int tar_y = 0,
        tar_x = 0;
    for (int y = 0; y < height; y++) {
        if (y == row_id)
            continue;
        for (int x = 0, tar_x = 0; x < width; x++) {
            if (x == col_id)
                continue;
            _mx_nums_mode[tar_y][tar_x] = mx_nums[y][x];
            tar_x++;
        }
        tar_x = 0;
        tar_y++;
    }

    mx_show(_mx_nums_mode, height - 1, width - 1);
    return 0;
}
