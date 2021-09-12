/*
 * =====================================================================================
 *
 *       Filename:  4.11_text-pass_text-describe.cpp
 *
 *    Description: displays decribe about text array with using funcs 
 *
 *        Version:  1.0
 *        Created:  05/30/20 16:05:39
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

void show_info(char *text);     // text - видимо, компилятор вообще игнорирует
int get_symbol_n(char *text);   //        имена параметров в объявлении функции
int get_space_n(char *text);


int main()
{
    char text[100] = "We are learning the C++ programming language";

    show_info(text);
    show_info((char *)"C++ has classes and objects"); 
                                      // "" - помним, что это зовётся литерал
    return 0;
}


void show_info(char *_text)
{
    cout << "Phrase:            " << _text << endl;
    cout << "There are symbols: " << get_symbol_n(_text) << endl;
    cout << "There are spaces:  " << get_space_n(_text) << endl;
    cout << "------------------------" << endl;
}

int get_symbol_n(char *_text)
{
    int n = 0;
    for (int i = 0; _text[i]; i++)
        n++;
    return n;
}

int get_space_n(char *_text)
{
    int n = 0;
    for (int i = 0; _text[i]; i++)
        if (_text[i] == ' ')
            n++;
    return n;
}
