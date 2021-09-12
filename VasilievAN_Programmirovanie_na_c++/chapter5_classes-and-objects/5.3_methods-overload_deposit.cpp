/*
 * =====================================================================================
 *
 *       Filename:  5.3_methods-overload_deposit.cpp
 *
 *    Description:  computes deposit with using class 
 *
 *        Version:  1.0
 *        Created:  06/04/20 22:36:41
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
        void show() {
            cout << "Name:           " << name << endl;
            cout << "Money:          " << money << endl;
            cout << "Rate (%):       " << rate << endl;
            cout << "Period (years): " << time << endl;
            cout << "Total account:  " << get_money() << endl;
        }
        void set(string _name, double _money, double _rate, int _time) {
            name = _name;
            money = _money;
            rate = _rate;
            time = _time;
        }
        void set(double _money, double _rate, int _time) {
            money = _money;
            rate = _rate;
            time = _time;
        }
        void set(string _name) {
            name = _name;
        }
        void set(int _time) {
            time = _time;
        }
        void set(double _money, double _rate) {
            money = _money;
            rate = _rate;
        }
        void set(double x, bool is_money = true) {
            if (is_money)
                money = x;
            else
                rate = x;
        }
};


int main()
{
    BankAccount my_acc;

    my_acc.set("Muslimov Arthur", 1500, 9, 6);
        my_acc.show();
        cout << endl;
    my_acc.set("Tosya");
        my_acc.show();
        cout << endl;
    my_acc.set(10);
        my_acc.show();
        cout << endl;
    my_acc.set(2200.0);
        my_acc.show();
        cout << endl;
    my_acc.set(2500, true);
        my_acc.show();
        cout << endl;
    my_acc.set(12, false);
        my_acc.show();
        cout << endl;
    my_acc.set(2700, 14, 5);
        my_acc.show();
        cout << endl;

    return 0;
}
