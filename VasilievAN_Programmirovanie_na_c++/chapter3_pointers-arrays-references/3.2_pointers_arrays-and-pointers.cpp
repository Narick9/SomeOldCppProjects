/*
 * =====================================================================================
 *
 *       Filename:  3.2_pointers_arrays-and-pointers.cpp
 *
 *    Description: creates an array and manipulates it with pointers 
 *
 *        Version:  1.0
 *        Created:  05/16/20 17:30:57
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
    const int n = 12;
    
    char symbs[n],
         *start = symbs,
         *end   = &symbs[n - 1];    // &symbs[n - 1] - сдвиг в скобках в
                                    //                 приоритете перед &

    cout << "The difference between first and last element is " << end - start
         << " bytes" << endl;

    start[0] = 'A';
    while (++start <= end)
        *start = start[-1] + 1;

    for (int i = 0; i < n; i++)
        cout << symbs[i] << ", ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << end[-i] << ", ";
    cout << endl;

    return 0;
}
