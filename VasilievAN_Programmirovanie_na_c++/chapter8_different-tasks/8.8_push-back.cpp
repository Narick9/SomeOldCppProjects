/*
 * =====================================================================================
 *
 *       Filename:  8.8_push-back.cpp
 *
 *    Description: demonstrates resizing of vector with push_back() method
 *
 *        Version:  1.0
 *        Created:  06/30/2020 09:05:14 PM
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
   srand(52);

   vector<char> symbs;

   int i = 0;
   while (symbs.size() < 8) {
      symbs.push_back('a' + i);
      cout << symbs[symbs.size() - 1] << " ";
      i++;           // push_back() - всеми известный метод добавления нового
   } cout << endl;   //   элемента вконец у vector. valarray такого не имеет

   return 0;
}
