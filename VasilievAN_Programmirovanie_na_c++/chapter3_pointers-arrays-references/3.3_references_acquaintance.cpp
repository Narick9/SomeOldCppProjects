/*
 * =====================================================================================
 *
 *       Filename:  3.3_references_acquaintance.cpp
 *
 *    Description: creates int and reference, changes and outputs them
 *
 *        Version:  1.0
 *        Created:  05/16/20 19:41:11
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

int main()
{
    int num;
    int &ref = num;     // int &ref = num - это ссылка. Она объявляется с
                        //                  символом & перед именем и тут же
                        //                  должна быть инициализирована
                        //                  переменной, т.к. память под ссылку
                        //                  не выделяется. Можно считать, что
                        //                  это второе имя для переменной.
                        //                  Обратишься к одному - значит
                        //                  обратишься к обоим

    num = 100;
    cout << "num: " << num << endl
         << "ref: " << ref << endl;
    ref = 200;
    cout << "num: " << num << endl
         << "ref: " << ref << endl;
    
    return 0;
}
