/*
 * =====================================================================================
 *
 *       Filename:  8.r2_valarr-mean.cpp
 *
 *    Description: creates two arrays and computes their means with func 
 *
 *        Version:  1.0
 *        Created:  07/01/20 22:16:25
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <valarray>
using namespace std;

double mean(valarray<int> arr);


int main()
{
   int temp_nums_a[5]  = {1, 3, 8, -2, 4};
   valarray<int> nums_a(temp_nums_a, 5);
      for (int &x: nums_a)
         cout << x << ", ";
      cout << endl;
   int temp_nums_b[3] = {4, 6, 2};
   valarray<int> nums_b(temp_nums_b, 3);
      for (int &x: nums_b)
         cout << x << ", ";
      cout << endl;

   cout << "First array mean:  " << mean(nums_a) << endl;
   cout << "Second array mean: " << mean(nums_b) << endl;

   return 0;
}


double mean(valarray<int> arr)
{
   return static_cast<double>(arr.sum() / arr.size());
}  // sum() - огромный плюс valarray перед vector (как уже говорилось) в том,
   //   что он заточен на векторные операции (математически векторные). В нём
   //   есть такие функции, как min(), max(), sum(), apply(), shift() и т.д.,
   //   которые очень облегчают работу. Их нет в vector'е
