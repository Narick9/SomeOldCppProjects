/*
 * =====================================================================================
 *
 *       Filename:  4.7_pass-by-pointer_swap-chars.cpp
 *
 *    Description: swaps two chars with func with passing by pointers and then
 *                 check them 
 *
 *        Version:  1.0
 *        Created:  05/29/20 17:02:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

void swap(char *_fst, char *_snd);  // * - на самом деле мы здесь также
                                    //     принимает аргументы по значению,
                                    //     просто значения здесь - это адреса
int main()
{
    char fst = 'A',
         snd = 'B';

    cout << "First:  " << fst << endl;
    cout << "Second: " << snd << endl;

    swap(&fst, &snd);

    cout << "First:  " << fst << endl;
    cout << "Second: " << snd << endl;

    return 0;
}


void swap(char *_fst, char *_snd)
{
    cout << "swap():" << endl;

    cout << "\tFirst:  " << *_fst << endl;
    cout << "\tSecond: " << *_snd << endl;

    char temp = *_fst;
    *_fst = *_snd;
    *_snd = temp;
    puts("\t---------");

    cout << "\tFirst:  " << *_fst << endl;
    cout << "\tSecond: " << *_snd << endl;
}
