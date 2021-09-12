/*
 * =====================================================================================
 *
 *       Filename:  7.6_template-class.cpp
 *
 *    Description:  demonstrates a template class 
 *
 *        Version:  1.0
 *        Created:  06/21/20 21:49:21
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


template < typename T, typename Y >
class MyClass {
   public:
      T fst;
      Y snd;

      MyClass(T _fst, Y _snd) {
         fst = _fst;
         snd = _snd;
      }

      void print() {
         cout << "first   " << fst << endl;
         cout << "second  " << snd << endl;
      }
};


int main()
{
   MyClass<int,char> ic_obj(100, 'A');
   MyClass<string,double> sd_obj("sometext", 10.5);
   MyClass<char*,string> cps_obj((char*)"first", "second");
   MyClass<int,int> ii_obj(1, 2);

   ic_obj.print();
   sd_obj.print();
   cps_obj.print();
   ii_obj.print();

   return 0;
}
