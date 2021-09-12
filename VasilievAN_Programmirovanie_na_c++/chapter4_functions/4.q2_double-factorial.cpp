/*
 * =====================================================================================
 *
 *       Filename:  4.q2_double-factorial.cpp
 *
 *    Description: computes double factorial with using different ways 
 *
 *        Version:  1.0
 *        Created:  05/31/20 17:30:56
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

int double_fact_recursion(int n);
int double_fact_cycle(int n);


int main()
{
    cout << "Double factorial of 6 with using recursion: "
         << double_fact_recursion(6) << endl;
    cout << "Double factorial of 6 with using cycle:     "
         << double_fact_cycle(6) << endl;
    return 0;
}


int double_fact_recursion(int n)
{
    if (n < 2)
        return 1;
    return n * double_fact_recursion(n - 2);
}

int double_fact_cycle(int n)
{
    int fact = 1;
    while (n > 1) {
        fact *= n;
        n -= 2;
    }
    return fact;
}
