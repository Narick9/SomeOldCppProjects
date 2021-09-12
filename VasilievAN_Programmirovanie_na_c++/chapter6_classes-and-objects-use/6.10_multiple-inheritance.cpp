/*
 * =====================================================================================
 *
 *       Filename:  6.10_multiple-inheritance.cpp
 *
 *    Description:  demonstrates multiple inheritance in classes
 *
 *        Version:  1.0
 *        Created:  06/17/20 22:23:15
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
      int alpha;

      Alpha(int a) {
         alpha = a;
      }

      void show() {
         cout << "Alpha: " << alpha << endl;
      }
};
class Bravo {
   public:
      int bravo;

      Bravo(int b) {
         bravo = b;
      }

      void show() {
         cout << "Bravo: " << bravo << endl;
      }
};
class Charlie: public Alpha, public Bravo {
   public:
      int charlie;

      Charlie(int a, int b, int c) : Alpha(a), Bravo(b) {
         charlie = c;
      }

      void show() {
         Alpha::show(); // :: - напоминаю, что это зовётся оператором
         Bravo::show(); //   расширения контекста
         cout << "Charlie: " << charlie << endl;
      }
};


int main()
{
   Charlie obj(10, 20, 30);

   obj.show();

   return 0;
}
