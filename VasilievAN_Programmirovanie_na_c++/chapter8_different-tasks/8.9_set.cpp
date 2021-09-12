/*
 * =====================================================================================
 *
 *       Filename:  8.9_set.cpp
 *
 *    Description:  demonstrates using of set 
 *
 *        Version:  1.0
 *        Created:  06/30/2020 10:37:47 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdlib>
#include <set>
using namespace std;


int main()
{
   srand(23);

   int size;
   cout << "number of unique symbols: ";
   cin >> size;

   set<char> symbs;  // set - как и в Python, set - это штука, где нет
                     //   повторяющихся элементов. И ещё не важен их порядок
   char new_s;
   int counter = 0;
   while (symbs.size() < size) {
      new_s = 'a' + rand() % 26;
      cout << new_s << " ";
      symbs.insert(new_s);    // insert - если мы попытаемся сунуть то, что уже
      counter++;              //   есть во множестве, то метод просто
   }                          //   проигнорирует это.
   cout << endl << "have been generated: " << counter << endl;

   cout << "unique symbols: " << endl;
   set<char>::iterator it;
   for (it = symbs.begin(); it != symbs.end(); it++) {
      cout << *it << " ";  // it - т.к. элементы во множестве неупорядоченны,
   }                       //   сказать, какой элемент первый, а какой
   cout << endl;           //   последний нельзя. Важно то, что какой-то из них
                           //   - первый, а какой-то - последний. Метод end()
   return 0;               //   по прежнему выдаст итератор на область памяти
}                          //   за последним элементом. По выхлопу можно
                           //   заметить, что символы выдаются в алфавитном
                           //   порядке, что довольно интересно
