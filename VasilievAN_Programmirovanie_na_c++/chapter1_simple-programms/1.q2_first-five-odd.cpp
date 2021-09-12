/*
 * =====================================================================================
 *
 *       Filename:  1.q2_first-five-odd.cpp
 *
 *    Description: output first five odd numbers 
 *
 *        Version:  1.0
 *        Created:  05/04/20 22:50:43
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int i = 1,
        k = 0;
    
    while (i < 2 * 5) {
        cout << i << endl;
        i += 2;
    }

    return 0;
}
