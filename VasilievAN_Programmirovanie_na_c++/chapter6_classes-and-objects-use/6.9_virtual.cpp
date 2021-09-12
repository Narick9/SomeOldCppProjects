/*
 * =====================================================================================
 *
 *       Filename:  6.8_non-virtual.cpp
 *
 *    Description:  demonstrates non virtual method 
 *
 *        Version:  1.0
 *        Created:  06/17/20 21:28:46
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

class Alpha {
   public:
      virtual void print() {  // virtual - теперь, если этот метод будет вызван
         puts("Alpha class"); //   в других методах этого класса из
      }                       //   производного класса, где будет своя версия,
                              //   будет вызвана именно своя версия.
                              //   Переопределяемые методы обычно объявляются
                              //   виртуальными
      void print_all() { 
         print(); // print() - при вызове метода print_all() из класса Bravo
      }           //   метод print() будет вызван тоже оттуда, т.к. версия
};                //   этого метода из этого класса - виртуальная
class Bravo :public Alpha {
   public:
      void print() {
         puts("Bravo class");
      }
};


int main()
{
   Bravo obj;

   obj.print();
   obj.print_all();

   return 0;
}
