/*
 * =====================================================================================
 *
 *       Filename:  3.8_pointers_two-dim-like.cpp
 *
 *    Description: creates a pointers array and fills it using dynamic arrays 
 *
 *        Version:  1.0
 *        Created:  05/18/20 19:51:14
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
#include <cstdlib>

int main()
{
    srand(2);
    const int size = 5;
    const int dim_sizes[] = {3, 7, 6, 4, 2};

    int **nums = new int*[size];        // int **nums;  nums = new int*[size]
        for (int y = 0; y < size; y++) {
            nums[y] = new int[dim_sizes[y]];
            for (int x = 0; x < dim_sizes[y]; x++) {
                nums[y][x] = rand() % 10;
                cout << "| " << nums[y][x] << " ";
            }
            cout << "|" << endl;
        }
                    // пока читал про квалификаторы (это ключивые слова типа
                    // const, увидел такую вещь, как volatile. Это
                    // квалификатор, который сообщает компилятору, что не
                    // нужно оптимизировать код, связынный с этой переменной.
                    // Например код
                    // int i = 0;
                    // i += 1;
                    // i += 2;
                    // компилятор может превратить в int i = 3;, т.к. это
                    // банально экономит ресурсы. Но, это не всегда бывает
                    // полезно. Если твои переменные считывает какая-нибудь
                    // другая программка (такое бывает во встраиваемых
                    // системах - это немного другой мир), то она может
                    // получить 3 вместо ожидаемой 2-ки или 1-ки
   
    for (int i = 0; i < size; i++)      // как оказалось, цикл по коллекции
        delete [] nums[i];              // не работает с такого рода массивами,
    delete [] nums;                     // которые на самом деле указатели
    return 0;
}
