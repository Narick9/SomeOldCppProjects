/*
 * =====================================================================================
 *
 *       Filename:  2.10_collection-cycle_array-counting.cpp
 *
 *    Description: creates an array, fills it using collection-cycle and
 *                 outputs it
 *
 *        Version:  1.0
 *        Created:  05/08/20 19:01:08
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    srand(2);

    int arr[12];
        cout << "An array with random numbers:" << endl;
        for (int &x: arr) {
            x = rand() % 10;
            cout << x << " ";
        }                       // for - это называется циклом по коллекции
                                //       (коллекция здесь - это как-бы массив).
                                //       Переменная в скобках последовательно
                                //       ссылается на каждый элемент массива.
                                //       Символ & нужен, чтобы она не просто
                                //       принимала значение, а была полноценной
                                //       ссылкой. Ссылка - это такое
                                //       альтернативное название для элемента
                                //       массива, поэтому через неё мы можем
                                //       даже изменить этот самый элемент
        cout << endl;

    int lenght = 0;
        for (int &x: arr) {
            lenght++;
        }

    cout << "The size of the array: " << lenght << endl;
    cout << "The array content checking:" << endl;
    for (int i = 0; i < lenght; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
