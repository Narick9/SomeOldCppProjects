/*
 * =====================================================================================
 *
 *       Filename:  drawer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/03/2020 04:10:49 PM
 * start: 3 july 2020G
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "drawer.h"


int main()
{
   cout << "___DRAWER___" << endl;
   short width;
   short height;
   cout << "canvas width: ";   cin >> width;
   cout << "canvas height: ";   cin >> height;
   cin.get();  // get() - извлекаем оставшийся символ новой строки
   setts_set(height, width, '#', ' ');

   while(setts::is_on) {
      system("cls");
      cout << "___DRAWER___" << endl;
      field_print();
      keypress_work();
   }

   return 0;
}