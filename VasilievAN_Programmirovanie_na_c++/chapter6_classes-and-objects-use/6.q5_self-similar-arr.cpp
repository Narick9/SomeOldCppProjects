/*
 * =====================================================================================
 *
 *       Filename:  6.q5_self-similar-arr.cpp
 *
 *    Description:  describes class with array of self-similar 
 *
 *        Version:  1.0
 *        Created:  06/19/20 20:37:19
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstring>
using namespace std;

class StrangeArr {
   public:
      char *str;
      int size;
      StrangeArr *arr;

      StrangeArr() {
         str = NULL;
         size = 0;
         arr = NULL;
      }
      StrangeArr(char *_str, int _size) {
         str = strdup(_str);
         size = _size;
         if (_size)
            arr = new StrangeArr[_size];
         else
            arr = NULL;
      }

      void print_all(int tab_n = 0) {
         for (int _ = 0; _ < tab_n; _++)
            cout << '\t';
         cout << str << endl;;
         for (int i = 0; i < size; i++)
            arr[i].print_all(tab_n + 1);
      }

      StrangeArr& operator[](int i) {
         return arr[i];
      }
}; // вспомнил - Структурам можно задавать поля прямо как массивам. Т.е.
   // Person fst = { "Muysa", 1925, "Cat" };

int main()
{
   StrangeArr alphabet((char*)"alphabet", 26);

   for (int i = 0; i < 26; i++) {
      char temp[10] = { 0 };
      temp[0] = 'a' + i;
      alphabet[i] = StrangeArr(temp, 5);
      for (int k = 0; k < 5; k++) {
         sprintf(temp, "%c%i.%i", 'a' + i, k, (100 - i) - k);
         alphabet[i].arr[k] = StrangeArr(temp, 0);
      }
   }

   alphabet.print_all();
   
   return 0;
}
