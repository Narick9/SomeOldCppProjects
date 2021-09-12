/*
 * =====================================================================================
 *
 *       Filename:  3.1_pointers_acquaintance.cpp
 *
 *    Description: creates two pointers and tests them 
 *
 *        Version:  1.0
 *        Created:  05/16/20 16:14:32
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
    char c;
    int n;

    char *p_c = &c;
    int *p_n = &n;

    *p_c = 'A';
    *p_n = 100;

    cout << "c: " << c << endl;
    cout << "n: " << n << endl;
    return 0;
}
