/*
 * =====================================================================================
 *
 *       Filename:  3.q15_text-word-count.cpp
 *
 *    Description: accepts user input and counts words and each word size in it
 *
 *        Version:  1.0
 *        Created:  05/24/20 19:16:06
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

int main()
{
    const int size = 100;
    char _text[size];
        fgets(_text, size, stdin);
        if (strchr(_text, '\n'))
            _text[strchr(_text, '\n') - _text] = '\0';
    int _n_word = 0,
        _words_sizes[size];
        
    int i = 0,
        j = 0,
        limit = strlen(_text);
    size_t word_start;

    while (true) {
        while (_text[i] == ' ' && i < limit)
            i++;
        if (i == limit)
            break;
        word_start = i;
        while (_text[i] != ' ' && i < limit)
            i++;
        _n_word++;
        _words_sizes[j++] = i - word_start;
        if (i == limit)
            break;
    }

    printf("There are %i words\n", _n_word);
    printf("Their sizes: ");
    for (int k = 0; k < _n_word; k++)
        printf("%i, ", _words_sizes[k]);
    puts("");
    return 0;
}
