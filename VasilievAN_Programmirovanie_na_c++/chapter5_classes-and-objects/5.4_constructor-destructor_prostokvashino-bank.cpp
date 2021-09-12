/*
 * =====================================================================================
 *
 *       Filename:  5.4_constructor-destructor_prostokvashino-bank.cpp
 *
 *    Description:  demonstrates working of constructor and desctructor 
 *
 *        Version:  1.0
 *        Created:  06/05/20 16:58:00
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Arthur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

class BankAccount {
    private:
        string name;
        float money;
        float rate;
        int time;
        float get_money() {
            float cur = money;
            for (int _ = 0; _ < time; _++)
                cur *= (1 + rate/100);
            return cur;
        }
    public:
        BankAccount(string _name, float _money, float _rate, int _time) {
            set(_name, _money, _rate, _time);   // BankAccount() - конструкторам
                                                //   и деструкторам не нужен
                                                //   возвращаемы тип, т.к.
                                                //   возвращать им нечего
                                                // set() - да, функция
                                                //   объявлена ниже
            cout << "A new bank account has been created:" << endl;
                show();
        }
        BankAccount() {             // BankAccount() - да, конструктор можно
            name = "Кот матроскин"; //   перегружать
            money = 100;
            rate = 5;
            time = 1;
            cout << "A new bank account has been created:" << endl;
                show();
        }       // BankAccount() - стоит ещё сказать, что даже если в классе
                //   нет никакого конструктора, на самом деле он есть. Зовётся
                //   он конструктором по умолчанию. Он ничего не делает, просто
                //   существует как необходимость для языка. Если появляется
                //   пользовательский конструктор, то конструктор по умолчанию
                //   становится недоступен
        ~BankAccount() {    // ~ - деструктор вызывается при удалении объекта
                            //   из памяти, т.е. при заканчивании функции, если
                            //   объект локальный, или при delete. Ещё он не
                            //   может быть перегружен и не принимает аргументов
            cout << "\"" << name << "\" has been deleted" << endl;
            cout << "*************************" << endl;
        }
        void show() {
            cout << "Name:           " << name << endl;
            cout << "Money:          " << money << endl;
            cout << "Rate (%):       " << rate << endl;
            cout << "Period (years): " << time << endl;
            cout << "Total account:  " << get_money() << endl;
            cout << "-------------------------" << endl;
        }
        void set(string _name, float _money, float _rate, int _time) {
            name = _name;
            money = _money;
            rate = _rate;
            time = _time;
        }
};


void BankAccount_postman()
{
    BankAccount pechkin("Почтальон Печкин", 200, 3, 2);
}


int main()
{
    BankAccount matroskin;  // matroskin - интересно, что при добавлении ()
                            //   ничего не происходит. Т.е. совсем, хотя можно
                            //   было предположить, что так вызывается одна из
                            //   версий конструктора
    BankAccount fedor("Дядя Фёдор", 1500, 8, 7);
    BankAccount_postman();
    BankAccount *p_sharik = new BankAccount("Пёс Шарик", 1200, 6, 9);
        cout << "All objects have been created" << endl;    // new - вот это
                                                            //   уже не похоже
                                                            //   на malloc()
    delete p_sharik;
    cout << "Program has been completed" << endl << endl;
    return 0;
}           // {} - также интересно, что локальные переменный удаляются в
            //   обратном порядке, т.е. то, что было создано последним,
            //   удаляется первым. По выводу деструкторов видно, что последним
            //   память покинул Матроскин
