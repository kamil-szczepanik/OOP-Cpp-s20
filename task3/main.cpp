#include "Complex_number.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


int main()
{
    cout << endl <<"   ### Complex_number class demo ###   " << endl << endl;


    cout << "  === Constructor: === " << endl;
    Complex_number z1(1, -1);
    cout << "  # z1: " << z1 << endl;
    Complex_number z2(-1.5, -3.443);
    cout << "  # z2: " << z2 << endl;
    Complex_number z3;
    cout << "  # z3: (deafult constructor): " << z3 << endl;

    cout << "  === Operators: === " << endl;
    Complex_number a(1, 1);
    Complex_number b(-2, 1);
    int c = 3;
    double d = -2.5;
    a + b;
    a + c;
    a + d;
    a - b;
    a - c;
    a - d;
    a * b;
    a * c;
    a * d;
    a == b;
    a != b;
    a == c;
    a != c;

    a++;
    ++a;
    a--;
    --a;

   // Equations are displayed by method 'show_last_values'
    Complex_number::show_last_values();


}
