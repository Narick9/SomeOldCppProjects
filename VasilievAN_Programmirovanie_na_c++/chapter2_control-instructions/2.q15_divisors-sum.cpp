/*
 * =====================================================================================
 *
 *       Filename:  2.q15_divisors-sum.cpp
 *
 *    Description: gets an number and outputs its divisors sum 
 *
 *        Version:  1.0
 *        Created:  05/11/20 16:21:48
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

double div_sum(int _num)
{
    double sum = 0;
    for (int i = _num; i > 0; i--)
        sum += (double)_num / i;
    return sum;
}

int main()
{
    int _num;
        cout << "Num: ";
        cin >> _num;

    cout << "Its divisors sum: " << div_sum(_num) << endl;
    return 0;
}
