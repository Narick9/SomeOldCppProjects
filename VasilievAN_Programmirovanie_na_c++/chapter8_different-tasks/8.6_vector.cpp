/*
 * =====================================================================================
 *
 *       Filename:  8.6_vector.cpp
 *
 *    Description:  demonstrates using of vector
 *
 *        Version:  1.0
 *        Created:  06/30/2020 05:38:43 PM
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
#include <vector>
using namespace std;


int main()
{
   srand(42);
   
   int size;
   cout << "size: ";
   cin >> size;

   vector<char> symbs(size);  // vector - сначала был vector, но позже кто-то
                              //   решил, что его скорости не достаточно, и
                              //   попытался с помощью некоторых решений с
                              //   FORTRAN сделать valarray. Это могло дать
                              //   некоторый выйгрыш производительности для
                              //   векторных машин (которые часто работали с
                              //   большими массивами данных), но популярности
                              //   valarray не возымел. Для простых смертных
                              //   valarray стал просто слегка урезанным в
                              //   плане набора методов vector'ом
                              // size - размер здесь тоже по умолчанию ноль
   for (int i = 0; i < symbs.size(); i++) {
      symbs[i] = 'a' + rand() % 26;
   }

   for (int i = 0; i < symbs.size(); i++) {
      cout << symbs[i] << " ";
   } cout << endl;

   return 0;
}
