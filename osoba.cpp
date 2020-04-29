#include "osoba.h"

Osoba::Osoba(string i)
{
	imie = i;
}

bool Osoba::operator<(const Osoba osobaA)
{
	if (this->imie < osobaA.imie)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Osoba::operator>(const Osoba osobaA)
{
	if (this->imie > osobaA.imie)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Osoba::operator==(const Osoba osobaA)
{
	if (this->imie == osobaA.imie)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Osoba::operator!=(const Osoba osobaA)
{
	if (this->imie != osobaA.imie)
	{
		return true;
	}
	else
	{
		return false;
	}
}