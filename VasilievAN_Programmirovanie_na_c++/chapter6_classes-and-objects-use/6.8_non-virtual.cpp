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
      void print() {
         puts("Alpha class");
      }
      void print_all() {
         print();
      }
};
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
