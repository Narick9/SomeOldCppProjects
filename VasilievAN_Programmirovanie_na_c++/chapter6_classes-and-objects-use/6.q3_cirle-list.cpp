/*
 * =====================================================================================
 *
 *       Filename:  6.q3_list-circle.cpp
 *
 *    Description:  describes a list like circle
 *
 *        Version:  1.0
 *        Created:  06/18/20 21:33:51
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

class CircleListNode {
   bool mark = true;
   int num   = rand() % 100;
   char symb = 'a' + rand() % 26;
   public:
      CircleListNode *next = NULL;

      CircleListNode() {
      }
      CircleListNode(CircleListNode &obj) {  // copy - как и после появления
         obj.next = this;                    //   обычного конструктора, после
      }                                      //   появления конструктора копий,
                                             //   исчезает конструктор по
      ~CircleListNode() {                    //   по умолчанию
         cout << num << "- "                       ;
         mark = !mark                              ;
         if (mark != next->mark)                    {
            delete next                            ;}
         else                                       {
            cout << endl                           ;}
      }

      void print() {
         cout << num << symb << " ";
      }
      void print_all() {
         CircleListNode *cur = this;
         do {
            cur->print();
            cur = cur->next;
         } while (cur != this);
         cout << endl;
      }
};


int main()
{
   CircleListNode *start = new CircleListNode;
      CircleListNode *cur = start;
      for (int _ = 1; _ < 16; _++) {
         cur = new CircleListNode(*cur);
      }

   cur->next = start;
   cur->print_all();

   delete start;
   return 0;
}
