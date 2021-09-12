/*
 * =====================================================================================
 *
 *       Filename:  5.r4_array.cpp
 *
 *    Description:  describes an array using class
 *
 *        Version:  1.0
 *        Created:  06/14/20 19:11:06
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

class Array {
public:
    int* arr;
    int n;
    Array(int* _arr, int _n) {
        arr = _arr;
        n = _n;
    }
    void sort() {
        int temp;
        for (int stop = n; stop > 0; stop--)
            for (int i = 0; i < stop - 1; i++)
                if (arr[i] > arr[i + 1]) {
                    temp = arr[i];
                    arr[i] = arr[i + 1];
                    arr[i + 1] = temp;
                }
    }
    void print() {
        for (int i = 0; i < n; i++)
            cout << arr[i] << ", ";
        cout << endl;
    }
};

int main() {
    int arr[8] = { 4, 2, 6, 9, 1, 7, 8, 7 };
    Array mine(arr, 8); // arr - как оказалось, нельзя просто сунуть
    mine.print();       //   аргументом {4, 2...}

    mine.sort();
    mine.print();
    return 0;
}
