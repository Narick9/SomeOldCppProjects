/*
 * =====================================================================================
 *
 *       Filename:  7.r3_type-list.cpp
 *
 *    Description:  describes lock type list 
 *
 *        Version:  1.0
 *        Created:  06/28/2020 01:31:55 PM
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
class List {
   struct Node {
      T value;
      Node *next;
   };

   Node *head = nullptr;
   size_t depth = 0;

   public:
      ~List() {
         while (depth) {
            pop(0);
         }
      }

      void add(T new_thing) {
         Node *new_node = new Node;
         new_node->value = new_thing;
         new_node->next = nullptr;
         if (!head) {
            head = new_node;
         } else {
            get_node(depth - 1)->next = new_node;
         }
         depth++;
      }
      void pop(int i) {
         if (i == 0) {
            Node *temp = head->next;
            delete head;
            head = temp;
         } else {
            Node *above = get_node(i - 1);
            Node *below = above->next->next;
            delete above->next;
            above->next = below;
         }
         depth--;
      }
      void print() const {
         Node *cur = head;
         for (int _ = 0; _ < depth; _++) {
            cout << cur->value << " ";
            cur = cur->next;
         }
         cout << endl;
      }

      size_t get_depth() const {
         return depth;
      }
      T& operator[](int i) {
         return get_node(i)->value;
      }

   private:
      Node* get_node(int i) const {
         if ( i < 0 || i >= depth ) {
            cout << "ERROR:\tmax depth has been exceeded" << endl;
            exit(1);
         }
         Node *target = head;
         for (int _ = 0; _ < i; _++)
            target = target->next;
         return target;
      }
};


int main()
{
   List<char> my_list;

   my_list.add('z');
   my_list.add('t');
   my_list.add('2');
   my_list.add('$');

   my_list.print();

   my_list.pop(1);
   my_list[2] = '3';

   cout << "[ ";
   for (int i = 0; i < my_list.get_depth(); i++) {
      cout << my_list[i] << " ";
   }
   cout << "]" << endl;
   
   return 0;
}
