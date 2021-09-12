/*
 * =====================================================================================
 *
 *       Filename:  4.q10_point-polynomial.cpp
 *
 *    Description: computes a polynom for point
 *
 *        Version:  1.0
 *        Created:  06/02/20 22:26:57
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

const int size = 4;

int polynom(int arr[size], int x);
void polynom(int arr[size]);


int main()
{
    int arr[size] = { 5, 2, 6, 9 };
        for (int &x: arr)
            cout << x << ", ";
        cout << endl;

    cout << "The polynom of 2 for this array is " << polynom(arr, 2) << endl;
    cout << "The polynom coefs are ";   polynom(arr);
    return 0;
}


int polynom(int arr[size], int x)       // polynom - википедия говорит, что это
{                                       //   многочлен, но что-то на него не
    int sum   = 0,                      //   очень похоже. Я не очень люблю эти
        x_pow = 1;                      //   обобщения, когда 5 = 2*2 + 1
    for (int i = 0; i < size; i++) {    //   строится из y = ax^2 + bx + c, а
        for (int _ = 0; _ < i; _++)     //   тут даже само это выражение 
            x_pow *= x;                 //   строится из полинома
        sum += arr[i] * x_pow;
        x_pow = 1;
    }
    return sum;
}
void polynom(int arr[size])
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << ", ";
    cout << endl;
}
