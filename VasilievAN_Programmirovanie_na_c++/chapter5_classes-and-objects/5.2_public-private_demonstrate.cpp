/*
 * =====================================================================================
 *
 *       Filename:  5.2_public-private_demonstrate.cpp
 *
 *    Description: demonstrates using public and private access specifier 
 *
 *        Version:  1.0
 *        Created:  06/04/20 21:47:43
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
    private:
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
    public:
        void set_all(string _name, double _money, double _rate, int _time) {
            name = _name;
            money = _money;
            rate = _rate;
            time = _time;
        }
        void show_all() {
            cout << "Name:            " << name << endl;
            cout << "Deposit:         " << money << endl;
            cout << "Rate (%):        " << rate << endl;
            cout << "Period (years):  " << time << endl;
            cout << "Total account:   " << get_money() << endl;
        }
};


int main()
{
    BankAccount my_acc, musya_acc;
        my_acc.set_all("Muslimov Arthur", 1500, 9, 6);
        musya_acc.set_all("Musya", 25000, 2, 8);

    my_acc.show_all();
        cout << endl;
    musya_acc.show_all();

    return 0;
}
