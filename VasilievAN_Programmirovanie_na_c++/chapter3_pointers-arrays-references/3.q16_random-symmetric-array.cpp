/*
 * =====================================================================================
 *
 *       Filename:  3.q16_random-symmetric-array.cpp
 *
 *    Description: creates a dynamic array with random size and fills it
 *                 symmetrically on both sides from one 
 *
 *        Version:  1.0
 *        Created:  05/25/20 17:40:43
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    srand(5);

    int size = rand() % 100;
        printf("The size is %i\n", size);
    int *_arr = new int[size];
    
    int i;
    for (i = 0; i < size/2; i++)
        _arr[i] = _arr[size - 1 - i] = i + 1;
    if (size % 2)
        _arr[size/2] = i + 1;

    for (int i = 0; i < size; i++)
        printf("%*i, ", 2, _arr[i]);
    puts("");

    delete [] _arr;
    return 0;
}
