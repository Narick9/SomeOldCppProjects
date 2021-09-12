/*
 * =====================================================================================
 *
 *       Filename:  4.q7_sum-overload-power.cpp
 *
 *    Description:  calculates the sum of degrees of numbers depending on their
 *                  number
 *
 *        Version:  1.0
 *        Created:  06/01/20 20:29:42
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

int sum_of_degrees(int n1);
int sum_of_degrees(int n1, int n2);
int sum_of_degrees(int n1, int n2, int n3);


int main()
{
    cout << "1:       " << sum_of_degrees(1) << endl;
    cout << "1, 3:    " << sum_of_degrees(1, 3) << endl;
    cout << "1, 3, 8: " << sum_of_degrees(1, 3, 8) << endl;
    return 0;
}


int sum_of_degrees(int n1)
{
    return n1;
}

int sum_of_degrees(int n1, int n2)
{
    return n1*n1 + n2*n2;
}

int sum_of_degrees(int n1, int n2, int n3)
{
    return n1*n1*n1 + n2*n2*n2 + n3*n3*n3;
}
