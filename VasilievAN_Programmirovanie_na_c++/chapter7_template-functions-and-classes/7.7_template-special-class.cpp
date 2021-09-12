/*
 * =====================================================================================
 *
 *       Filename:  7.7_template-special-class.cpp
 *
 *    Description:  demonstrates a template special class 
 *
 *        Version:  1.0
 *        Created:  06/21/20 22:39:39
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


template< typename T >
class MyClass {
   T value;
   public:
      MyClass(T _value) {
         value = _value;
      }

      void print() {
         cout << "value: " << value << endl;
      }
};
template<>
class MyClass <string>{
   char value[100];
   public:
      MyClass(char* str) {
         int i;
         for (i = 0; str[i]; i++) {
            value[2*i] = '|';
            value[2*i + 1] = str[i];
         }
         value[2*i] = '|';
         value[2*i + 1] = '\0';
      }

      void print() {
         cout << value << endl;
      }
};


int main()
{
   MyClass<int> obj_1(100);
   MyClass<char> obj_2('A');
   MyClass<char*> obj_3((char*)"sometext");
   MyClass<string> obj_4((char*)"sometext"); // string - интересно, что в
                                             //   в специализированном под
   obj_1.print();                            //   string классе сам по себе
   obj_2.print();                            //   string не используется
   obj_3.print();
   obj_4.print();

   return 0;
}
