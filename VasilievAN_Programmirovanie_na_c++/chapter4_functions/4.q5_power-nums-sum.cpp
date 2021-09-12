/*
 * =====================================================================================
 *
 *       Filename:  4.q5_power-nums-sum.cpp
 *
 *    Description: computes the sum of nums raised to the power 
 *
 *        Version:  1.0
 *        Created:  06/01/20 18:06:48
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

int sum_power_nums(int n);
int sum_power_nums(int n, int power);


int main()
{
    cout << "Sum of first " << 6 << " natural numbers is "
         << sum_power_nums(6) << endl;
    cout << "Sum of first " << 4 << " natural numbers raised to "
         << 2 << " power is " << sum_power_nums(4, 2) << endl;
    return 0;
}


int sum_power_nums(int n)
{
    if (n == 1)                         // if - ещё можно было сделать проверку
        return 1;                       //   на дурочка, но зачем громоздить
    return n + sum_power_nums(n - 1);   //   лишние проверки в таких мелких
}                                       //   программках?

int sum_power_nums(int n, int power)
{
    if (n == 1)
        return 1;
    int n_powered = 1;
    for (int _ = 0; _ < power; _++)     // for - конечно можно подключить
        n_powered *= n;                 //   и cmath, но мы же учимся
    return n_powered + sum_power_nums(n - 1, power);
}
