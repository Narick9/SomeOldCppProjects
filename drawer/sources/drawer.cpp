#include "drawer.h"
#include <string.h>

namespace setts {
   char **pp_field = nullptr;
   short field_size_x = 0;
   short field_size_y = 0;
   char field_border_symb = '#';
   char field_body_symb = ' ';
   string bottom_msg = "-- NORMAL --";

   short cursor_x = 1;
   short cursor_y = 1;
   char cursor_symb = '!';

   bool is_on = true;
   Mode mode = VISUAL;
};

void field_clear()
{
   for (int y = 0; y < setts::field_size_y; y++) {
      for (int x = 0; x < setts::field_size_x; x++)
         if (   y == 0 || y == setts::field_size_y - 1
             || x == 0 || x == setts::field_size_x - 1)
            setts::pp_field[y][x] = setts::field_border_symb;
         else
            setts::pp_field[y][x] = setts::field_body_symb;
   }
}

void field_print()
{
   char occupied = setts::pp_field[setts::cursor_y][setts::cursor_x];
   setts::pp_field[setts::cursor_y][setts::cursor_x] = setts::cursor_symb;
   for (int y = 0; y < setts::field_size_y; y++) {
      for (int x = 0; x < setts::field_size_x; x++)
         printf("%c", setts::pp_field[y][x]);
      printf("\n");
   }
   setts::pp_field[setts::cursor_y][setts::cursor_x] = occupied;
   cout << setts::bottom_msg;
}

void command_work()
{
   char msg[80];
   cin.getline(msg, 79);
   string extra_msg = " - completed";

   if (! strcmp(msg, "quit") ) {
      setts::is_on = false;
   } else if (! strcmp(msg, "clear") ) {
      field_clear();
   } else if (! memcmp(msg, "write ", 6)) {
      char *filename = new char[strlen(msg + 6)];
      sprintf(filename, "%s", msg + 6);
      FILE *fstorage = fopen(filename, "w"); {
         for (int y = 1; y < setts::field_size_y - 1; y++) {
            fprintf(fstorage, "%.*s\n", setts::field_size_x - 2,
                     &setts::pp_field[y][1]);  // \n - перед этим нужен пробел,
         }                                     //   т.к. Windows ставит \r к
      } fclose(fstorage);                      //   нему: \r\n
   } else if (! memcmp(msg, "open ", 5)) {
    //char *filename = new char[strlen(msg + 5)];
    //sprintf(filename, "%s", msg + 5);
      char *filename = msg + 5;
      FILE *frecover = fopen(filename, "r"); {
         if (!frecover) {
            extra_msg = " - cannot open file";
         } else {
            char line[800];
            int y = 1;
            while (fgets(line, 800, frecover) && y < setts::field_size_y - 1) {
             //sprintf(&setts::pp_field[y][1], "%.*s", setts::field_size_x - 2,
             //         line);
               int x = 0;
               while (x < strlen(line) - 1 && x < setts::field_size_x - 2) {
                        // strlen() - 1 - убираем символ новой строки
                  setts::pp_field[y][x + 1] = line[x];
                  x++;
               }
               y++;
            }
         }
      } fclose(frecover);
   } else {
      extra_msg = " - invalid command";
   }

   setts::bottom_msg = msg + extra_msg;
   setts::mode = VISUAL;
}

void keypress_work()
{
   if (setts::mode == COMMAND) {
      command_work();
      return;
   }
   setts::bottom_msg = "-- NORMAL --";

   char key = getch();
   bool is_arrow = false;
   if (key == -32) {   // -32 - возможные первичные коды у стрелок в Windows:
      is_arrow = true; //   0, 224, -32
      key = getch();
   }

   if (is_arrow) {
      switch (key) {
         case 75:    // left arrow
            if (setts::cursor_x > 1) {
               setts::cursor_x--;
            }
            break;
         case 77:    // right arrow
            if (setts::cursor_x < setts::field_size_x - 2) {
               setts::cursor_x++;
            }
            break;
         case 72:    // up arrow
            if (setts::cursor_y > 1) {
               setts::cursor_y--;
            }
            break;
         case 80:    // down arrow
            if (setts::cursor_y < setts::field_size_y - 2) {
               setts::cursor_y++;
            }
            break;
      }
      return;
   }
   switch (key) {
      case ':':
         setts::bottom_msg = ":";
         setts::mode = COMMAND;
         break;
      case 32:    // Space
      case 13:    // Enter
         setts::pp_field[setts::cursor_y][setts::cursor_x]
                  = setts::cursor_symb;
         break;
      case 27:    // Esc
         break;
      case 8:     // Backspace
         setts::pp_field[setts::cursor_y][setts::cursor_x]
                  = setts::field_body_symb;
         break;
      default:
         setts::cursor_symb = key;
   }
}