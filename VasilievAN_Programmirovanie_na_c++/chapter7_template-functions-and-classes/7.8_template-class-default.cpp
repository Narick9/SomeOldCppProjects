/*
 * =====================================================================================
 *
 *       Filename:  7.8_template-class-default.cpp
 *
 *    Description:  demonstrate default template class parameters
 *
 *        Version:  1.0
 *        Created:  06/21/20 23:12:55
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


template< typename T=int, typename Y=char >  // = - здесь такая же логика, как
class MyClass {                              //   и у параметров по умолчанию
   public:                                   //   у функций: т.е. сначала
      T fst;                                 //   должны идти обычные параметры
      Y snd;                                 //   , и уже после них идут те,
                                             //   у кого есть значения по
      MyClass(T _fst, Y _snd) {              //   по умолчанию
         fst = _fst;
         snd = _snd;
      }

      void print() {
         cout << fst << "  " << snd << endl;
      }
};


int main()
{
   MyClass<double,int> obj_1(3.5, 100);
   MyClass<string> obj_2("text", 'A');
   MyClass<> obj_3(200, 'B'); // <> - это неизменное бремя всех шаблонных
                              //   классов
   obj_1.print();
   obj_2.print();
   obj_3.print();

   return 0;
}
