#pragma once
#include <iostream>
#include <vector>

using namespace std;


class Complex_number
{
	float x, y;

public:
	
	// VECTOR
	static vector<string> last_values;

	static void add_to_last_values(string changes);
	static void show_last_values();

	// KONSTRUKTORY
	Complex_number(double a, double b);
	Complex_number();

	// METODY
	string complex_to_string() const;

	// OPERATORY
	friend ostream& operator<< ( ostream &out, const Complex_number &z);

	Complex_number operator+ (const Complex_number& z) const;
	Complex_number operator+ (const int& z);
	Complex_number operator+ (const double& z);

	Complex_number operator- (Complex_number& z);
	Complex_number operator- (int& z);
	Complex_number operator- (double& z);

	bool operator==(const Complex_number& z);
	bool operator==(const int& z);
	bool operator==(const double& z);

	bool operator!=(const Complex_number& z);
	bool operator!=(const int& z);
	bool operator!= (const double & z);

	Complex_number operator++ (int);
	Complex_number operator++ ();
	Complex_number operator-- ();
	Complex_number operator-- (int);

	Complex_number operator* (Complex_number& z);
	Complex_number operator* (int& z);
	Complex_number operator* (double& z);
};

