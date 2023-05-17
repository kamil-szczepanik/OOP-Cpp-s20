#pragma once
#include <iostream>

using namespace std;

class Osoba
{
public:
	string imie;
	Osoba(string i = "Kamil");
	bool operator<(const Osoba);
	bool operator>(const Osoba);
	bool operator==(const Osoba);
	bool operator!=(const Osoba);
};

