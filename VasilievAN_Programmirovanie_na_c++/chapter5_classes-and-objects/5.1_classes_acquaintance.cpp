/*
 * =====================================================================================
 *
 *       Filename:  5.1_class_acquaintance.cpp
 *
 *    Description:  demonstrates class work 
 *
 *        Version:  1.0
 *        Created:  06/04/20 21:21:17
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
        double money;
        double rate;
        int time;

        double get_money() {
            double cur = money;
            for (int _ = 0; _ < time; _++)
                cur *= (1 + rate/100);
            return cur;
        }

        void show() {
            cout << "Name:           " << name << endl;
            cout << "Deposit:        " << money << endl;
            cout << "Rate (%):       " << rate << endl;
            cout << "Period (years): " << time << endl;
            cout << "Total amount:   " << get_money() << endl;
        }
};


int main()
{
    BankAccount my_account;
        my_account.name  = "Muslimov Arthur";
        my_account.money = 1500;
        my_account.rate  = 9;
        my_account.time  = 6;

    my_account.show();

    return 0;
}
