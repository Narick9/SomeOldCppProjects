/*
 * =====================================================================================
 *
 *       Filename:  3.5_pointer_character-arrays-features.cpp
 *
 *    Description: demonstrates character arrays features
 *
 *        Version:  1.0
 *        Created:  05/17/20 17:58:51
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
    char str[100] = "We program in C++";

    cout << str << endl;        // cout << str - если бы массив str, т.е.
                                //               указатель str был какого-то
                                //               друго типа, т.е. не char,
                                //               то вывелся бы просто адрес,
                                //               а не содержимое массива до
                                //               нуль-символа. Mассивы символов
                                //               обрабатываются особым образом

    for (int i = 0; str[i]; i++)
        cout << str[i] << "_";
    cout << endl;

    for (char *p = str; *p; p++)
        cout << p << endl;

    str[10] = '\0';
    cout << str << endl;

    cout << str + 11 << endl;

    cout << "One two three" + 4 << endl;

    const char *nums = "One two three" + 8; // const - оказывается, что
    cout << nums[0] << endl;                //         литералы возращают
    cout << nums << endl;                   //         указатель-константу,
                                            //         так что комплятор не
                                            //         примет присвоение к
                                            //         неконстанте. Вполне
                                            //         логично, т.к. литералы
                                            //         хранятся в статической
                                            //         памяти (которая для
                                            //         констант), и нам бы не
                                            //         хотелось потерять этот
                                            //         адрес из-за
                                            //         неосторожности

    return 0;
}
