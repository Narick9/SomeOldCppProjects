/*
 * =====================================================================================
 *
 *       Filename:  8.10_map.cpp
 *
 *    Description:  demonsrates using of map
 *
 *        Version:  1.0
 *        Created:  07/01/2020 02:32:25 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <utility>   // utility - здесь хранится класс pair, который нужен для
#include <map>       //   хранения пар. Описание чуть ниже
using namespace std;


int main()
{
   const int size = 5;

   map<string,int> mp_nums;   // map - так выглядит местный ассоциативный
                              //   контейнер
   string names[size] = { "один", "два", "три", "четыре", "пять" };
   int nums[size] = { 1, 2, 3, 4, 5 };

   for (int i = 0; i < size; i++) {
      mp_nums.insert( pair<string,int>(names[i], nums[i]) );
   }  // insert - так мы можем добавлять новую пару ключ-значение в наш map.
      //   Пользуется map объектами класса pair, дла которого была подключенён
      //   отдельный header <utility>. Как ты видишь, контейнеры из стандартной
      //   библиотеки пользуются схожими методами, решающими схожие задачи
   mp_nums.insert( pair<string,int>("шесть", 6) );
   mp_nums.erase("три");   // erase - (англ. удалить)

   map<string,int>::iterator it = mp_nums.begin();
   while (it != mp_nums.end()) {
      cout << it->first << "\t: " << (*it).second << endl;
      it++;    // -> - да, здесь полная имитация указателя
   }
   cout << "Единица - " << mp_nums["один"] << endl;
   cout << "Двойка  - " << mp_nums.at("два") << endl;
         // at() - это то же, что и скобки, но с функцией
   return 0;
}
