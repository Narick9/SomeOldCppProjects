/*
 * =====================================================================================
 *
 *       Filename:  3.9_pointers_symbol-two-dim-features.cpp
 *
 *    Description: creats an array that contains pointers to character
 *                 literals and demonstrates its features
 *
 *        Version:  1.0
 *        Created:  05/18/20 21:37:58
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

int main()
{
    char const *str[3] = { "red", "yellow", "green" };
                // {}         - "red" и {"red"} - одно и то же
                // const      - без этого g++ выдаёт сообщиение, что
                //              стандарт ISO C++ запрещает конвертировать
                //              string constant в char*. Вполне разумно
                // char const - тут стоит заметить, что более привычный
                //              const int равен этому, но он не подчёркивает
                //              нюансы const. Запись const int a говорит
                //              компилятору, что const относится к int a,
                //              но, т.к. int - это тип, то он отбрасывается,
                //              и остаётся что-то вроде const a. Это значит,
                //              что нам нельзя писать a = 6 . Пока всё ок,
                //              но когда в игру вступают указатели,
                //              становится интереснее. const int *a
                //              превращается в const *a, т.е. мы не можем
                //              изменять *a, т.е. место памяти, куда
                //              указывает a, но при этом можно писать
                //              a = 0xF963BA2, и компилятор даже не будет
                //              ругаться. Но если поместить звёздочку левее
                //              const, т.е. int * const a, то тут уже нельзя
                //              изменять само значение a, но при этом память
                //              открыта для изменений, и можно писать *a = 2

    for (int i = 0; i < 3; i++)
        cout << str[i] << endl;

    cout << str[2][0] << **str << *( *(str+2) + 3 ) << *str[1] << endl;

    return 0;
}
