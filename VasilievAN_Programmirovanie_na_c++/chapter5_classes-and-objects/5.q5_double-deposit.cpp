/*
 * =====================================================================================
 *
 *       Filename:  5.1_class_acquaintance.cpp
 *
 *    Description:  describes Bank with class. This is modified 5.1 issue
 *                  with the ability to store your deposit in two parts
 *
 *        Version:  1.0
 *        Created:  06/13/20 15:56:15
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    public:
        string name;
        int time;
        float money1;
        float money2;
        float rate1;
        float rate2;
        BankAccount(string _name, int _time, float _money1, float _rate1,
                                             float _money2, float _rate2) {
            name   = _name;
            time   = _time;
            money1 = _money1;
            money2 = _money2;
            rate1  = _rate1;
            rate2  = _rate2;
        }
//      --------------------------------------------------------------
        float get_money() {
            float cur1 = money1;
            float cur2 = money2;
            for (int _ = 0; _ < time; _++) {
                cur1 *= (1 + rate1/100);
                cur2 *= (1 + rate2/100);
            }
            return cur1 + cur2;
        }
        void print_describe() {
            cout << "Name                 " << name << endl;
            cout << "Period (years)       " << time << endl;
            cout << "Deposit (1st part)   " << money1 << endl;
            cout << "Rate (1st part) (%)  " << rate1 << endl;
            cout << "Deposit (2st part)   " << money2 << endl;
            cout << "Rate (2nd part) (%)  " << rate2 << endl;
            cout << "Total amount         " << get_money() << endl;
        }
};


int main()
{
    BankAccount my_account("Muslimov Arthur", 6, 1500., 9., 1200., 13.);

    my_account.print_describe();

    return 0;
}
