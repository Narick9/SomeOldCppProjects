/*
 * =====================================================================================
 *
 *       Filename:  4.q6_exp.cpp
 *
 *    Description: computes exp with recursion func 
 *
 *        Version:  1.0
 *        Created:  06/01/20 18:39:04
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

double exp(double x, int n);


int main()
{
    cout << "Exp of 1 with accuracy 5 is " << exp(1, 5) << endl;
    cout << "Exp of 2 with accuracy 3 is " << exp(2, 3) << endl;
    return 0;
}


double exp(double x, int n)
{
    static double x_starter = 0;        // static - насколько я понял, автор
    if (x_starter == 0) {               //   хочет, чтобы в функции каждый раз
        if (x == 0)                     //   высчитывался новый x с нуля:
            return 1;                   //   1 + x + x^2/2! + x^3/3! ...
        x_starter = x;                  //   Я же сделал всё чуть сложнее, но
        for (int i = 2; i <= n; i++)    //   зато экономнее в плане ресурсов.
            x *= x_starter/i;           //   Пришлось подключить static для
    }                                   //   хранения стартовой информации
                                        //   Зачем я так всё усложнил здесь,
    if (n == 1) {                       //   при этом написав в прошлой
        x_starter = 0;                  //   программке о ненужности
        return 1 + x;                   //   усложнений? Дело в том, что здесь
    }                                   //   реально приходится немного
                                        //   попотеть. А лишний раз напрягать
                                        //   мозги полезно. Ну, я так считаю
    return exp(x/x_starter*n, n - 1) + x;
}
