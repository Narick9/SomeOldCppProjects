/*
 * =====================================================================================
 *
 *       Filename:  8.1_structures.cpp
 *
 *    Description:  demonstrates using of structures 
 *
 *        Version:  1.0
 *        Created:  06/29/2020 06:57:13 PM
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


struct MyMoney {  // struct - здесь это тот же класс, но с public по умолчанию.
    string name;  //   В отличие от структур из Си, может хранить методы. Ещё
    double money; //   интересное отличие от классов - это возможность задавать
    double rate;  //   полям значения в стиле массивов: MyMoney = { "st", 1, ..
    int time;     //   Скорее всего оставили для совместимости с Си
};
double get_money(MyMoney obj)
{
   double ans = obj.money;
   for (int _ = 0; _ < obj.time; _++) {
      ans *= (1 + obj.rate/100);
   }
   return ans;
}
void show(MyMoney obj)
{
   cout << "Name:         " << obj.name << endl;
   cout << "Money:        " << obj.money << endl;
   cout << "Rate (%):     " << obj.rate << endl;
   cout << "Time (years): " << obj.time << endl;
   cout << "Total amount: " << get_money(obj) << endl;
}



int main()
{
   MyMoney matroskin = { "Кот Матроскин", 1000, 8, 5 };
   MyMoney sharik = { "Пёс Шарик", 1200, 7, 4 };

   show(matroskin);
   cout << endl;
   show(sharik);

   return 0;
}
