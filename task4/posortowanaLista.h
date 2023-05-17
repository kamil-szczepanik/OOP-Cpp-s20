#pragma once
#include <iostream>
#include "lista.h"

using namespace std;

template <typename T, int N=10>
class PosortowanaLista :
	public Lista<T,N>
{
private:
	using Lista<T, N>::dodaj_element_na_pozycje;
public:
	PosortowanaLista();
	void sortowanie();
	void wyrzuc_duplikaty();
	void dodaj_na_pozycje_i_posortuj(T, int);
};

template <typename T, int N>
PosortowanaLista<T, N>::PosortowanaLista() : Lista<T, N>::Lista() {};

template <typename T, int N>
void PosortowanaLista<T, N>::wyrzuc_duplikaty()
{
	for (int i = 0; i < this->liczba_elementow; i++)
	{ 
		if (this->tablica[i] == this->tablica[i + 1])
		{
			this->usun_element_z_pozycji(i);
		}
	}
}

template <typename T, int N>
void PosortowanaLista<T, N>::sortowanie()
{
	for (int i = 0; i < this ->liczba_elementow; i++)
	{
		for (int j = i+1; j < this->liczba_elementow; j++)
		{
			if (this->tablica[i] > this->tablica[j])
			{
				T pom = this->tablica[j];
				this->tablica[j] = this->tablica[i];
				this->tablica[i] = pom;
			}
		}
	}
}

template <typename T, int N>
void PosortowanaLista<T, N>::dodaj_na_pozycje_i_posortuj(T element, int pozycja)
{
	if (this->liczba_elementow == 0) dodaj_element_na_pozycje(element, 0);
	else
	{
		dodaj_element_na_pozycje(element, pozycja);
		sortowanie();
		wyrzuc_duplikaty();
	}

	
	
}
