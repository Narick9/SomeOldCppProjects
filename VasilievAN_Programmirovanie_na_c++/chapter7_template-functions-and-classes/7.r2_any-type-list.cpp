/*
 * =====================================================================================
 *
 *       Filename:  7.r2_ordered-any-type-list.cpp
 *
 *    Description:  describes ordered list with any type
 *
 *        Version:  1.0
 *        Created:  06/27/2020 02:42:55 PM
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


class List {
   struct Node {
      Node *next;
      void *value;
   };

   Node *head = nullptr;   // nullptr - в отличие от Си, в C++ официально нет
   size_t depth = 0;       //   макроса NULL, зато есть nullptr. Добавили это
                           //   в C++11, до этого писали просто 0 (кто не хотел
   public:                 //   использовать NULL, связанный с компилятором).
      ~List() {            //   Стоит ещё сказать, что для него сделали
         while (depth)     //   отедальный тип данных: std::nullptr, способный
            pop(0);        //   хранить только одно значение - nullptr. Зачем?
      }                    //   - непонятно. Нужно? - нет.

      template< typename T >           // T - механизм сохранения типов я таки
      void add(T new_thing) {   //   не смог придумать
         Node *new_node = new Node;
         new_node->next = nullptr;
         T* temp = new T;
         *temp = new_thing;
         new_node->value = temp;

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
            free(head->value);
            delete head;
            head = temp;
         } else {
            Node *above = get_node(i - 1);
            Node *below = above->next->next;
            free(above->next->value); // free - g++ говорит, что delete не в
            delete above->next;       //   курсе как освобождать void*
            above->next = below;
         }
         depth--;
      }
      template< typename U >
      U& get(int i) {
         return *static_cast<U*>(get_node(i)->value);
      }
      size_t get_depth() const {
         return depth;
      }

   private:
      Node* get_node(int i) {
         if ( i < 0 || i >= depth ) {
            cout << "ERROR:\tmax depth has been exceeded" << endl;
            exit(1);
         }
         Node *target = head;
         for (int _ = 0; _ < i; _++) {
            target = target->next;
         }
         return target;
      }
};


int main()
{
   List my_list;

   my_list.add("vi");
   my_list.add("next");
   my_list.add('t');
   my_list.add(52);
   my_list.add(static_cast<unsigned short>(63000));

   cout << "0:  " << my_list.get<char*>(0) << endl;
   cout << "1:  " << my_list.get<char*>(1) << endl;
   cout << "2:  " << my_list.get<char>(2) << endl;
   cout << "3:  " << my_list.get<int>(3) << endl;
   cout << "4:  " << my_list.get<short>(4) << endl;
   cout << "4:  " << my_list.get<unsigned short>(4) << endl;

   cout << "depth: " << my_list.get_depth() << endl;

   my_list.get<char>(2) = 'v';
   cout << "2:  " << my_list.get<char>(2) << endl;

   my_list.pop(2);
   cout << "2:  " << my_list.get<int>(2) << endl;

   cout << "depth: " << my_list.get_depth() << endl;

   return 0;
}
