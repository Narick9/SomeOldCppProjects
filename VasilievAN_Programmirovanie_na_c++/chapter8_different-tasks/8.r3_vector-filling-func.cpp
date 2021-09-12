/*
 * =====================================================================================
 *
 *       Filename:  8.r3_vector-filling-func.cpp
 *
 *    Description:  creates a arr objects and fills them with two funcs
 *
 *        Version:  1.0
 *        Created:  07/01/20 12:21:55
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
#include <set>
using namespace std;

void fibs_fill(vector<int>& arr);
void rands_fill(set<int>& uniqs, int need_size);
   // & - не добавить & в объявлении функции, но добавить в описании, g++
   //   поперхнётся так, что сам не поймёт ошибку
int main()
{
   srand(3);
   const int size = 15;

   vector<int> vec(size);  // vec - если не задать наполнитель, конструктор
                           //   заполнит всё нулями
   fibs_fill(vec);
      for (int i = 0; i < size; i++)
         cout << vec[i] << ", ";
      cout << endl;
    
   set<int> uniques;

   rands_fill(uniques, size);
      for (set<int>::iterator it = uniques.begin(); it != uniques.end(); it++)
         cout << *it << ", ";
      cout << endl;

   return 0;
}


void fibs_fill(vector<int>& vec)
{
   if (vec.size() > 0)
      vec[0] = 1;
   if (vec.size() > 1)
      vec[1] = 1;
   for (int i = 2; i < vec.size(); i++)
      vec[i] = vec[i - 2] + vec[i - 1];
}

void rands_fill(set<int>& uniqs, int need_size)
{
   while(uniqs.size() < need_size)
      uniqs.insert(rand() % 100);
}
