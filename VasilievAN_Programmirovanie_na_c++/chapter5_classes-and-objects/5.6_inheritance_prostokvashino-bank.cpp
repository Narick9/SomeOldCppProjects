/*
 * =====================================================================================
 *
 *       Filename:  5.6_inheritance_acquaintance.cpp
 *
 *    Description:  demonstrate class inheritance working 
 *
 *        Version:  1.0
 *        Created:  06/07/20 13:45:43
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstring>
using namespace std;

///////////////////////////////////////////////////////////////////////////////
class Test {            // Test - этот класс я создал специально для
    int n;      // 4    //   демонстрации некоторых особенностей
    char c[2];  // 4    // 4 - столько байт занимает переменная. Почему здесь
};                      //   char тоже занимает 4? Дело в том, что машинное у
                        //   меня, как и почти везде, занимает 32 бита. Это
                        //   значит, что, если класс набрал, допустим, 6 байт,
                        //   то займёт он все 8, чтобы было кратно 4. Но, если
                        //   твой класс (или структура) хранит переменные
                        //   одного типа, то sizeof() покажет, что добора до
                        //   конечного слова не будет. Может это потому что
                        //   в памяти они расположены сразу друг за другом, как
                        //   при массиве, и это даёт комплятору возможность
                        //   записи прямо за ними другое переменные для
                        //   экономии памяти. Ну, как минимум так делает gcc
                        // = 3 - да, можно задавать значения по умолчанию прямо
                        //   в классе
class TestMode: Test {};// TestMode - класс для демонстрации нюансов
                        //   наследования. Например, можно не задавать
                        //   идентефикатор типа наследования, и перенимаемая
                        //   начинка будет перенесена как private
///////////////////////////////////////////////////////////////////////////////
class BankAccount {
    public:
        string name;    // 32 total 48  // total - столько байт занимает класс
        //char name[10];// 10 total 24  //   при хранении этого элемента. Как
        float money;    // 4            //   оказалось, string без текста уже
        float rate;     // 4            //   со старта занимает 32 байта, но,
        int time;       // 4            //   насколько мне известно, если текс
        float get_money() {             //   в нём перерастает эту отметку, то
            float cur = money;          //   он можешь расширятся
            for (int _ = 0; _ < time; _++)
                cur *= (1 + rate/(100));
            return cur;
        }
        BankAccount() {
            set("", 0, 0, 0);
        }
        BankAccount(string _name, float _money, float _rate, int _time) {
            set(_name, _money, _rate, _time);
        }
        void set(string _name, float _money, float _rate, int _time) {
            name = _name;
            money = _money;
            rate = _rate;
            time = _time;
        }
        void show() {
            cout << "Name:           " << name << endl;
            cout << "Money:          " << money << endl;
            cout << "Rate (%):       " << rate << endl;
            cout << "Period (years): " << time << endl;
            cout << "Total amount:   " << get_money() << endl;
        }
};
class BankAccountMode: public BankAccount { // public - это значит, что мы
    public:                                 //   перенимаем все члены
        int year_pays;                      //   с другого класса, называемого
        float get_money() {                 //   родительским (ну или базовым).
            float cur = money;              //   члены переносятся как открытые
            for (int _ = 0; _ < time*year_pays; _++)
                cur *= (1 + rate/(100*year_pays));
            return cur;
        }
        BankAccountMode(): BankAccount() {
            year_pays = 0;
        }   // : - так вызывается конструктор базового класса. Специфика вызова
            //   конструктора базового класса такова, что надо явно указывать
            //   его имя. Остальные методы довольствуются другим способом.
            //   Стоит ещё отметить, что методы по умолчанию видят начинку
            //   только своего класса. Здесь конструктор BankAccount базового
            //   класса вызывает метод set с четырьмя аргументами из своего
            //   класса, а не переопределённую версию отсюда
        BankAccountMode(string _name, float _money, float _rate, int _time,
                        int _year_pays=1):
                        BankAccount(_name, _money, _rate, _time) {
            year_pays = _year_pays;
        }
        void set(string _name, float _money, float _rate, int _time,
                int _year_pays) {
            BankAccount::set(_name, _money, _rate, _time);
            year_pays = _year_pays; // :: - так мы можем вызвать метод одного
        }                           //   из родительских классов. Это прозвали
                                    //   оператором расширения контекста. С
                                    //   помощью него можно также вызывать и
                                    //   конструкторы, только для них не надо
                                    //   перед оператором писать имя класса.
                                    //   Здесь это может выглядить так:
                                    //   ::BankAccount();
                                    //   Поправка: при таком вызове в классе
                                    //   обязательно должен быть конструктор
                                    //   без параметров. Да, удивительно, но
                                    //   без него нельзя обойтись
                                    // set - Здесь мы описали метод set с пятью
                                    //   аргументами, а в базовом классе был
                                    //   метод set с четырьмя. Может сложиться
                                    //   впечатление, что это перегрузка, но
                                    //   на самом деле здесь тоже происходит
                                    //   перекрываение. set из базового класса
                                    //   без оператора расширения не получить
        void show() {
            cout << "Name:              " << name << endl;
            cout << "Money:             " << money << endl;
            cout << "Rate (%):          " << rate << endl;
            cout << "Payments per year: " << year_pays << endl;
            cout << "Period (years):    " << time << endl;
            cout << "Total amount:      " << get_money() << endl;
        }
};


int main()
{
    BankAccount matroskin("Кот Матроскин", 1200, 8, 5);
        matroskin.show();
        cout << endl;
    BankAccountMode fedor("Дядя Федор", 1000, 7, 6, 2);
        fedor.show();
        cout << endl;
    BankAccountMode sharik("Пёс Шарик", 1500, 6, 8);
        sharik.show();
        cout << endl;
    BankAccountMode pechkin;
        pechkin.set("Почтальон Печкин", 800, 10, 3, 4);
        pechkin.show();
///////////////////////////////////////////////////////////////////////////////
    cout << "/////////////////////////////////////////" << endl;
    BankAccountMode test("m", 1, 2, 3, 4);
        test.show();                // show() - версия show() из класса-потомка
        test.BankAccount::show();   // ::show() - версия из базового
        cout << "size:      " << sizeof(BankAccount) << endl;
        cout << "size mode: " << sizeof(BankAccountMode) << endl;
                    // sizeof() - вывод потребления родительского класса и
                    //   класса-потомка. В классе потомка есть дополнительное
                    //   поле int, но при этом класс занимает те же 48 байт.
                    //   Это довольно странно, и я не знаю к чему бы это. При
                    //   добавлении ещё одно int в классе-потомке sizeof выдал
                    //   даже 56, т.е. класс прибавил в весе 8 байт
    cout << "-----------------------------------------" << endl;
///////////////////////////////////////////////////////////////////////////////
    Test nt;
        cout << "size nt: " << sizeof(nt) << endl;   // sizeof - выдаёт 8
    TestMode tm;
        cout << "size tm: " << sizeof(tm) << endl;   // sizeof - выдаёт те же 8,
                                                     //   хотя в книге пишется,
                                                     //   что private-члены
                                                     //   не наследуются вообще 
    cout << "size string: " << sizeof(string) << endl;  // sizeof - выдаёт 32
    return 0;
///////////////////////////////////////////////////////////////////////////////
}
