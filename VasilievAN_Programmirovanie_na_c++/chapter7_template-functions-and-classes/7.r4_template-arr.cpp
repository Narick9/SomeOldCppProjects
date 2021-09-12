/*
 * =====================================================================================
 *
 *       Filename:  7.r4_binary-tree.cpp
 *
 *    Description:  describes template array class
 *
 *        Version:  1.0
 *        Created:  06/28/2020 05:49:01 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;


template< typename T >
class Container {
   size_t size = 5;
   int free_id = 0;
   T *arr = nullptr;

   public:
      Container() {
         arr = new T[size];
      }
      ~Container() {
         delete arr;
      }

      void add(T new_thing) {
         if (free_id == size) {
            reallocate(1.5 * size);
         }
         arr[free_id++] = new_thing;
      }
      void pop(int k = -1) {
         assert(-1 <= k && k < free_id);
         if (k == -1) {       // assert - стандартная функция для утверждения.
            k = free_id - 1;  //   Если утверждение ложно, то работа программы
         }                    //   останавливается, а компилятор выкладывает
                              //   строчку, где это произошло. в C++ появился
                              //   братик этой функции - static_assert,
                              //   проверяющий условие во время компиляции.
                              //   Разумеется, его условие должно быть
                              //   пригодным для этого. В идеале релизная
                              //   программа не должна содержать assert'ов,
                              //   т.к. код уже должен быть тщательно
                              //   протестирован. Есть даже директива
                              //   #define NDEBUG, уберающая все assert'ы из
                              //   кода для экономии ресурсов (хотя тратит она
                              //   их почти не тратит)
         for (int i = k; i <= free_id - 2; i++) {
            arr[i] = arr[i + 1];
         }
         free_id--;
      }
      void print() {
         cout << "[ ";
         for (int i = 0; i < free_id; i++)
            cout << arr[i] << " ";
         cout << "]" << endl;;
      }

      T& operator[](int i) {
         assert(0 <= i && i < free_id);
         return arr[i];
      }

   private:
   void reallocate(size_t new_size) {
      T *new_arr = new T[new_size];
      for (int i = 0;   i < new_size && i < size;   i++) {
         new_arr[i] = arr[i];
      }
      delete arr;
      arr = new_arr;
      size = new_size;
   }
};


int main()
{
   Container<char> my_arr;
   my_arr.print();

   for (int i = 0; i < 6; i++) {
      my_arr.add('a' + i);
   }
   my_arr.print();

   my_arr.add('t');
   my_arr.print();

   my_arr.pop(3);
   my_arr.print();

   my_arr[0] = 'v';
   my_arr.print();

   return 0;
}
