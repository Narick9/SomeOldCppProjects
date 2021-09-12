/*
 * =====================================================================================
 *
 *       Filename:  4.10_two-dim-dynamic_mx-show.cpp
 *
 *    Description: creates two-dim ridge array and displays it with func 
 *
 *        Version:  1.0
 *        Created:  05/30/20 15:38:39
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

void show(int **_mx, int _y_size, int _x_size);


int main()
{
    const int height = 3,
              width  = 5;

    int **mx_nums = new int*[width];
        for (int y = 0; y < height; y++) {
            mx_nums[y] = new int[width];
            for (int x = 0; x < width; x++)
                mx_nums[y][x] = y*width + x + 1;
        }

    show(mx_nums, height, width);

    for (int y = 0; y < height; y++)
        delete [] mx_nums[y];
    delete [] mx_nums;
    return 0;
}


void show(int **_mx, int _y_size, int _x_size)
{
    for (int y = 0; y < _y_size; y++) {
        for (int x = 0; x < _x_size; x++)
            printf("%3i, ", _mx[y][x]);
        printf("\n");
    }
}
