/*
 * =====================================================================================
 *
 *       Filename:  8.4_valarray.cpp
 *
 *    Description:  demonstrates using of valarray class 
 *
 *        Version:  1.0
 *        Created:  06/29/2020 09:28:42 PM
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

int main()
{
   const int size = 15;

   valarray<int> fibs(size);  // valarray - это этакий продвинутый массив,
                              //   умеющий делать полезные вещи, такие, как
   fibs[0] = 1;               //   выдача своего размера (метод size()), или
   fibs[1] = 1;               //   его изменение (методы resize())
                              // size - по умолчанию размер - ноль
   cout << fibs[0] << " " << fibs[1];
   for (int i = 2; i < size; i++) {
      fibs[i] = fibs[i - 2] + fibs[i - 1];
      cout << " " << fibs[i];
   }
   cout << endl;

   return 0;
}
