/*
 * =====================================================================================
 *
 *       Filename:  6.11_parent-variables.cpp
 *
 *    Description:  demonstrates accessibility of base class varibles in 
 *                  descendant class
 *        Version:  1.0
 *        Created:  06/18/20 15:03:03
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
      char alpha;

      Alpha(char _alpha) {
         alpha = _alpha;
      }

      virtual void show() {
         cout << "Alpha: " << alpha << endl;
      }
};
class Bravo {
   public:
      char bravo;

      Bravo(char _bravo) {
         bravo = _bravo;
      }

      virtual void show() {
         cout << "Bravo: " << bravo << endl;
      }
};
class Charlie: public Alpha, public Bravo {
   public:
      Charlie(char _alpha, char _bravo) : Alpha(_alpha), Bravo(_bravo) {
      }  // : - как оказалось, при вызове конструктора базового класса через ::
         //   нельзя отправлять аргументы. Т.е. это скорее интересное
         //   исключение, а не возможность
      void show() {
         cout << "Charlie: " << alpha << bravo << endl;
      }
};


int main()
{
   cout << "   Using variables" << endl;

   Alpha a('A');
   Bravo b('B');
   Charlie c('C', 'D');
      a.show();
      b.show();
      c.show();

   a = c;   // = - здесь переменной базового класса Alpha присваивается начинка
   b = c;   //   класса Charlie. Это законно, т.к. Alpha - один из базовых
            //   классов Charlie. Правда, присавивается не всё подряд, а только
            //   то, что было в самом классе Alpha. Здесь переменной a
            //   записывается только alpha из Charlie
      a.show();   // show() - метод, конечно же, не переносится из производного
      b.show();   //   класса, а используется свой

   cout << "   Using pointers" << endl;

   Alpha *p_a   = &c;   // * - с указателями связана одна особенность.
   Bravo *p_b   = &c;   //   Указатель на класс Alpha здесь также может видеть
   Charlie *p_c = &c;   //   поля и методы только от класса Alpha, но если
      p_a->show();      //   метод в этом классе виртуальный, и есть
      p_b->show();      //   переопределённая версия в производном классе, то
      p_c->show();      //   вызываться будет именно она. Всё правильно, т.к.
                        //   указатель сам по себе ничего не хранит. Он знает
   return 0;            //   из чего состоит класс Alpha, поэтому и берёт всё,
}                       //   что должно там быть из класса Charlie. Оператором
                        //   расширения контекста мы можем получить
                        //   оригинальную версию метода: p_a->Alpha::show();
                        //   Ведь нет ничего незаконного в том, чтобы уточнять
                        //   через указатель на Alpha то, что мы хотим получить
                        //   поле или метод класса Alpha
