/*
 * =====================================================================================
 *
 *       Filename:  8.5_valarray_polynom.cpp
 *
 *    Description:  describes polynom using valarray 
 *
 *        Version:  1.0
 *        Created:  06/29/2020 09:46:00 PM
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <valarray>
#include <cassert>   // cassert - а можно и <assert.h>. Совместимость с Си
using namespace std; //   работает


class Polynom {
   valarray<double> arr;   // arr - здесь нельзя воспользоваться скобками для
                           //   задействия конструктора с параметрами
   public:
      Polynom(int power = 0) {
         assert(power >= 0 && "Bad size");
         arr.resize(power + 1, 0);
      }  // assert - valarray не делает проверки на размер
         // && - так можно выводить сообщение при ошибке. Это помогает, когда
         //   условие не говорит за себя
         // resize - первым параметром принимает новый размер (он может стать
         //   даже меньше), а вторым (необязательный) - новый заполнитель
      Polynom(double *_arr, power) {
         valarray<double> new_arr(_arr, 1 + power);
         arr = new_arr;               
      }

      void print() const {
         cout << "| ";
         for (double i = 0; i < arr.size(); i++) {
            cout << arr[i] << " | ";
         }
         cout << endl;
      }
      int power() const {
         return arr.size() - 1;
      }

      double operator()(double x) const {
         valarray<double> arr_copy(arr);
         double q = x;
         for (int i = 1; i < arr.size(); i++) {
            arr_copy[i] *= q;
            q *= x;
         }
         return arr_copy.sum();
      }
      double& operator[](int i) {
         return arr[i];
      }
      Polynom operator* (Polynom right) const {
         Polynom ans(power() + right.power());
         for (int i = 0; i <= power(); i++) {
            for (int k = 0; k <= right.power(); k++)
               ans[i + k] += arr[i] * right[k];
         }
         return ans;
      }
      Polynom operator+ (Polynom right) {
         Polynom ans(power() > right.power() ? power() : right.power());
         for (int i = 0; i <= power(); i++) {
            ans[i] += arr[i];
         }
         for (int i = 0; i <= right.power(); i++) {
            ans[i] += right[i];
         }
         return ans;
      }
};
Polynom operator* (Polynom left, double right)
{
   for (int i = 0; i <= left.power(); i++) {
      left[i] *= right;
   }
   return left;
}
Polynom operator* (double left, Polynom right)
{
   return right * left;
}
Polynom operator- (Polynom left, Polynom right)
{
   return left + (-1)*right;
}
Polynom diff(Polynom pol)
{
   Polynom ans(pol.power() - 1);
   for (int i = 0; i <= ans.power(); i++) {
      ans[i] = pol[i + 1] * (i + 1);
   }
   return ans;
}


int main()
{
   double coefs_1[4] = { 1, 2, -1, 1 };
   double coefs_2[6] = { -1, 3, 0, 2, -1, 1 };

   Polynom P(coefs_1, 3);
   double x = 2;

   printf("P:     ");   P.print();
   printf("P(%.2f): %.2f\n", x, P(x));
   printf("P':    ");   diff(P).print();
   printf("P'(%.2f): %.2f\n", x, diff(P)(x));
   
   Polynom Q(coefs_2, 5);

   printf("Q:     ");   Q.print();
   printf("Q(%.2f): %.2f\n", x, Q(x));

   printf("Q*P:   ");   (Q * P).print();
   printf("(Q*P)(%.2f): %.2f\n", x, (Q * P)(x));
   printf("Q+P:   ");   (Q + P).print();
   printf("(Q+P)(%.2f): %.2f\n", x, (Q + P)(x));
   printf("Q-P:   ");   (Q - P).print();
   printf("(Q-P)(%.2f): %.2f\n", x, (Q - P)(x));

   return 0;
}
