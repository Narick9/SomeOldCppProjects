/*
 * =====================================================================================
 *
 *       Filename:  5.q1_parallelepiped.cpp
 *
 *    Description:  describes parallelepiped using class 
 *
 *        Version:  1.0
 *        Created:  06/08/20 20:10:44
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

class Parallelepiped {
    public:
        float lenght;
        float width;
        float height;
        Parallelepiped(float _lenght, float _width, float _height) {
            lenght = _lenght;
            width = _width;
            height = _height;
        }
        void show() {
            cout << "   lenght: " << lenght << endl;
            cout << "   width:  " << width << endl;
            cout << "   height: " << height << endl;
            cout << "   volume: " << get_volume() << endl;
        }
        float get_volume() {
            return lenght*width*height;
        }
};
class ParallelepipedWeight : public Parallelepiped {
    public:
        float weight;
        ParallelepipedWeight(float _lenght, float _width, float _height,
            float _weight) : Parallelepiped(_lenght, _width, _height) {
            weight = _weight;
        }
        void show() {
            cout << "   lenght:  " << lenght << endl;
            cout << "   width:   " << width << endl;
            cout << "   height:  " << height << endl;
            cout << "   weight:  " << weight << endl;
            cout << "   volume:  " << get_volume() << endl;
            cout << "   density: " << get_density() << endl;
        }
        float get_density() {
            return weight / get_volume();
        }
        ParallelepipedWeight operator/ (int right) {
            ParallelepipedWeight ans = *this;
            ans.weight /= right;
            return ans;
        }
        ParallelepipedWeight operator+ (ParallelepipedWeight right) {
            float side = pow(this->get_volume() + right.get_volume(), .333);
            ParallelepipedWeight ans(side, side, side,
                                     this->weight+right.weight);
            return ans;
        }
};


int main()
{
    Parallelepiped paral_a(2, 4, 6);
        cout << "paral_a:" << endl;
        paral_a.show();
    ParallelepipedWeight paralw_a(2, 4, 6, 10);
        cout << "paralw_a:" << endl;
        paralw_a.show();
    paralw_a = paralw_a / 2;
        cout << "paralw_a / 2" << endl;
        paralw_a.show();
    ParallelepipedWeight paralw_b(6, 4, 1, 10);
        cout << "paralw_b:" << endl;
        paralw_b.show();
    cout << "paralw_a + paralw_b: " << endl;
        (paralw_a + paralw_b).show();
    return 0;
}
