/*
 * =====================================================================================
 *
 *       Filename:  6.q1_obj-array.cpp
 *
 *    Description:  creates an array of objects 
 *
 *        Version:  1.0
 *        Created:  06/18/20 17:51:21
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
using namespace std;


class Num {
   private:
      int num;
   public:
      Num() { num = rand() % 10; }

      int get_num() { return num; }
};


int main()
{
   Num arr[4];

   for (int i = 0; i < 4; i++) {
      cout << arr[i].get_num() << ", ";
   }
   cout << endl;

   return 0;
}
