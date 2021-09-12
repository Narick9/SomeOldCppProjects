/*
 * =====================================================================================
 *
 *       Filename:  7.r1_sort.cpp
 *
 *    Description:  describes template sort func and swap func
 *
 *        Version:  1.0
 *        Created:  06/27/2020 12:24:06 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using std::cout;
using std::endl;


template< typename T >
void swap(T &left, T &right)  // swap - а чем это не алгоритм?
{
   T temp = left;
   left = right;
   right = temp;
}


template< typename T >
void qsort(T *arr, int size, bool (*comparator)(T, T))
{
   if (size <= 1)
      return;

   int pivot = arr[size/2];
   int i = 0;
   int k = size - 1;
   T temp;
   while (i < k) {
      while (arr[i] < pivot)  i++;
      while (arr[k] > pivot)  k--;
      if (i < k)
         swap(arr[i], arr[k]);
   }
   qsort(arr, i, comparator);
   qsort(arr+i+1, size-i-1, comparator);
}


bool compare(int left, int right)
{
   return left < right;
}


int main()
{
   int arr[6] = { 1000, 4, 99, 3, 0, 100 };
   for (const int &x: arr)
      cout << x << " ";
   cout << endl;

   qsort(arr, 6, compare);

   for (const int &x: arr)
      cout << x << " ";
   cout << endl;
   return 0;
}
