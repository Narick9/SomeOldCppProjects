/*
 * =====================================================================================
 *
 *       Filename:  4.14_dynamic-arr-as-func-result_demonstrate.cpp
 *
 *    Description: creates two dynamic arrays with functions 
 *                 Update: using class-array for static arrays
 *
 *        Version:  1.0
 *        Created:  06/20/20 12:50:32
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


class Array {
   public:
      int *arr;
      int size;
      
      Array() {
      }
      Array(int _size);
      Array(const Array& obj); // const - я вычитал, что именно так должен
      ~Array();                //   выглядить конструктор копий. Собственно,
                               //   без этого g++ не хочет компилировать, так
      int& operator[](int i);  //   что всё гуд
};

Array fibs_create(int _size);


int main()
{
   Array arr = fibs_create(10);

   for (int i = 0; i < 10; i++)
      cout << arr[i] << ", ";
   cout << endl;
   
   return 0;
}


Array::Array(int _size) {
   size = _size;
   arr = new int[_size];
}
Array::Array(const Array& obj) {
   size = obj.size;
   arr = new int[size];
   for (int i = 0; i < size; i++)
      arr[i] = obj.arr[i];
}
Array::~Array() {
   delete arr;
}

int& Array::operator[](int i) {
   return arr[i];
}


Array fibs_create(int size)
{
   Array ans(size);
   if (size > 0)
      ans[0] = 1;
   if (size > 1)
      ans[1] = 1;
   for (int i = 2; i < size; i++)
      ans[i] = ans[i - 2] + ans[i - 1];
   return ans;
}
