/*
 * =====================================================================================
 *
 *       Filename:  2.12_goto_squares-sum.cpp
 *
 *    Description: computing squares sum using goto instruction 
 *
 *        Version:  1.0
 *        Created:  05/09/20 15:59:50
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
    int n = 10,
        i = 1,
        sum = 0;

    start:                  // start - это метка
        sum += i * i;
        i++;
        if (i <= n)
    goto start;             // goto - а это инструкция безусловного перехода.
                            //        После нёё ставится имя метки, к которой
                            //        мы переходим. Если ты будешь использовать
                            //        это в реальных проектах, то тебя будут
                            //        осуждать многие другие программисты

    cout << "The sum of squares from 1 to " << n << ": " << sum << endl;
    return 0;
}
