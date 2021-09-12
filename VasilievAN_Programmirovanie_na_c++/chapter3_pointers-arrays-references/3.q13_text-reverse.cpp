/*
 * =====================================================================================
 *
 *       Filename:  3.q13_text-reverse.cpp
 *
 *    Description: creates an symbol array, fills it with user input and
 *                 reverse 
 *
 *        Version:  1.0
 *        Created:  05/22/20 21:45:35
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    const int size = 100;

    char _text[size];
        fgets(_text, size, stdin);
        if (strchr(_text, '\n'))
            _text[strchr(_text, '\n') - _text] = '\0';

    int true_size = strlen(_text);
    char tmp;
    for (int i = 0; i < true_size/2; i++) {
        tmp = _text[i];
        _text[i] = _text[(true_size - 1) - i];
        _text[(true_size - 1) - i] = tmp;
    }

    printf("%s\n", _text);
    return 0;
}
