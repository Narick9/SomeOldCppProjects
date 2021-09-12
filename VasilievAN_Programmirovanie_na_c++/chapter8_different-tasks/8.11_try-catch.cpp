/*
 * =====================================================================================
 *
 *       Filename:  8.11_try-catch.cpp
 *
 *    Description:  demonsrates using of try-catch with standart lib containter 
 *
 *        Version:  1.0
 *        Created:  07/01/2020 03:45:16 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
using namespace std;


int main()
{
   int size;
   cout << "Fibonacci series size: ";
   cin >> size;

   try {
      vector<int> fibs(size, 1);
            // try - про исключения уже было написано, но тогда мы их делали
            //   искусственно. Здесь же показано как они генерируются прямо в
            //   объектах стандартной библиотеки. Если size здесь окажется
            //   отрицательным - выкенится исключение, которое мы перехватим
      cout << fibs[0] << " " << fibs[1];  // fibs[..] - да, здесь мы хотим,
      for (int i = 2; i < size; i++) {    //   чтобы была введена минимум 2-ка
         fibs[i] = fibs[i - 2] + fibs[i - 1];
         cout << " " << fibs[i];
      }
      cout << endl;
   } catch (...) {   // ... - этот catch будет перехватывать ошибки всех типов
      cout << "ERROR: some error" << endl;
   }

   return 0;
}
