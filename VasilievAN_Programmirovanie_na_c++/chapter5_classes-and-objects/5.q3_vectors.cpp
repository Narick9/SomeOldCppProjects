/*
 * =====================================================================================
 *
 *       Filename:  5.q3_vectors.cpp
 *
 *    Description:  describes vectors using classes
 *
 *        Version:  1.0
 *        Created:  06/12/20 11:53:00
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cmath>
using namespace std;

class Vector {
    public:
        float x;
        float y;
        Vector(float _x, float _y) {
            x = _x;
            y = _y;
        }
        void print_representation() {
            int x_accur = 2;
            int y_accur = 2;
                if (x == (int)x)
                    x_accur = 0;
                if (y == (int)y)
                    y_accur = 0;
            printf("(%.*f, %.*f)\n", x_accur, x, y_accur, y);
        }
        Vector operator+ (Vector right) {
            Vector ans(x + right.x,
                       y + right.y);
            return ans;
        }
        Vector operator- (Vector right) {
            Vector ans(x - right.x,
                       y - right.y);
            return ans;
        }
        float operator* (Vector right) {
            float left_angle = atan2(y, x);
                // atan2() - одна из функций для тригонометрии. Обычный atan()
                //   (т.е. арктангенс) принимает число и для него выводит угол
                //   в радианах. Но, т.к. для каждого такого числа есть два
                //   угла, то возникает неточность. Функция возвращает углы из
                //   1 и 4 координатных четвертях. Если передать аргументом 1,
                //   то она вернёт 0.78.. радиан, т.е. 45 градусов. Но ведь ещё
                //   подходит и 225 градусов, верно? По этой причине придумали
                //   второй вариант - atan2(). Она уже принимает вектора, а там
                //   неопределённостей уже нет. Только странно, что первым она
                //   принимает y. Скорее всего такой аналог есть и для других
                //   тригонометрических функций
            float right_angle = atan2(right.y, right.x);
            float ans = x * cos(right_angle - left_angle);
                if (ans == truncf(ans))         // truncf - это одна из четырёх
                    ans = truncf(ans);          //   функций округления. Она 
                else                            //   просто отбрасывает дробную
                    ans = roundf(ans*100)/100;  //   часть. Что значит f на 
            return ans;                         //   на конце? Это значит, что
        }                                       //   она принимает float и 
        Vector operator* (float right) {        //   возвращает тоже float. Ещё
            Vector ans(x * right,               //   есть просто trunc(),
                       y * right);              //   работающая с double, и
            return ans;                         //   truncl(), работаеющая с
        }                                       //   long double. Я даже не
        Vector operator/ (float right) {        //   знал, что есть такое. Оно
            return *this * (1/right);           //   занимает аж 80 бит, и 
        }                                       //   зовётся числом с плавающей
};                                              //   запятой четырёхкратной
class Vector3D :public Vector {                 //   точности.
    public:         // Ещё три функции округления - это floor(), округляющий
        float z;    // число до меньшего (2.6 -> 2.0). Ему не надо ставить f на
                    // конце, у него действует перегрузка. ceil() - это floor()
                    // наоборот (2.3 -> 3.0). Тоже перегружена. round() - это
                    // обычное человеческое округление (2.6 -> 3.0, 2.4 -> 2.0).
                    // Как и с trunc() существуют три разные функции с f и l на
                    // конце
        Vector3D(float _x, float _y, float _z) : Vector(_x, _y) {
            z = _z;
        }
        void print_representation() {
            int x_accur = 2;
            int y_accur = 2;
            int z_accur = 2;
                if (x == (int)x)    // (int) - да, разницы с trunc() нет. Ну
                    x_accur = 0;    //   только с trunc() может будет всё чутка
                if (y == (int)y)    //   быстрее, т.к. там не приходится делать
                    y_accur = 0;    //   двойное преобразование float -> int ->
                if (z == (int)z)    //   float. Хотя, кто знает, что там внутри
                    z_accur = 0;
            printf("(%.*f, %.*f, %.*f)\n", x_accur, x, y_accur, y, z_accur, z);
        }
        Vector3D operator+ (Vector3D right) {
            Vector3D ans(x + right.x,
                         y + right.y,
                         z + right.z);
            return ans;
        }
        Vector3D operator- (Vector3D right) {
            Vector3D ans(x - right.x,
                         y - right.y,
                         z - right.z);
            return ans;
        }
        float operator* (Vector3D right) {
            float ans = x*right.x + y*right.y + z*right.z; 
                if (ans == truncf(ans))
                    ans = truncf(ans);
                else
                    ans = round(ans*100)/100;
            return ans;
        }
        Vector3D operator* (float right) {
            Vector3D ans(x * right,
                         y * right,
                         z * right);
            return ans;
        }
        Vector3D operator/ (float right) {
            return *this * (1/right);
        }
};


int main()
{
    Vector a(4, 3);
        cout << "a:       ";    a.print_representation();
    Vector b(-2, 5);
        cout << "b:       ";    b.print_representation();
    cout << "a + b:   ";    (a + b).print_representation();
    cout << "a - b:   ";    (a - b).print_representation();
    cout << "a * b:   " << a * b << endl;
    cout << "a * 1.5: ";    (a * 1.5).print_representation();
    cout << "a / 2:   ";    (a / 2).print_representation();
    cout << endl;

    Vector3D c(3, 1, -7);
        cout << "c:        ";   c.print_representation();
    Vector3D d(1, 2, 8);
        cout << "d:        ";   d.print_representation();
    cout << "c + d:    ";   (c + d).print_representation();
    cout << "c - d:    ";   (c - d).print_representation();
    cout << "c * d:    " << c * d << endl;  // cout - у него есть интересное
                                            //   свойство обрасывать дробную
                                            //   часть, если она нулевая. Т.е,
                                            //   он выведет не  6.000000, как
                                            //   printf(), а просто 6
    cout << "c * 0.25: ";   (c * 0.25).print_representation();
    cout << "c / 3:    ";   (c / 3).print_representation();
    return 0;
}
