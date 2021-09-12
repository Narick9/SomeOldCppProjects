/*
 * =====================================================================================
 *
 *       Filename:  6.q4_binary-tree.cpp
 *
 *    Description:  spies 
 *
 *        Version:  1.0
 *        Created:  06/19/20 16:29:47
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

class node {
   public:
      string question;
      node *yes;
      node *no;

      node(string _question) {
         question = _question;
         yes = NULL;
         no  = NULL;
      }
      ~node() {
         cout << "del " << question << endl;
         if (yes)
            delete yes;
         if (no)
            delete no;
      }
};


bool yes_no(string question)
{
   cout << question << "? (y/n): ";
   char ans[3];
   fgets(ans, 3, stdin);      // fgets - cin не знает меры, поэтому пытается
   return ans[0] == 'y';      //   впихнуть невпихуемое
}

void del_newline(char *str)
{
   char *p_newline = strchr(str, '\n');
   if (p_newline)
      *p_newline = '\0';
}


int main()
{
   node *start_node = new node("Носит ли подозреваемый усы?");
   start_node->yes = new node("Иван Ложкин");
   start_node->no = new node("Лоретта Барншворц");

   char suspect[40];    // char - cin умеет читать только до первого пробела,
   char question[80];   //   а fgets не знаком со string. Поэтому получилась
   node *current;       //   такая чехорда с типами
   do {
      current = start_node;
      while (true)
         if (yes_no(current->question)) {
            if (current->yes) {
               current = current->yes;
            } else {
               cout << "ПОДОЗРЕВАЕМЫЙ ОПОЗНАН" << endl;
               break;
            }
         } else if (current->no) {
            current = current->no;
         } else {
            cout << "Кто подозреваемый? ";
            fgets(suspect, 40, stdin);
            del_newline(suspect);

            cout << "Задайте мне вопрос, который подходит для " << suspect
                 << ", но не для " << current->question << ". ";
            fgets(question, 80, stdin);
            del_newline(question);
         
            current->no = new node(current->question);
            current->yes = new node(suspect);
            current->question = question; // question - не стоит забывать, что
                                          //   при присвоении string переменной
            break;                        //   символьного массива, string
         }                                //   копирует себе его содержимое.
   } while (yes_no("Выполнить ещё раз")); //   Незнание этого может привезти
                                          //   к утечке памяти
   delete start_node;
   return 0;
}
