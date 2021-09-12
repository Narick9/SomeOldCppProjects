/*
 * =====================================================================================
 *
 *       Filename:  2.6_switch_from-num-to-word.cpp
 *
 *    Description: inputs numbers from 1 to 3 and output them like words 
 *
 *        Version:  1.0
 *        Created:  05/07/20 20:07:58
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
    int _inp;
    for (int i = 0; i < 5; i++) {
        cout << "Set a number from 1 to 3: ";
            cin >> _inp;
        switch (_inp) {
            case 1:     cout << "This is one"   << endl;  break;
            case 2:     cout << "This is two"   << endl;  break;
            case 3:     cout << "This is three" << endl;  break; 
            default:
                 cout << "I don't know this number" << endl;
        }
    }
    return 0;
}
