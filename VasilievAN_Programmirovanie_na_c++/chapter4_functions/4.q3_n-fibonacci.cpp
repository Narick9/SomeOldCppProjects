/*
 * =====================================================================================
 *
 *       Filename:  4.q3_n-fibonacci.cpp
 *
 *    Description: computes nth fibonacci number with using different ways 
 *
 *        Version:  1.0
 *        Created:  05/31/20 17:45:13
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

int get_fibonacci_recursion(int n, int last = 1, int cur = 1);
int get_fibonacci_cycle(int n);


int main()
{
    int n;
        cin >> n;
    
    cout << "Recursion: " << get_fibonacci_recursion(n) << endl;
    cout << "Cycle:     " << get_fibonacci_cycle(n) << endl;

    return 0;
}


int get_fibonacci_recursion(int n, int last, int cur) // last = 1, cur = 1
{
    if (n <= 2)
        return cur;
    return get_fibonacci_recursion(n-1, cur, cur+last);
}

int get_fibonacci_cycle(int n)
{
    int last = 1,
        cur  = 1,
        buf;
    for (int _ = 2; _ < n; _++) {
        buf = cur;
        cur = last + cur;
        last = buf;
    }
    return cur;
}
