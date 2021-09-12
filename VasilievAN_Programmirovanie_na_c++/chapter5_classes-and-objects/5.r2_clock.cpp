/*
 * =====================================================================================
 *
 *       Filename:  5.r2_clock.cpp
 *
 *    Description:  describes a clock using classes 
 *
 *        Version:  1.0
 *        Created:  06/13/20 22:27:26
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <time.h>
#include <unistd.h>     // unistd.h - для доступа к фукнции sleep()
using namespace std;

class Clock {       // Clock - это простая обёртка для struct tm
    public:
        struct tm *p_cur_time;  // tm - структура для описания даты и времени,
        char time_str[10];      //   и даже недели и месяцы

        Clock() {
            time_t now = time(NULL);
            p_cur_time = gmtime(&now);  // & - нам нужен именно адрес значения,
                                        //   а его можно взять только из
                                        //   переменной. Нельзя написать
                                        //   &time()
                                        // gmtime() - это гринвичское среднее
                                        //   вермя
            strftime(time_str, 9, "%H:%M:%S", p_cur_time);
                cout << "The clock has been bought at " << time_str << endl;
                        // strftime() - как printf, но для даты и времени
        }
        ~Clock() {
            cout << "The clock has been crashed at " << get_time() << endl;
        }
//      --------------------------------------------------------------
        char* get_time() {
            time_t now = time(NULL);
            p_cur_time = gmtime(&now);

            strftime(time_str, 9, "%H:%M:%S", p_cur_time);
            return time_str;
        }
};


int main()
{
    Clock mine;

    sleep(2);   // sleep() - в отличии от sleep() из windows.h отмеряет секунды
    cout << "Now " << mine.get_time() << endl;
    sleep(2);
    return 0;
}
