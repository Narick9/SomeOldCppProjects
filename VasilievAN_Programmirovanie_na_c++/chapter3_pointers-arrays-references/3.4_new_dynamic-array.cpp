/*
 * =====================================================================================
 *
 *       Filename:  3.4_new_dynamic-array.cpp
 *
 *    Description: creates an dynamic array with new, fills it and
 *                 then frees up its memory using delete
 *
 *        Version:  1.0
 *        Created:  05/16/20 23:26:21
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
    int *size = new int;                // new - это как malloc(), но
                                        //       безопаснее и проще
        cout << "The array size: ";
        cin >> *size;
    char *symbs = new char[*size];      // new [] - так динамически выделяется
                                        //          память. При обычной записи
                                        //          char arr[n] вродек как n
                                        //          должен быть константой,
                                        //          т.к. память выделятся ещё
                                        //          комплятором. Я это
                                        //          протестировал и заметил,
                                        //          что n может и не быть
                                        //          константой (по крайней мере 
                                        //          в C для компилятора gcc)

    for (int i = 0; i < *size; i++) {
        symbs[i] = 'a' + i;
        cout << symbs[i] << " ";
    }
    cout << endl;

    delete size;            // delete    - а это как free()
    delete [] symbs;        // delete [] - это delete так понимает, что перед
                            //             ним массив. Также, как и free(),
                            //             он знает сколько именно байт ему
                            //             следует освободить. Разные
                            //             компиляторы по разному реализуют
                            //             эту магию. Например, несколько байт
                            //             перед памятю, которую ты занял
                            //             через malloc(), могут хранить эту
                            //             информацию
    cout << "Memory has been freed" << endl;
    return 0;
}
