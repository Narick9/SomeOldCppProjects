/*
 * =====================================================================================
 *
 *       Filename:  8.r1_structure-cat.cpp
 *
 *    Description:  describes a cat with structure 
 *
 *        Version:  1.0
 *        Created:  07/01/20 20:57:16
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

struct Cat {
   string name;
   string breed;
   int age;
   string loss_cause = "didn't return from war";
};
   void create(Cat* p_obj, string _name, string _breed, int _age) {
      p_obj->name  = _name;
      p_obj->breed = _breed;
      p_obj->age   = _age;
      cout << "Cat " << _name << " has been added" << endl;
   }
   void destroy(Cat* p_obj) {
      cout << "Cat " << p_obj->name << " has been removed" << endl;
      cout << "Reason: " << p_obj->loss_cause << endl;
   }
   void print_describe(Cat* p_obj) {
      cout << "Name   " << p_obj->name << endl;
      cout << "Breed  " << p_obj->breed << endl;
      cout << "Age    " << p_obj->age << endl;
   }
   void print_meow(Cat *p_obj) {
      cout << p_obj->name << ": meow" << endl;
   }
   void print_view(Cat *p_obj) {
      cout << p_obj->name << endl <<
"\
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n\
▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌ \n\
▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌ \n\
▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▌ \n\
▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░▓▓░░░░▓▓▓▓▓▓▓▓▓▌ \n\
▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░░░░░░░░▓▓▓▓▓▓▓▓▌ \n\
▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░░░░░░░░▓▓▓▓▓▓▓▓▌ \n\
▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░░░░░░░░░░▓░░░░▓▓▓▌ \n\
▐▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░█▄░░░░▄█░░░░░░░░▓▓▌ \n\
▐▓▓▓▓▓▓▓▓▓▓░░░░▓▓▓▓▓▓▓░░░████████░░░░▄▄░░▓▓▌ \n\
▐░░░░▓▓▓▓▓▓░░░░▓▓▓▓▓▓▓░░░███▀██▀█░░▄███░░▓▓▌ \n\
▐░░░░▓▓▓▓▓▓░░░░▓▓▓▓▓▓▓░░░▐████▀██▄███▀░░░▓▓▌ \n\
▐░░░░░▓▓▓░░░░░░▓▓▓░░░▓░░░░▀████████▀░░▄▄░░░▌ \n\
▐░░░░░▓▓▓░░░░░░░░░░░░░░░░▄███████▀░░▄███░░░▌ \n\
▐░░░░░▓▓▓░░░░░░░░░░░░░░░▄█████████▄███▀░░░░▌ \n\
▐░░░░░░░░░░░░░░░░░░░░▄██████████████▀░░░░░░▌ \n\
▐░░░░░░░░░░░░░░░░░░▄██████████████▀░░░░░░░░▌ \n\
▐░░░░░░░░░░░░░░░░░▐████████████▀░░░░░░░░░░░▌ \n\
▐░░░░░░░░░░░░░░░░░█████████████░░░░░░░░░░░░▌ \n\
▐░░░░░░░░░░░░░░░░█████████████▌░░░░░░░░░░░░▌ \n\
▐░░░░░░░░░░░░░░░██████████████░░░░░░░░░░░░░▌ \n\
▐░██▄░░░░░░░▄▄██████████████▀░░░░░░░░░░░░░░▌ \n\
▐░▀███▄░░▄███████████████▀▀░░░░░░░░░░░░░░░░▌ \n\
▐░░░▀▀█████▀▀░░▒▀███▌███▄░░░░░░░░░░░░░░░░░░▌ \n\
▐░░░░░░░░░░░░░░░░░▀██▌████░░░░░░░░░░░░░░░░░▌ \n\
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀ \n\
";
   }


int main()
{
   Cat *musya = new Cat;
      create(musya, "musya", "sphinx", 1917);  cout << endl;
      print_describe(musya);                   cout << endl;
      print_view(musya);
      print_meow(musya);                       cout << endl;
   destroy(musya);
   return 0;
}
