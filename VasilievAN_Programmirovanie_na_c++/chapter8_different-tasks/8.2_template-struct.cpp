/*
 * =====================================================================================
 *
 *       Filename:  8.2_template-struct.cpp
 *
 *    Description:  demonstrates using of template structs 
 *
 *        Version:  1.0
 *        Created:  06/29/2020 08:25:55 PM
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


template< typename T, typename Y >
struct MyStruct {
   T fst;
   Y snd;
};
template< typename T, typename Y >
void show(MyStruct<T,Y> obj)
{
   cout << "first:  " << obj.fst << endl;
   cout << "second: " << obj.snd << endl;
}


int main()
{
   MyStruct<int,char> struct_ia = { 100, 'A' };
   MyStruct<double,string> struct_ds = { 2.5, "sometext" };

   show(struct_ia);
   cout << endl;
   show(struct_ds);

   return 0;
}
