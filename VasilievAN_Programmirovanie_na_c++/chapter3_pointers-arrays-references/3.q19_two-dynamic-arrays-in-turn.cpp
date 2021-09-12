/*
 * =====================================================================================
 *
 *       Filename:  3.q19_two-dynamic-arrays-in-turn.cpp
 *
 *    Description: creates two dynamic arrays with a same size and fills them
 *                 using random. Then creates third array and fills it with
 *                 elements from first two in turn: a1, b1, a2, b2 ... 
 *
 *        Version:  1.0
 *        Created:  05/25/20 18:35:36
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

void arr_show(int *_arr, int _size)
{
    for (int i = 0; i < _size; i++)
        cout << _arr[i] << ", ";
    cout << endl;
}

int main()
{
    srand(8);
    const int size = 6;

    int *nums_a = new int[size],
        *nums_b = new int[size];
        for (int i = 0; i < size; i++) {
            nums_a[i] = rand() % 10;
            nums_b[i] = rand() % 10;
        }
        cout << "First:  ";     arr_show(nums_a, size);
        cout << "Second: ";     arr_show(nums_b, size);
    int *_nums_turn_ab = new int[size*2];
    
    int *start = _nums_turn_ab;
    for (int i = 0; i < size; i++) {
        *start++ = nums_a[i];
        *start++ = nums_b[i];
    }

    cout << "Second through first: ";  arr_show(_nums_turn_ab, size*2);

    delete [] nums_a;
    delete [] nums_b;
    delete [] _nums_turn_ab;
    return 0;
}
