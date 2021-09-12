/*
 * =====================================================================================
 *
 *       Filename:  8.3_complex.cpp
 *
 *    Description:  demonstrates complex class from <complex> 
 *
 *        Version:  1.0
 *        Created:  06/29/2020 08:43:54 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <complex>
using namespace std;


int main()
{
   complex<double> a(3, 4);   // <> - тут можно задать даже свой тип. Главное -
   complex<double> b(2, -1);  //   чтобы методы не подавились им при расчётах
   cout << "a: " << a << endl;
   cout << "b: " << b << endl;

   cout << "a + b: " << a + b << endl;
   cout << "a - b: " << a - b << endl;
   cout << "a * b: " << a * b << endl;
   cout << "a / b: " << a / b << endl;

   double x = 2;
   double y = 3;
   cout << "x: " << x << endl;
   cout << "y: " << y << endl;

   cout << "a + x: " << a + x << endl; // x - странно, но никто не предусмотрел
   cout << "a - x: " << a - x << endl; //   использование double complex с int,
   cout << "a * x: " << a * x << endl; //   например. Приведение в операторах
   cout << "a / x: " << a / x << endl; //   не работает
   cout << "y + b: " << y + b << endl;
   cout << "y - b: " << y - b << endl;
   cout << "y * b: " << y * b << endl;
   cout << "y / b: " << y / b << endl;

   cout << "Re(a):    " << a.real() << endl;
   cout << "Im(a):    " << a.imag() << endl;
   cout << "abs(a):   " << abs(a) << endl;
   cout << "arg(a):   " << arg(a) << endl;
   cout << "a*:       " << conj(a) << endl;
   cout << "polar(a): " << polar(abs(a), arg(a)) << endl;
      // arg - аргумент комплесного числа - это угол между абсцисс и его
      //   вектором. Как по мне, странное название дали математики этому
      // conj - conjugate (англ. сопряжённый)
      // polar - фактически вычисляет координаты из длины вектора и его угла

   return 0;
}
