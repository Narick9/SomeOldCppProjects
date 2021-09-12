/*
 * =====================================================================================
 *
 *       Filename:  6.4_arr-as-field.cpp
 *
 *    Description:  describes Taylor series using class
 *
 *        Version:  1.0
 *        Created:  06/17/20 13:38:53
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
public:
   double series[n];

   TaylorSeries(double num = 0.) {
      for (double &x: series)
         x = num;
   }
   TaylorSeries(double *nums) {
      for (int i = 0; i < n; i++)
         series[i] = nums[i];
   }

   double get_value(double x) {
      double sum = 0;
      double q = 1;
      for (int i = 0; i < n; i++) {
         sum += series[i] * q;
         q *= x;
      }
      return sum;
   }
};


int main()
{
   double nums[n] = { 0, 1, 0, 1./3, 0, 2./15, 0, 17./315, 0, 62./2835 };
   TaylorSeries myexp;
      myexp.series[0] = 1;
      for (int i = 1; i < n; i++) {
         myexp.series[i] = myexp.series[i-1] / i;
      }
   TaylorSeries f(1);
   TaylorSeries mytan(nums);

   double x = 1.0;
   cout << myexp.get_value(x) << " vs " << exp(x) << endl;
   cout << mytan.get_value(x) << " vs " << tan(x) << endl;
   cout << f.get_value(x/2) << " vs " << 1 / (1 - x/2) << endl;

   return 0;
}
