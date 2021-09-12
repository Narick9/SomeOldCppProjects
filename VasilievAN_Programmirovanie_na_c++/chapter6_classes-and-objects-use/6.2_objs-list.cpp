/*
 * =====================================================================================
 *
 *       Filename:  6.2_objs-list.cpp
 *
 *    Description:  creates recursive class and list of it
 *
 *        Version:  1.0
 *        Created:  06/15/20 16:04:53
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

class CharNode {
public:
    char c;
    CharNode *next;
    ~CharNode() {
        if (next)
            delete next;
        cout << c << " has been deleted" << endl;
    }
    void print_recursive() {
        cout << c << " ";
        if (next)
            next->print_recursive();
    }
};


int main()
{
    CharNode *p_head = new CharNode;
    p_head->c = 'A';

    CharNode *p_node = p_head;
    for (int _ = 0; _ < 10; _++) {
        p_node->next = new CharNode;
        p_node->next->c = p_node->c + 1;
        p_node = p_node->next;
    }
    p_node->next = NULL;

    p_head->print_recursive();
    cout << endl;

    delete p_head;  // p_head - не стоит забывать, что указатель после free()
    return 0;       //   (а значит и после delete) не станет хранить NULL
}
