/*
 * =====================================================================================
 *
 *       Filename:  6.4_arr-as-field.cpp
 *
 *    Description:  describes Taylor series using class
 *
 *        Version:  1.0
 *        Created:  06/20/20 12:24:14
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


class TaylorSeries {
public:
   double *series;
   int size;

   TaylorSeries(double num = 0., int accuracy=10) {
      size = accuracy;
      series = new double[accuracy];
      for (int i = 0; i < accuracy; i++)
         series[i] = num;
   }
   TaylorSeries(double *nums, int accuracy=10) {
      size = accuracy;
      series = new double[accuracy];
      for (int i = 0; i < accuracy; i++)
         series[i] = nums[i];
   }

   double get_value(double x) {
      double sum = 0;
      double q = 1;
      for (int i = 0; i < size; i++) {
         sum += series[i] * q;
         q *= x;
      }
      return sum;
   }
};


int main()
{
   double nums[10] = { 0, 1, 0, 1./3, 0, 2./15, 0, 17./315, 0, 62./2835 };
   TaylorSeries myexp(0., 7); // 0. - странно, но отправка int и int здесь
      myexp.series[0] = 1;    //   считается двусмысленной. Как можно препутать
                              //   int к double и int к указателю?
      for (int i = 1; i < 7; i++) {
         myexp.series[i] = myexp.series[i-1] / i;
      }
   TaylorSeries f(1, 8);
   TaylorSeries mytan(nums);

   double x = 1.0;
   cout << myexp.get_value(x) << " vs " << exp(x) << endl;
   cout << mytan.get_value(x) << " vs " << tan(x) << endl;
   cout << f.get_value(x/2) << " vs " << 1 / (1 - x/2) << endl;

   return 0;
}
