/*
 * =====================================================================================
 *
 *       Filename:  7-check-input_5-alt.cpp
 *
 *    Description: 5 alternative with input check 
 *
 *        Version:  1.0
 *        Created:  05/04/20 18:41:21
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
    int n,
        s = 0;

        cout << "Top sum edge: ";
        cin >> n;

        if (n < 0) {
            cout << "Incorrect num" << endl;
            return 1;
        }
    
    while (n) {
        s += n * n;
        n--;
    }

    cout << "Squares sum: " << s << endl;
    return 0;
}
