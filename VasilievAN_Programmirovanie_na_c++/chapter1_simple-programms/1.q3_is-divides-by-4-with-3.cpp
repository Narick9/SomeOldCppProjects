/*
 * =====================================================================================
 *
 *       Filename:  1.q3_is-divides-by-4-with-3.cpp
 *
 *    Description: output the numbers that when divides by 4 gives 3
 *
 *        Version:  1.0
 *        Created:  05/05/20 13:59:26
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
    int n = 0;
        cout << "How many numbers will be outputed? ";
        cin >> n;

    int i = 3;
    while (n) {
        cout << i << " ";
        i += 4;
        n--;
    }
    cout << endl;

    return 0;
}
