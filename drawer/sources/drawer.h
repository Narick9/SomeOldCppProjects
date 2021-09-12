#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#ifdef __linux
   #include <curses>
#elif defined _WIN64 || _WIN32
   #include <conio.h>
#endif

enum Mode { VISUAL, COMMAND };

namespace setts {
   extern char **pp_field;
   extern short field_size_x;
   extern short field_size_y;
   extern char field_border_symb;
   extern char field_body_symb;
   extern string bottom_msg;

   extern short cursor_x;
   extern short cursor;
   extern char cursor_symb;

   extern bool is_on;
   extern Mode mode;
};

void field_clear();

inline void setts_set(
      short _field_size_y,
      short _field_size_x,
      char _field_border_symb,
      char _field_body_symb)
{
   setts::field_size_y = _field_size_y;
   setts::field_size_x = _field_size_x;
   setts::field_border_symb = _field_border_symb;
   setts::field_body_symb = _field_body_symb;

   setts::pp_field = new char*[_field_size_y];
   for (int y = 0; y < _field_size_y; y++) {
      setts::pp_field[y] = new char[_field_size_x];
   }
   field_clear();
}

void field_print();
void command_work();
void keypress_work();