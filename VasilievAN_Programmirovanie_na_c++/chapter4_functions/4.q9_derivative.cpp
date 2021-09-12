/*
 * =====================================================================================
 *
 *       Filename:  4.q9_derivative.cpp
 *
 *    Description: computes a derivatives use overload funcs 
 *
 *        Version:  1.0
 *        Created:  06/02/20 20:36:12
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

const int size     = 4,
          accuracy = 100;

double mult_2(double n);
double derivative(double (*func)(double), double x);
void derivative(double (*func)(double), double arr[size], double output[size]);


int main()
{
    cout << "accuracy: " << accuracy << endl;
    cout << "f(x) = x*x" << endl;
    cout << endl;

    cout << "f'(6):   " << derivative(mult_2, 6) << endl;

    double nums[size] = {5, 4, 5, 2};
        cout << "arr:     ";
        for (double &x: nums)
            cout << x << ", ";
        cout << endl;
    double derivatives[size];
        cout << "f'(arr): ";
        derivative(mult_2, nums, derivatives);
        for (double &x: derivatives)
            cout << x << ", ";
        cout << endl;

    return 0;
}


double mult_2(double n)
{
    return n * n;
}

double derivative(double (*func)(double), double x)
{
    double delta = 1./accuracy;                 // 1. - да, так можно было
    return ( func(x+delta) - func(x) )/delta;   // derivative - производная, в
}                                               //   переводе с английского.
                                                //   Простейший её пример - это
                                                //   спидометр в автомобиле.
                                                //   Как он может знать, что
                                                //   твоя скорость 60 км/ч,
                                                //   если часа не прошло? Это
                                                //   можно расчитать, если
                                                //   посмотреть то, сколько ты
                                                //   проедешь за кусочек
                                                //   времени поменьше, допустим
                                                //   за минуту, и умножить этот
                                                //   кусок на 60, т.к. в часе
                                                //   60 минут. Чем меньший
                                                //   кусок времени ты возьмёшь,
                                                //   тем точнее будет спидометр
void derivative(double (*func)(double), double arr[size], double output[size])
{                                               // double arr[4] - массивы уже
    for (int i = 0; i < size; i++)              //   не переводятся из int в
        output[i] = derivative(func, arr[i]);   //   double так легко. Да, я
}                                               //   попытался передать int[4]
