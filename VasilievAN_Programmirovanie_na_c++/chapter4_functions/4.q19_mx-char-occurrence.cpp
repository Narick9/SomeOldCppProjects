/*
 * =====================================================================================
 *
 *       Filename:  4.q16_matrix-biggest.cpp
 *
 *    Description:  computes a number of char occurrence int the text
 *
 *        Version:  1.0
 *        Created:  06/03/20 18:10:08
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>

const int height = 4,
          width  = 10;

int mx_occurrence(char mx_char[height][width], char c);


int main()
{
    srand(-9);

    char mx_char[height][width];
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                mx_char[y][x] = 'a' + rand() % 26;  // 'a' - нам же не нужны
                printf("%c", mx_char[y][x]);        //   нечитаемые символы,
            }                                       //   верно?
            puts("");
        }
    char target = 'r';

    printf("There are %i %c symbols\n", mx_occurrence(mx_char, target), target);

    return 0;
}


int mx_occurrence(char mx_char[height][width], char c)
{
    int occur = 0;
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            if (mx_char[y][x] == c)
                occur++;
    return occur;
}
