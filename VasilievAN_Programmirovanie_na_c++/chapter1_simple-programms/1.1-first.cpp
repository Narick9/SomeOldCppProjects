/*
 * =====================================================================================
 *
 *       Filename:  1-first.cpp
 *
 *    Description: first cpp programm in the book 
 *
 *        Version:  1.0
 *        Created:  05/04/20 17:04:19
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author: Artur 
 *   Organization: Musya inc. 
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    // system("chcp 65001 > nul");     // chcp  - утилита cmd в Windows, меняет кодовую
    //                                 //         страницу. Объявляется в cstdlib
    //                                 // 65001 - таблица юникода
    //                                 // >     - перевод вывода левой команды вправо
    //                                 // nul   - аналог NULL в cmd в Windows
    cout << "Программируем на C++!" << endl;

    // system("pause > nul");
    return 0;
}
