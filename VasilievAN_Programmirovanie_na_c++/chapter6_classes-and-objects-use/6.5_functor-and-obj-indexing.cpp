/*
 * =====================================================================================
 *
 *       Filename:  6.5_functor-and-obj-indexing.cpp
 *
 *    Description:  describes Taylor series using class with extra operators
 *
 *        Version:  1.0
 *        Created:  06/17/20 15:22:53
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cmath>
using namespace std;

const int n = 10;


class TaylorSeries {
private:
   double series[n];
public:
   TaylorSeries(double num = 0.) {
      for (double &x: series)
         x = num;
   }
   TaylorSeries(double *nums) {
      for (int i = 0; i < n; i++)
         (*this)[i] = nums[i];   // *this - тут не сработает простое ->
   }

   double operator()(double x) { // () - да, теперь объект будет работать как
      double sum = 0;            //   функция! Такой объект зовётся функтором
      double q = 1;
      for (int i = 0; i < n; i++) {
         sum += (*this)[i] * q;
         q *= x;
      }
      return sum;
   }
   double& operator[](int i) {
      return series[i];
   }
};


int main()
{
   double nums[n] = { 0, 1, 0, 1./3, 0, 2./15, 0, 17./315, 0, 62./2835 };
   TaylorSeries myexp;
      myexp[0] = 1;
      for (int i = 1; i < n; i++) {
         myexp[i] = myexp[i-1] / i;
      }
   TaylorSeries f(1);
   TaylorSeries mytan(nums);

   double x = 1.0;
   cout << myexp(x) << " vs " << exp(x) << endl;
   cout << mytan(x) << " vs " << tan(x) << endl;
   cout << f(x/2) << " vs " << 1 / (1 - x/2) << endl;

   return 0;
}
