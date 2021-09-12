/*
 * =====================================================================================
 *
 *       Filename:  1.q12_sum.cpp
 *
 *    Description: outputs sum of input integers using func 
 *
 *        Version:  1.0
 *        Created:  05/05/20 17:45:59
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

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int a, b;
        cout << "a: ";
        cin >> a;
        cout << "b: ";
        cin >> b;

    cout << sum(a, b) << endl;
    return 0;
}
