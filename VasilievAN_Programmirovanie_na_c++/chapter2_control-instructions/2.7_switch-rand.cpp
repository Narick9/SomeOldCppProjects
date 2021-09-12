/*
 * =====================================================================================
 *
 *       Filename:  2.7_switch-rand.cpp
 *
 *    Description: output some info about random number 
 *
 *        Version:  1.0
 *        Created:  05/07/20 21:42:30
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

    for (int _ = 0, num; _ < 10; _++) {
        num = 2 + rand() % 7;
        switch (num) {       // rand() - возвращает рандомное число
                             //          от 0 до ... большого числа
            case 3:
            case 6:
                cout << num << " is divided by three" << endl;
                break;
            case 2:
            case 4:
            case 8:
                cout << num << " is a power of two" << endl;
                break;
            case 5:
                cout << num << " is five" << endl;
                break;
            case 7:
                cout << num << " is seven" << endl;
        }
    }
    return 0;
}
