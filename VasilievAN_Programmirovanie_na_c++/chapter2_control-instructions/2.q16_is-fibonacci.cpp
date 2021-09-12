/*
 * =====================================================================================
 *
 *       Filename:  2.q16_is-fibonacci.cpp
 *
 *    Description: gets a number and says whether it is fibonacci 
 *
 *        Version:  1.0
 *        Created:  05/11/20 17:55:07
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

bool is_fibonacci_switch(int _num)
{
    switch (_num) {
        case 1:
        case 2:
        case 3:
        case 5:
        case 8:
            return true;
        default:
            return false;
    }
}

bool is_fibonacci_recreate(int _num)
{
    int sub_last = 0,
        last = 1,
        cur;
    while (last <= _num) {
        cur = sub_last + last;
        if (cur == _num)
            return true;
        sub_last = last;
        last = cur;
    }
    return false;
}

int main()
{
    int _num;
        cout << "Num (1-10): ";
        cin >> _num;

   if (is_fibonacci_recreate(_num))
       cout << "This number is fibonacci number" << endl;
   else
       cout << "This number is not fibonacci number" << endl;
   return 0;
}
