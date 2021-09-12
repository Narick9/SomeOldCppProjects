/*
 * =====================================================================================
 *
 *       Filename:  5.q4_car.cpp
 *
 *    Description:  describes a car with classes
 *
 *        Version:  1.0
 *        Created:  06/12/20 20:33:31
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

class Car {
    public:
        string model;
        string colour;
        int fuel_tank_capacity;
        float consumption_per_100_km;
        Car(string _model, string _colour, int _fuel_tank_capacity,
                float _consumption_per_100_km) {
            model  = _model;
            colour = _colour;
            fuel_tank_capacity     = _fuel_tank_capacity;
            consumption_per_100_km = _consumption_per_100_km;
        }
//      --------------------------------------------------------------
        void print_describe() {
            cout << "model                                    "
                 << model << endl;
            cout << "colour                                   "
                 << colour << endl;
            cout << "fuel tank capacity (in liters)           "
                 << fuel_tank_capacity << endl;
            cout << "fuel consumption per 100 km (in liters)  "
                 << consumption_per_100_km << endl;
            cout << "maximum driving range                    "
                 << get_max_driving_range() << endl;
        }
        float get_max_driving_range() {
            return fuel_tank_capacity / (consumption_per_100_km/100);
        }
};
class Truck :public Car {
    public:
        float carrying_capacity_in_tons;
        Truck(string _model, string _colour, int _fuel_tank_capacity,
                float _consumption_per_100_km, float _carrying_capacity_in_tons)
                : Car(_model, _colour, _fuel_tank_capacity,
                      _consumption_per_100_km) {
            carrying_capacity_in_tons = _carrying_capacity_in_tons;
        }
//      --------------------------------------------------------------
        float get_cost_of_moving_one_ton_per_km(float cost_of_fuel_liter) {
            return consumption_per_100_km/100 * cost_of_fuel_liter /
                carrying_capacity_in_tons;
        }
//      --------------------------------------------------------------
        Truck operator+ (Truck right) {
            string ans_colour = (colour[0] <= 'm') ? colour : right.colour;
            int ans_tank = fuel_tank_capacity + right.fuel_tank_capacity;
            float ans_consumption =
                (consumption_per_100_km + right.consumption_per_100_km)/2;
            float ans_capacity =
                (carrying_capacity_in_tons > right.carrying_capacity_in_tons)
                ? carrying_capacity_in_tons : right.carrying_capacity_in_tons;
            Truck ans(model + " / " + right.model,  // + - string гораздо более
                      ans_colour,                   //   гибок чем массив char
                      ans_tank,
                      ans_consumption,
                      ans_capacity);
            return ans;
        }
};


int main()
{
    Car mine("Daewoo Nexia", "black", 50, 6.7);
        mine.print_describe();  cout << endl;
    Truck iveco("Iveco Eurocargo ML180E28", "white", 200, 16., 11.885);
        iveco.print_describe();
        cout << "transportation soct of 1 ton per km      "
             << iveco.get_cost_of_moving_one_ton_per_km(46.49) << endl;
        cout << endl;
    Truck man("MAN TGM", "silver", 250, 21.3,  26.);
        man.print_describe();   cout << endl;
    cout << "       MAN + Iveco hybrid:" << endl;
        (man + iveco).print_describe();
    return 0;
}
