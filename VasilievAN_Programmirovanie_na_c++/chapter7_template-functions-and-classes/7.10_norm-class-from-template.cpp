/*
 * =====================================================================================
 *
 *       Filename:  7.10_norm-class-from-template.cpp
 *
 *    Description:  demonstrates a creation of normal class from template class 
 *
 *        Version:  1.0
 *        Created:  06/23/2020 10:38:06 AM
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


template< typename T >
class Base {
   private:
      T value;
   public:
      Base(T _value)     {  set(_value);  }

      void set(T _value) {  value = _value;  }
      T get()            {  return value;  }
};

class Alpha :public Base<int> {
   public:
      Alpha() : Base<int>(0) {}
};

class Bravo :public Base<char> {
   public:
      Bravo(char value) : Base<char>(value) {}
};


int main()
{
   Alpha obj_a;   // ojb_a - не стоит писать (), если нет конструктора с
                  //   аргументами. Язык сочтёт это за копирование конутруктора
                  //   (по крайней мере, g++ выдаёт это за тип Alpha())
      cout << "obj_a: " << obj_a.get() << endl;
      obj_a.set(100);
      cout << "obj_a: " << obj_a.get() << endl;

   Bravo obj_b('B');
      cout << "obj_b: " << obj_b.get() << endl;
      obj_b.set('N');
      cout << "obj_b: " << obj_b.get() << endl;

   return 0;
}
