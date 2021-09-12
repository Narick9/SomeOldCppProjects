/*
 * =====================================================================================
 *
 *       Filename:  6.3_objs-arr.cpp
 *
 *    Description:  demonsrates an array of objects 
 *
 *        Version:  1.0
 *        Created:  06/15/20 19:13:16
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <string>
using namespace std;

class Word {
public:
   string word;
   bool is_last;
   Word() {
      word = "";
      is_last = false;
   }
   void print() {
      cout << word << " ";
      if (is_last)
         cout << endl;
      else
         (this + 1)->print();
   }
};


int main()
{
   const int n = 5;

   string numbers[n] = { "one", "two", "three", "four", "five" };
   Word words[n];    // words - если хочешь сделать массив из кастомных классов,
                     //   то в них должен быть конструктор без аргументов. Как
                     //   мы помним, такой есть в классах по умолчанию, до того,
                     //   как там появится другой, который с аргументами
   words[n - 1].is_last = true;
   for (int i = 0; i < n; i++)
      words[i].word = numbers[i];

   words[0].print();
   words[2].print();
    
   return 0;
}
