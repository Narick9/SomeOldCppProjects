/*
 * =====================================================================================
 *
 *       Filename:  7.4_template-overload.cpp
 *
 *    Description:  demonstrates overload func with templates 
 *
 *        Version:  1.0
 *        Created:  06/21/20 18:09:13
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


template< class T >
void show(T thing)
{
   cout << thing << endl;
}

template< class T, class Y >
void show(T a, Y b)
{
   cout << "\t" << a << " " << b << endl;
}


int main()
{
   show('A');
   show(123);
   show("sometext");

   show(321, "sometext");
   show('B', 456);
   show('C', 'D');

   return 0;
}
