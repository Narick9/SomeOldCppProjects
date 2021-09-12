/*
 * =====================================================================================
 *
 *       Filename:  4.q15_char-occurrence.cpp
 *
 *    Description:  computes the number of occurrences of a symbol in a text  
 *
 *        Version:  1.0
 *        Created:  06/03/20 20:11:49
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <cstdio>
using namespace std;

int n_occurrences(char *text, char c);


int main()
{
    char text[] = "Again hello!";
        puts(text);
    char target = 'l';
    
    printf("There are %i '%c' symboles\n", n_occurrences(text, target), target);

    return 0;
}


int n_occurrences(char *text, char c)
{
    int n = 0;
    for (int i = 0; text[i]; i++)
        if (text[i] == c)
            n++;
    return n;
}
