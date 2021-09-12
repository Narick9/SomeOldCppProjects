/*
 * =====================================================================================
 *
 *       Filename:  7.2_template_sort.cpp
 *
 *    Description:  sortes arrays with different types using one func 
 *
 *        Version:  1.0
 *        Created:  06/20/20 19:45:37
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


template<typename T>          // template - совсем не страшная вещь
void show(T* arr, int size)   // show() - функция с template зовётся обобщённой
{                             //   (по типам)
   for (int i = 0; i < size; i++)
      cout << arr[i] << " ";
   cout << endl;
}

template<typename T>
void sort(T* arr, int size)
{
   show(arr, size);

   T temp;
   for (int k = 0; k < size; k++)
      for (int i = 1; i < size - k; i++)
         if (arr[i - 1] > arr[i]) {
            temp       = arr[i - 1];
            arr[i - 1] = arr[i];
            arr[i]     = temp;
         }

   show(arr, size);
}


int main()
{
   int nums[5] = { 3, 2, 8, 1, 0 };
   char symbs[7] = { 'Z', 'B', 'Y', 'A', 'D', 'C', 'X' };

   sort(nums, 5);
   sort(symbs, 7);

   return 0;
}
