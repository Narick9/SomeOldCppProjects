/*
 * =====================================================================================
 *
 *       Filename:  4.2_func-overload_deposit.cpp
 *
 *    Description: computes deposit with overloading functions 
 *
 *        Version:  1.0
 *        Created:  05/28/20 21:19:25
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

double get_money(double _money, double _rate);
double get_money(double _money, double _rate, int _for_years);
double get_money(double _money, double _rate, int _for_years, int _per_years);

/* Использование перегрузки функции не очень эффективно в плане потребления
 * памяти, т.к. фактически в готовом исполняемом файле для каждой из версии
 * функции будет выделена память именно как для отдельной функции. На самом
 * деле это довольно очевидно, ведь функции технически совершенно разные.
 * Здесь можно было обойтись функцией с параметрами по умолчанию, но
 * демнострируется здесь именно перегрузка
 */

int main()
{
    double money = 1000,
           rate  = 5;
        cout << "Contibution: " << money << endl;
        cout << "Rate:        " << rate << endl;

    cout << "Account in a year: " << get_money(money, rate) << endl;
    cout << "Account in 7 years: " << get_money(money, rate, 7) << endl;
    cout << "Account in 7 years with accrual 3 times a year: "
         << get_money(money, rate, 7, 3) << endl;

    return 0;
}


double get_money(double _money, double _rate)
{
    return _money * (1 + _rate/100);
}

double get_money(double _money, double _rate, int _for_years)
{
    for (int _ = 0; _ < _for_years; _++)
        _money *= (1 + _rate/100);      // () - на самом деле тут необязательноj
    return _money;                      //      их использовать, всё равно
}                                       //      первым будет считаться то, что
                                        //      после *=

double get_money(double _money, double _rate, int _for_years, int _per_year)
{
    return get_money(_money, _rate/_per_year, _for_years*_per_year);
}
