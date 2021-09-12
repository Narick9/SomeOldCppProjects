/*
 * =====================================================================================
 *
 *       Filename:  4.4_recursion_deposit.cpp
 *
 *    Description: computes deposit with a recursion function 
 *
 *        Version:  1.0
 *        Created:  05/29/20 16:09:04
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

double get_money(double _money, double _rate, int _for_years);


int main()
{
    double money = 1000,
           rate  = 5;
        cout << "Contibution: " << money << endl;
        cout << "Rate:        " << rate << endl;

    cout << "Account in a year:   " << get_money(money, rate, 1) << endl;
    cout << "Account in 7 years:  " << get_money(money, rate, 7) << endl;
    cout << "Account in 10 years: " << get_money(money, rate, 10) << endl;

    return 0;
}


double get_money(double _money, double _rate, int _for_years)
{
    if (_for_years == 0)    // == - да, тут нет проверки на отрицательный year
        return _money;
    return (1 + _rate/100) * get_money(_money, _rate, _for_years-1);
}
