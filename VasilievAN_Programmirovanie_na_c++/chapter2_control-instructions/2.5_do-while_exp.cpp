/*
 * =====================================================================================
 *
 *       Filename:  2.5_do-while_exp.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/06/20 18:34:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n = 100,
        x = 1;
    double sum    = 0,
           append = 1;

    int i = 0;
    do {
        sum += append;
        i++;
        append *= (double)x / i;
    } while (i < n);

    cout << "Computed value: " << sum << endl;
    cout << "Control value:  " << exp(x) << endl;
    return 0;
}
