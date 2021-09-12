/*
 * =====================================================================================
 *
 *       Filename:  4.3_default-params_deposit.cpp
 *
 *    Description: computes deposit with function with default parameters 
 *
 *        Version:  1.0
 *        Created:  05/28/20 22:53:18
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

double get_money(double _money, double _rate,
                 int _for_years = 1,    // = - как оказалось, значения по
                 int _per_year  = 1);   //     умолчанию должны задаваться в
                                        //     объявлении функции. Если их
                                        //     написать ещё и в определении,
                                        //     то компилятор тебя обругает
                                    // Ещё стоит сказать, что функции с
                                    // аргументами по умолчанию также легко
                                    // перегружаются, но стоит быть аккуратным,
                                    // чтобы всегда можно было однозначно
                                    // определить какую именно версию ты
                                    // вызываешь
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


double get_money(double _money, double _rate,
                 int _for_years, // = 1
                 int _per_year)  // = 1
{
    for (int _ = 0; _ < _for_years * _per_year; _++)
        _money *= (1 + _rate/100/_per_year);
    return _money;
}
