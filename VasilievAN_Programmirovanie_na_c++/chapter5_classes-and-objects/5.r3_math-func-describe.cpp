/*
 * =====================================================================================
 *
 *       Filename:  5.r3_math-func-describe.cpp
 *
 *    Description:  describes given func using classes
 *
 *        Version:  1.0
 *        Created:  06/14/20 16:47:07
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

class MathFunc {
    public:
        float (*func)(float);
        MathFunc(float (*_func)(float)) {
            func = _func;
        }
        float get_derivative_1(float x) {
            return ( func(x + 0.01) - func(x) )/0.01;
        }
        float get_result(float x) {
            return func(x);
        }
};


float y(float x)
{
    return x*x;
}

int main()
{
    MathFunc y_describe(&y);
    cout << "Func: y(x) = x^2" << endl;

    cout << "Derivative for x = 3: " << y_describe.get_derivative_1(3) << endl;
    cout << "y(2):                 " << y_describe.get_result(2) << endl;
    return 0;
}
