/*
 * =====================================================================================
 *
 *       Filename:  4.q20_mx-text-occurrence.cpp
 *
 *    Description:  computes a number of char occurrence int the text
 *
 *        Version:  1.0
 *        Created:  06/03/20 18:30:08
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
          width  = 35;

int mx_text_occurrence(char mx_text[height][width], char c);


int main()
{
    srand(-9);

    char mx_text[height][width] = { "Greased Lightning",
                                    "It's Not All It's Cracked Up To Be",
                                    "A Chip on Your Shoulder" };
        for (int y = 0; y < height; y++)        // [][] - для текста лучше не
            printf("%s\n", (char*)&mx_text[y]); //   использовать матрицу, т.к.
    char target = 'r';                          //   часто остаётся не
                                                //   используемая память
    printf("There are %i %c symbols\n",
            mx_text_occurrence(mx_text, target), target);

    return 0;
}


int mx_text_occurrence(char mx_text[height][width], char c)
{
    int occur = 0;
    for (int y = 0; y < height; y++)
        for (int x = 0; mx_text[y][x]; x++)
            if (mx_text[y][x] == c)
                occur++;
    return occur;
}
