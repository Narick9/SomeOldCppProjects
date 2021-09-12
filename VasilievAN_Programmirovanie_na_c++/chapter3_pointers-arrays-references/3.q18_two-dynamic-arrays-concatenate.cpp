/*
 * =====================================================================================
 *
 *       Filename:  3.18_two-dynamic-arrays-concatenate.cpp
 *
 *    Description: creates two dynamic arrays and fills them with random. Then
 *                 creates third that stores first and second in turn
 *
 *        Version:  1.0
 *        Created:  05/25/20 18:10:42
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    const int size_a = 3,
              size_b = 8;
    srand(7);

    int *nums_a = new int[size_a];
        cout << "First:\t\t";
        for (int i = 0; i < size_a; i++) {
            nums_a[i] = rand() % 10;
            cout << nums_a[i] << ", ";
        } cout << endl;
    int *nums_b = new int[size_b];
        cout << "Second:\t\t";
        for (int i = 0; i < size_b; i++) {
            nums_b[i] = rand() % 10;
            cout << nums_b[i] << ", ";
        } cout << endl;
    int *_nums_concat_ab = new int[size_a + size_b];
    
    int *start = _nums_concat_ab;
    for (int i = 0; i < size_a; i++)
        *start++ = nums_a[i];
    for (int i = 0; i < size_b; i++)
        *start++ = nums_b[i];

    cout << "First + second:\t";
    for (int i = 0; i < size_a + size_b; i++)
        cout << _nums_concat_ab[i] << ", ";
    cout << endl;
    
    delete [] nums_a;
    delete [] nums_b;
    delete [] _nums_concat_ab;
    return 0;
}
