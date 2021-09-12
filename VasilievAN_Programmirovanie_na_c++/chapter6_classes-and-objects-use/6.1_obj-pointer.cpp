/*
 * =====================================================================================
 *
 *       Filename:  6.1_obj-pointer.cpp
 *
 *    Description:  demonstrates using class pointer 
 *
 *        Version:  1.0
 *        Created:  06/15/20 15:48:17
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

class NameNum {
public:
    string name;    // string - g++ абсолютно не смущает то, что я не подключил
    int num;        //   ни <cstring>, ни <string>
    void show() {
        cout << "Name: " << name << endl;
        cout << "Num:  " << num << endl;
    }
};


int main()
{
    NameNum a;
    NameNum b;
    NameNum *p;

    p = &a;
        p->name = "a";
        p->num  = 1;
        p->show();
    p = &b;
        p->name = "b";
        p->num  = 2;
        p->show();

    cout << endl;
    cout << "Check:" << endl;
        a.show();
        b.show();
    
    return 0;
}
