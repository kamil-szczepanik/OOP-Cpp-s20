#include "Complex_number.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// VECTOR
vector<string> Complex_number::last_values = vector<string>();

void Complex_number::add_to_last_values(string changes)
{
	last_values.push_back(changes);
}

void Complex_number::show_last_values()
{
	cout << "### Last Values ###" << endl;
	for (int i = 0; i < last_values.size(); i++)
		cout << last_values[i] << endl;
}

string number_number_to_string(double num) // funkcja pomocnicza
{
	stringstream ss;
	ss << num;
	string new_string = ss.str();
	return new_string;
}

// KONSTRUKTORY
Complex_number::Complex_number(double x, double y)
{
	this->x = x;
	this->y = y;
}


Complex_number::Complex_number()
{
	 x=0;
	 y=0;
}

// METODY
string Complex_number::complex_to_string() const
{
	string real = number_number_to_string(x);
	string imaginary = number_number_to_string(y);

	if (y == 0)
	{
		return real;
	}
	if (y < 0)
	{

		if (x != 0)
		{
			return (real + " + " + imaginary + "i");

		}
		else
		{
			return (imaginary + "i");
		}
	}
	if (y > 0)
	{
		if (x != 0)
		{
			return (real + " + " + imaginary + "i");
		}
		else
		{
			return (imaginary + "i");
		}
	}
	
}


// OPERATORY
ostream& operator<< (ostream& out, const Complex_number& z)
{
	if (z.y == 0)
	{
		out << z.x << endl;
		return out;
	}
	if (z.y < 0)
	{

		if (z.x != 0)
		{
			out << z.x << " " << z.y << "i" << endl;
			return out;
		}
		else
		{
			out << z.y << "i" << endl;
			return out;
		}
	}
	if (z.y > 0)
	{
		if (z.x != 0)
		{
			out << z.x << " + " << z.y << "i" << endl;
			return out;
		}
		else
		{
			out << z.y << "i" << endl;
			return out;
		}
	}

}
// +
Complex_number Complex_number::operator+ (const Complex_number& z) const
{
	Complex_number solution;
	add_to_last_values("Added: (" + Complex_number::complex_to_string() +")" + " + (" + z.complex_to_string()+ ")");
	solution.x = x + z.x;
	solution.y = y + z.y;
	string temp = solution.complex_to_string();
	add_to_last_values(temp);
	return solution;
}

Complex_number Complex_number::operator+ (const double& z)
{
	Complex_number solution(z, 0);
	add_to_last_values("Added: (" +  Complex_number::complex_to_string()+")" +  " + (" + solution.complex_to_string()+ ")");
	solution.x = x + solution.x;
	solution.y = y + solution.y;
	
	string temp = solution.complex_to_string();
	add_to_last_values(temp);
	return solution;
}

Complex_number Complex_number::operator+ (const int& z)
{
	Complex_number solution(z, 0);
	add_to_last_values("Added: (" + Complex_number::complex_to_string()+")" + " + (" + solution.complex_to_string()+ ")");
	solution.x = x + solution.x;
	solution.y = y + solution.y;
	string temp = solution.complex_to_string();
	add_to_last_values(temp);
	return solution;
}
// -
Complex_number Complex_number::operator- (Complex_number& z)
{
	Complex_number solution;
	add_to_last_values("Subtracted: (" + Complex_number::complex_to_string()+")" + " - (" + z.complex_to_string()+")");
	solution.x = x - z.x;
	solution.y = y - z.y;
	string temp = solution.complex_to_string();
	add_to_last_values(temp);
	return solution;
}

Complex_number Complex_number::operator- (double& z)
{
	Complex_number solution(z, 0);
	add_to_last_values("Subtracted: (" + Complex_number::complex_to_string()+")" + " - (" + solution.complex_to_string()+ ")");
	solution.x = x - solution.x;
	solution.y = y - solution.y;
	string temp = solution.complex_to_string();
	add_to_last_values(temp);
	return solution;
}

Complex_number Complex_number::operator- (int& z)
{
	Complex_number solution(z, 0);
	add_to_last_values("Subtracted: (" + Complex_number::complex_to_string()+")" + " - (" + solution.complex_to_string()+ ")");
	solution.x = x - solution.x;
	solution.y = y - solution.y;
	string temp = solution.complex_to_string();
	add_to_last_values(temp);
	return solution;
}
// == / !=
bool Complex_number::operator==(const Complex_number &z)
{
	add_to_last_values("Comparison: " + Complex_number::complex_to_string() + " == " + z.complex_to_string());
	int temp;
	if (x == z.x && y == z.y)
	{
		temp = 1;
	}
	else temp = 0;
	string temp2 = to_string(temp);
	add_to_last_values(temp2);
	return x == z.x && y == z.y;
}

bool Complex_number::operator==(const int& z)
{
	Complex_number num(z, 0);
	add_to_last_values("Comparison: " + Complex_number::complex_to_string() + " == " + num.complex_to_string());
	int temp = 0;
	if (y == 0)
	{
		if (x == num.x)
		{
			temp = 1;
		}
		else temp = 0;
		string temp2 = to_string(temp);
		add_to_last_values(temp2);
		return x == num.x && y == num.y;
	}
	string temp2 = to_string(temp);
	add_to_last_values(temp2);
	return 0;

}

bool Complex_number::operator==(const double& z)
{
	Complex_number num(z, 0);
	add_to_last_values("Comparison: " + Complex_number::complex_to_string() + " == " + num.complex_to_string());
	int temp=0;
	if (y == 0)
	{
		if (x == num.x)
		{
			temp = 1;
		}
		else temp = 0;
		string temp2 = to_string(temp);
		add_to_last_values(temp2);
		return x == num.x && y == num.y;
	}
	string temp2 = to_string(temp);
	add_to_last_values(temp2);
	return 0;
}

bool Complex_number::operator!=(const Complex_number& z)
{
	add_to_last_values("Comparison: " + Complex_number::complex_to_string() + " != " + z.complex_to_string());
	int temp;
	if (x == z.x && y == z.y)
	{
		temp = 0;
	}
	else temp = 1;
	string temp2 = to_string(temp);
	add_to_last_values(temp2);
	return x != z.x && y != z.y;
}

bool Complex_number::operator!=(const int& z)
{
	Complex_number num(z, 0);
	add_to_last_values("Comparison: " + Complex_number::complex_to_string() + " != " + num.complex_to_string());
	int temp=1;
	if (y != 0)
	{
		if (x == num.x)
		{
			temp = 0;
		}
		else temp = 1;
		string temp2 = to_string(temp);
		add_to_last_values(temp2);
		return x != num.x && y != num.y;
	}
	string temp2 = to_string(temp);
	add_to_last_values(temp2);
	return 1;
}

bool Complex_number::operator!=(const double& z)
{
	Complex_number num(z, 0);
	add_to_last_values("Comparison: " + Complex_number::complex_to_string() + " != " + num.complex_to_string());
	int temp=1;
	if (y != 0)
	{
		if (x == num.x)
		{
			temp = 0;
		}
		else temp = 1;
		string temp2 = to_string(temp);
		add_to_last_values(temp2);
		return x != num.x && y != num.y;
	}
	string temp2 = to_string(temp);
	add_to_last_values(temp2);
	return 1;
}

// ++
Complex_number Complex_number::operator++ (int)
{
	add_to_last_values("Increment: " + Complex_number::complex_to_string() + " + 1");
	Complex_number solution;
	solution.x = x++;
	solution.y = y;
	add_to_last_values(solution.complex_to_string());
	return solution;
}

Complex_number Complex_number::operator++ ()
{
	add_to_last_values("Increment: " + Complex_number::complex_to_string() + " + 1");
	Complex_number solution;
	solution.x = ++x;
	solution.y = y;
	add_to_last_values(solution.complex_to_string());
	return solution;
}
// --

Complex_number Complex_number::operator-- ()
{
	add_to_last_values("Increment: " + Complex_number::complex_to_string() + " - 1");
	Complex_number solution;
	solution.x = --x;
	solution.y = y;
	add_to_last_values(solution.complex_to_string());
	return solution;
}

Complex_number Complex_number::operator-- (int)
{
	add_to_last_values("Increment: " + Complex_number::complex_to_string() + " - 1");
	Complex_number solution;
	solution.x = x--;
	solution.y = y;
	add_to_last_values(solution.complex_to_string());
	return solution;
}
// *
Complex_number Complex_number::operator* (Complex_number& z)
{
	Complex_number solution;
	add_to_last_values("Multiplication: (" + Complex_number::complex_to_string() + ")" + " * " +"(" + z.complex_to_string() + ")");
	solution.x = x * z.x - y * z.y;
	solution.y = x * z.y + y * z.x;
	string temp = solution.complex_to_string();
	add_to_last_values(temp);
	return solution;
}

Complex_number Complex_number::operator* (double& z)
{
	Complex_number solution(z, 0);
	add_to_last_values("Multiplication: (" + Complex_number::complex_to_string() + ")" + " * "+ "(" + solution.complex_to_string() + ")");
	solution.x = x * z;
	solution.y = x * z;
	string temp = solution.complex_to_string();
	add_to_last_values(temp);
	return solution;
}

Complex_number Complex_number::operator* (int& z)
{
	Complex_number solution(z, 0);
	add_to_last_values("Multiplication: (" + Complex_number::complex_to_string()+")" + " * " + "(" +solution.complex_to_string()+")");
	solution.x = x * z;
	solution.y = x * z;
	string temp = solution.complex_to_string();
	add_to_last_values(temp);
	return solution;
}