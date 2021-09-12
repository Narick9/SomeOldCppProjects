/*
 * =====================================================================================
 *
 *       Filename:  6.7_private-inheritance.cpp
 *
 *    Description:  demonstrates a inheritance of private class member 
 *
 *        Version:  1.0
 *        Created:  06/17/20 18:37:11
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
   private:
      char c;
   public:
      Alpha(char _c) {
         c = _c;
      }

      void print_alpha() {
         cout << "Alpha: " << c << endl;
      }
      void set_c(char _c) {
         c = _c;
      }
};
class Bravo :public Alpha {   // public - в базовом классе есть приватное поле.
   public:                    //   Автор назвал его "ненаследуемым", т.е. его
      int num;                //   нельзя пощупать в этом классе, но к нему
                              //   можно обратиться ненапрямую
      Bravo(char c, int _num) : Alpha(c) {
         num = _num;
      }

      void print_bravo() {
         print_alpha();
         cout << "Bravo: " << num << endl;
      }
};


int main()
{
   Bravo obj('A', 100);
      obj.print_bravo();

   obj.set_c   ('Z'  )                       ;
      obj  .  print_bravo();

   return
      0;
}
