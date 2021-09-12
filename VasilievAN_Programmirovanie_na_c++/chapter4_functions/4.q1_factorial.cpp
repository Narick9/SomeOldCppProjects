/*
 * =====================================================================================
 *
 *       Filename:  4.q1_factorial.cpp
 *
 *    Description: computes factorial with different ways 
 *
 *        Version:  1.0
 *        Created:  05/31/20 17:19:06
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

int fact_recursion(int n);
int fact_cycle(int n);


int main()
{
    cout << "Factorial of 5 with using recursion: " << fact_recursion(5)
         << endl;
    cout << "Factorial of 5  with using cycle:    " << fact_cycle(5) << endl;
    return 0;
}


int fact_recursion(int n)
{
    if (n == 1)
        return 1;
    return n * fact_recursion(n - 1);
}

int fact_cycle(int n)
{
    int fact = 1;
    while (n > 1)
        fact *= n--;
    return fact;
}
