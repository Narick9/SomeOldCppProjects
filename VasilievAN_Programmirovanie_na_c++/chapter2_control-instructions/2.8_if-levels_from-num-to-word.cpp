/*
 * =====================================================================================
 *
 *       Filename:  2.8_if-levels_from-num-to-word.cpp
 *
 *    Description: gets a num and output some info about it using nested ifs 
 *
 *        Version:  1.0
 *        Created:  05/07/20 22:47:32
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
    for (int _ = 0, num; _ < 5; _++) {
        cout << "Set a number from 1 to 3: ";
            cin >> num;
        if (num == 1)
            cout << "This is one" << endl;
        else
            if (num == 2)
                cout << "This is two" << endl;
            else
                if (num == 3)
                    cout << "This is three" << endl;
                else
                    cout << "I don't know this number" << endl;
    }
    return 0;
}
