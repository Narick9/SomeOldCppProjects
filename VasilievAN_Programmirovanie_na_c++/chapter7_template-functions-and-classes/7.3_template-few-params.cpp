/*
 * =====================================================================================
 *
 *       Filename:  7.3_template-few-params.cpp
 *
 *    Description:  demonstrates template func with few parameters 
 *
 *        Version:  1.0
 *        Created:  06/20/20 20:47:37
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


template< typename T, typename Y >  // T, Y - это этакие хранилища для типов.
Y apply(Y (*func)(T), T arg)        //   Заполняются они по порядку, т.е. если
{                                   //   сюда пришла функция с типом char (*f)
   cout << sizeof(T) << endl;       //   (double), то char запишется в T, а
   cout << sizeof(Y) << endl;       //   double - в Y. Может случится так, что
   return func(arg);                //   они будут хранить одно и то же. Ещё
}                                   //   стоит сказать, что все "гибкие" типы
                                    //   должны использоваться в объявлении
double f(double x)                  //   функции. Туниянцев быть не должно, g++
{                                   //   не позволит
   return x * (1-x);
}

int factorial(int n)
{
   if (n <= 1)
      return 1;
   return n * factorial(n - 1);
}

char symb(int n)
{
   return 'a' + n;
}


int main()
{
   cout << apply(f, 0.5) << endl;
   cout << apply(factorial, 5) << endl;
   cout << apply(symb, 3) << endl;

   return 0;
}
