/*
 * =====================================================================================
 *
 *       Filename:  4.q13_the-biggest-word-func.cpp
 *
 *    Description:  displays a lenght of the biggest word in text with func
 *
 *        Version:  1.0
 *        Created:  06/03/20 19:08:06
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

int biggest_word_lenght(char *text);


int main()
{
    char text[] = "  Hello, musya! ";
        cout << "\"" << text << "\"" << endl;

    cout << "Chars in the biggest word: " << biggest_word_lenght(text) << endl;

    return 0;
}


int biggest_word_lenght(char *text)
{
    int biggest       = 0,
        last_space_id = -1,
        i             = -1;
    while (text[++i]) {
        if (   ('a' <= text[i] && text[i] <= 'z')
            || ('A' <= text[i] && text[i] <= 'Z'))
            continue;
        if (i - last_space_id - 1 > biggest)
            biggest = i - last_space_id - 1;
        last_space_id = i;
    }
    if (i - last_space_id - 1 > biggest)
        biggest = i - last_space_id - 1;
    return biggest;
}
