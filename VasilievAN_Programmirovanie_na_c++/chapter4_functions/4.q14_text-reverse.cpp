/*
 * =====================================================================================
 *
 *       Filename:  4.q14_text-reverse.cpp
 *
 *    Description:  prints text backward 
 *
 *        Version:  1.0
 *        Created:  06/03/20 19:48:57
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

void print_reverse(char *text);


int main()
{
    char text[] = "Hello again, musya!";
        cout << text << endl;

    print_reverse(text);

    return 0;
}


void print_reverse(char *text)
{
    static int cur = -1;    // static - да, я люблю его
    if (cur == -1) {
        int i = 0;
        while (text[i]) i++;
        cur = i - 1;
    }
    
    if (cur == 0) {
        cout << text[cur] << endl;
        cur = -1;
        return;
    }
    cout << text[cur];  cur--;
    print_reverse(text);
}
