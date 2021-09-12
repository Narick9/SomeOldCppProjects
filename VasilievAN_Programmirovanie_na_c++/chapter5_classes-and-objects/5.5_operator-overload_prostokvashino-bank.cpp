/*
 * =====================================================================================
 *
 *       Filename:  5.5_operator-overload_prostokvashino-bank.cpp
 *
 *    Description:  demonstrates working of operators methods and functions 
 *
 *        Version:  1.0
 *        Created:  06/05/20 19:02:57
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
        float money;
        float rate;
        int time;
        BankAccount() {
            name = "";
            money = 0;
            rate = 0;
            time = 0;
        }
        BankAccount(string _name, float _money, float _rate, int _time) {
            set(_name, _money, _rate, _time);
        }   // ~ - деструктор по умолчанию видимо тоже есть
        void set(string _name, float _money, float _rate, int _time) {
            name = _name;
            money = _money;
            rate = _rate;
            time = _time;
        }
        void show() {
            cout << "Name:           " << name << endl;
            cout << "Money:          " << money << endl;
            cout << "Rate:           " << rate << endl;
            cout << "Period (years): " << time << endl;
            cout << "Total amount:   " << get_money() << endl;
            cout << "-------------------------" << endl;
        }
        float get_money() {
            float cur = money;
            for (int _ = 0; _ < time; _++)
                cur *= (1 + rate/100);
            return cur;
        }
        BankAccount operator++() {  // operator - это операторный метод. Он
            money = money + 1000;   //   даёт возмножость делать правила для
            return *this;           //   операторов. Оператор - это +, - и т.д.
        }                           //   В остальном он писывается также, как
                                    //   любой другой метод. Здесь, например,
                                    //   мы сделали правило для префиксной
                                    //   формы оператора инкремента. Это
                                    //   значит, что если компьютер увидит
                                    //   запись BankAccount++, то заработает
                                    //   этот метод для операнда BankAccount.
                                    //   операторы настраивать можно только для
                                    //   классов. Формально, это, видимо,
                                    //   модифицированная фукнция, т.к. автор
                                    //   говорит о задании оператора, как о
                                    //   перегрузке operator
        BankAccount operator++(int unused) {    // unused - так выглядит
            time++;                             //   разница между префиксной
            return *this;                       //   и постфиксной формой (для
        }                                       //   постфиксной формы
                                                //   объявляется формальный не
                                                //   используемый int, который
                                                //   хранит нуль)
        BankAccount operator+(BankAccount right) {  // + - одним операндом дело
            BankAccount ans;                        //   не ограничивается, и
            ans.name = "Почтальон Печкин";          //   это очень хорошо
            ans.money = money + right.money;    // ans - в принципе тут можно
                                                //   было просто передалать уже
                                                //   имеющийся right
            ans.rate = (rate > right.rate) ? rate : right.rate;
            ans.time = (int)(time + right.time)/2;
            return ans;                         // ?: - это тернарный оператор
        }                                       //   (ещё есть унарные когда
};                                              //   операнд один, и бинарные,
                                                //   когда операнда два).
                                                //   Другого такого в си нет
                                                // (int) - это пометка о том,
                                                //   что мы вкурсе, что здесь
                                                //   остаток от деления
                                                //   обрубается
float operator - (BankAccount left, BankAccount right)  //. - . - да, так можно
{                                               // {} - а это операторная
    return left.get_money() - right.get_money();//   функция. Отличается тем,
}                                               //   что .. это функция, и тем,
                                                //   что принимает минимум один
                                                //   операнд. В методе за него
                                                //   считался сам объект, а тут
                                                //   это аргумент. Если комп
                                                //   увидит запись
                                                //   BankAccount - BankAccount,
                                                //   то вызовет эту функцию и
                                                //   подставит её результат
                                                //   вместо записи. И ещё - не
                                                //   стоит делать аналогичный
                                                //   метод и функцию, т.к. это
                                                //   вызовет ошибку
                                                //   неопределённости
BankAccount operator -- (BankAccount &obj)  // .. -- .. - для разнообразия
{                                           //   периодически я буду напоминать
    if (obj.money > 1000)                   //   о таких возможностях
        obj.money -= 1000;                  // & - да, объект разрешается брать
    else                                    //   по ссылке. Ещё я пробовал
        obj.money = 0;                      //   получить указатель, но g++
    return obj;                             //   требовал именно тип класса
}

BankAccount operator--(BankAccount &obj, int)   // int - да, аргументы даже
{                                               //   называть не обязательно
    obj.time--;
    if (obj.time < 0)
        obj.time = 0;
    return obj;
}


int main()
{
    BankAccount matroskin("Кот Матроскин", 1200, 7, 1);
        matroskin.show();
    matroskin--;            // уменьшаем year
        matroskin.show();
    matroskin--;            // уменьшаем year
        matroskin.show();
    matroskin++;            // увеличиваем year
        matroskin.show();
    --matroskin;            // уменьшаем money
        matroskin.show();
    --matroskin;            // уменьшаем money
        matroskin.show();
    ++matroskin;            // увеличиваем money
        matroskin.show();

    BankAccount sharik("Пёс Шарик", 1100, 8, 5);
        sharik.show();
    BankAccount pechkin;
        pechkin = matroskin + sharik;   // компонуем счета
        pechkin.show();     // pechkin - тут можно было обойтись и без явной
                            //   инициализации дополнительной переменной,
                            //   восьпозловавшись возмножостями великого и
                            //   ужасного: (matroskin + sharik).show();
    cout << pechkin.name << " will receive more income than " << sharik.name
         << " for " << pechkin - sharik << endl;    // находим разницу в доходах
    
    return 0;
}
