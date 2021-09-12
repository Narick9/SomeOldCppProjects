/*
 * =====================================================================================
 *
 *       Filename:  5.q2_complex-nums.cpp
 *
 *    Description:  describes complex numbers using class 
 *
 *        Version:  1.0
 *        Created:  06/09/20 15:44:06
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
#include <cstring>
using namespace std;

class ComplexNum {
    public:
        float real;
        float image;
        ComplexNum(float _real, float _image) {
            real = _real;
            image = _image;
        }
//---------------------------------------------------------
        ComplexNum operator+ (ComplexNum right) {
            ComplexNum ans(real + right.real,
                           image + right.image);
            return ans;
        }
        ComplexNum operator- (ComplexNum right) {
            ComplexNum ans(real - right.real,
                           image - right.image);
            return ans;
        }
        ComplexNum operator* (ComplexNum right) {
            ComplexNum ans(real*right.real - image*right.image,
                           real*right.image + right.real*image);
            return ans;
        }
        ComplexNum operator/ (ComplexNum right) {
            float common_divisor = pow(right.real, 2) + pow(right.image, 2);
            ComplexNum ans(
                (real*right.real + image*right.image) / common_divisor,
                (right.real*image - real*right.image) / common_divisor);
            return ans;
        }
        void print_algebric_representation() {
            int real_accur  = 2;
            int image_accur = 2;
                if (real == (int)real)
                    real_accur = 0;
                if (image == (int)image)
                    image_accur = 0;
            char sign = '+';
                if (image < 0)
                    sign = '-';
            printf( "%.*f %c %.*fi\n",
                    real_accur, real, sign, image_accur, abs(image));
        }
};
class ComplexNumTrigonometry :public ComplexNum {
    public:
        ComplexNumTrigonometry(float _real, float _image)
            : ComplexNum(_real, _image) {
        }
        void print_exponantial_representation() {
            float r     = sqrt(real*real + image*image);
            float angle = asin(image / r);
            int r_accur     = 2;
            int angle_accur = 2;
                if (r == (int)r)
                    r_accur = 0;
                if (angle == int(angle))
                    angle_accur = 0;
            printf("|%.*f| * e^%.*fi\n", r_accur, r, angle_accur, angle);
        }
};


int main()
{
    ComplexNum a(2, 3);
        cout << "a: ";  a.print_algebric_representation();
    ComplexNum b(5, -7);
        cout << "b: ";  b.print_algebric_representation();
    cout << "a + b: ";  (a + b).print_algebric_representation();
    cout << "a - b: ";  (a - b).print_algebric_representation();
    cout << "a * b: ";  (a * b).print_algebric_representation();
    cout << "a / b: ";  (a / b).print_algebric_representation();

    ComplexNumTrigonometry c(5, 4);     // 5, 4 - странно, но нельзя просто 
                                        //   взять и написать a = Com..Trigo..,
                                        //   точнее можно, но тип не поменяется,
                                        //   при этом принимая значения 5 и 4.
                                        //   Компилятору тоже всё нравится
        cout << "c (in exponential representation: ";
            c.print_exponantial_representation();
    return 0;
}
