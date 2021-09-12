/*
 * =====================================================================================
 *
 *       Filename:  6.q2_obj-array.cpp
 *
 *    Description:  describes an class-array 
 * *        Version:  1.0
 *        Created:  06/18/20 18:16:26
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

const int size = 12;


class MyArray {
   public:
      float arr[size];

      MyArray() {
         for (int i = 0; i < size; i++)
            arr[i] = i;
      }
      MyArray(float _arr[size]) {
         for (int i = 0; i < size; i++)
            arr[i] = _arr[i];
      }
      MyArray(MyArray &obj) {             // copy - честно говоря не знаю зачем
         for (int i = 0; i < size; i++)   //   здесь нужен отдельный
            arr[i] = obj.arr[i];          //   конструктор копирования, т.к.
      }                                   //   копируется весь массив, ну да
      float& operator[](int i) {          //   ладно
         return arr[i];
      }
      float operator()() {
         float sum = 0;
         for (int i = 0; i < size; i++)
            sum += arr[i];
         return sum / size;
      }
      MyArray operator+ (MyArray right) {
         float ans_arr[size];
         for (int i = 0; i < size; i++)
            ans_arr[i] = (arr[i]+right.arr[i]) / 2;
         MyArray ans(ans_arr);
         return ans; // return - интересно, но если ты объявляешь кастомный
      }              //   конструктор копий, отпадает возможность делать так:
                     //   return MyArray(..); Ошибка в том, что конструктор
                     //   копий принимает значение по ссылке, а ссылка может
                     //   ссылаться только на именованную переменную. При такой
                     //   записи переменной как таковой нет, а значит нельзя
                     //   задейстовать конструктор копий, чтобы копировать
                     //   объект из ретурна в место вызова
      MyArray operator* (float right) {
         float ans_arr[size];
         for (int i = 0; i < size; i++)
            ans_arr[i] = arr[i] * right;
         MyArray ans(ans_arr);
         return ans;
      }
      MyArray operator/ (float right) {
         float ans_arr[size];
         for (int i = 0; i < size; i++)
            ans_arr[i] = arr[i] / right;
         MyArray ans(ans_arr);
         return ans;
      }

      void print() {
         for (int i = 0; i < size; i++)
            cout << arr[i] << ", ";
         cout << endl;
      }
};


int main()
{
   MyArray counter;
      cout << "counter:     ";   counter.print();
   float temp[size] = { 4, 2, 6, 9, 7, 0, 4, 1, 8, 1, 2, 5 };
   MyArray random_nums(temp);
      cout << "random nums: ";   random_nums.print();

   cout << "counter mean:     " << counter() << endl;
   cout << "random nums mean: " << random_nums() << endl;

   cout << "counter and random nums mean: ";   (counter + random_nums).print();

   cout << "counter / 5:     ";   (counter / 5).print();
   cout << "random nums * 2: ";   (random_nums * 2).print();
   
   cout << "counter[5]:     " << counter[5] << endl;
   cout << "random_nums[9]: " << random_nums[9] << endl;
   
   return 0;
}
