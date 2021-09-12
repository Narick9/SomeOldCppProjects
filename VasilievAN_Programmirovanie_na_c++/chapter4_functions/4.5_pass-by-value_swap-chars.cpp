/*
 * =====================================================================================
 *
 *       Filename:  4.5_pass-by-value_swap-chars.cpp
 *
 *    Description: swaps two chars with funs with passing by value and then
 *                 check them 
 *
 *        Version:  1.0
 *        Created:  05/29/20 16:38:14
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

void swap(char _fst, char _snd);


int main()
{
    char fst = 'A',
         snd = 'B';

    cout << "First:  " << fst << endl;
    cout << "Second: " << snd << endl;

    swap(fst, snd);

    cout << "First:  " << fst << endl;
    cout << "Second: " << snd << endl;

    return 0;
}


void swap(char _fst, char _snd)
{
    cout << "swap():" << endl;

    cout << "\tFirst:  " << _fst << endl;
    cout << "\tSecond: " << _snd << endl;

    char temp = _fst;
    _fst = _snd;
    _snd = temp;
    puts("\t---------");

    cout << "\tFirst:  " << _fst << endl;
    cout << "\tSecond: " << _snd << endl;
}
