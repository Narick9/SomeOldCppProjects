/*
 * =====================================================================================
 *
 *       Filename:  7.9_template-class-inheritance.cpp
 *
 *    Description:  demonstrates temlate classes inheritance 
 *
 *        Version:  1.0
 *        Created:  22.06.2020 20:04:57
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

template< typename A >
class Alpha {
   public:
      A alpha;
   
      Alpha(A _alpha) {
         alpha = _alpha;
      }

      void print() {
         cout << "Alpha: " << alpha << endl;
      }
};

template< typename B >
class Bravo {
   public:
      B bravo;

      Bravo(B _bravo) {
         bravo = _bravo;
      };

      void print() {
         cout << "Bravo: "<< bravo << endl;
      }
};

template< typename A, typename B, typename C >
class Charlie: public Alpha<A>, public Bravo<B> {  // <A> - ведь нужно знать
   public:                                         //   сколько памяти занимать
      C charlie;

      Charlie(A alpha, B bravo, C _charlie) : Alpha<A>(alpha), Bravo<B>(bravo) {
         charlie = _charlie;  // <A> - ведь нужно знать какой из новосозданных
      }                       //   в компиляторе классов нужно использовать

      void print() {
         Alpha<A>::print();
         Bravo<B>::print();
         cout << "Charlie: " << charlie << endl;
      }
};


int main()
{
   Charlie<string,char,int> obj_1("sometext", 'A', 100);
   Charlie<int,double,char> obj_2(200, 5.5, 'B');

   obj_1.print();
   obj_2.print();

   return 0;
}
