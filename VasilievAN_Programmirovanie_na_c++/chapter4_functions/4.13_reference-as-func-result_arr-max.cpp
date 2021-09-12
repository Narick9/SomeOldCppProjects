/*
 * =====================================================================================
 *
 *       Filename:  4.13_reference-as-funs-result_arr-reference-max.cpp
 *
 *    Description:  creates and int array and demonstrates using func returning
 *                  reference of max
 *
 *        Version:  1.0
 *        Created:  05/30/20 22:55:41
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

void show(int *_arr, int _size);
int& get_max(int *_arr, int _size);


int main()
{
    const int size = 10;

    int nums[size] = {1, 5, 8, 2, 4, 9, 11, 9, 12, 3};
        show(nums, size);
    
    int max = get_max(nums, size);      // int = &int - да, можно делать и так
        cout << "Max is " << max << endl;

    max = -100;
    show(nums, size);

    int &r_max = get_max(nums, size);
        cout << "Max is " << r_max << endl;

    r_max = -200;
    show(nums, size);

    cout << "Max is " << get_max(nums, size) << endl;

    return 0;
}


void show(int *_arr, int _size)
{
    for (int i = 0; i < _size; i++)
        cout << _arr[i] << ", ";
    cout << endl;
}

int& get_max(int *_arr, int _size)
{
    int max_id = 0;
    for (int i = 1; i < _size; i++)
        if (_arr[i] > _arr[max_id])
            max_id = i;
    return _arr[max_id];    // return - понятно, что нет смысла передавать
}                           //   ссылку на локальную переменную, которая
                            //   существует только пока выполняется функция.
                            //   Да, это выглядит так, как будто мы передаём
                            //   копию обычной переменной, но, т.к. для функции
                            //   мы поставили тип возврата int&, то возвращаем
                            //   мы именно ссылку
