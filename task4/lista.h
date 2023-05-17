#pragma once
#include <iostream>

using namespace std;

template <typename T, int N=10>
class Lista
{
protected:
	T* tablica;
	int liczba_elementow;

public:
	Lista();
	~Lista();

	
	T& operator[] (unsigned int ktory);
	void usun_element_z_pozycji(int d);
	void wyczysc_liste();
	int get_liczbe_elementow();
	const T* zwroc_niemodyfikowalna_tablice()const;
	void dodaj_element_na_pozycje(T, int);
};

template <typename T, int N>
Lista<T, N>::Lista()
{
	if (N <= 0) cout << "Rozmiar listy musi byc wiekszy od 0" << endl;
	else
	{
		this->liczba_elementow = 0;
		this->tablica = new T[N];
	}
	
}

template <typename T, int N>
Lista<T, N>::~Lista()
{
	delete[] tablica;
}

template <typename T, int N>
T& Lista<T, N>::operator[] (unsigned int ktory)
{
	if (ktory < liczba_elementow && liczba_elementow>0)
	{
		return tablica[ktory];
	}
	else
	{
		cout << "Nie ma zadnego elementu na tej pozycji" << endl;
	}
}

template <typename T, int N>
void Lista<T, N>::dodaj_element_na_pozycje(T element, int pozycja)
{
	if (liczba_elementow == 0 && liczba_elementow!=pozycja) cout << "Mozna dodac element tylko na pozycje: 0" << endl;
	else if (pozycja > liczba_elementow)
	{
		cout << "Mozna dodac element na pozycje od 0 do " << liczba_elementow << endl;
	}
	else if (pozycja > N) cout << "Nie mo¿na dodaæ - Lista jest pe³na" << endl;
	else
	{
		for (int i = liczba_elementow; i >= pozycja; i--)
		{
			tablica[i + 1] = tablica[i];
		}
		tablica[pozycja] = element;
		liczba_elementow++;
	}

}

template <typename T, int N>
int Lista<T, N>::get_liczbe_elementow()
{
	return liczba_elementow;
}

template <typename T, int N>
void Lista<T, N>::usun_element_z_pozycji(int pozycja)
{
	if (liczba_elementow == 0)
	{
		cout << "Lista jest pusta" << endl;
	}
	else
	{
		for (int i = pozycja; i <= liczba_elementow-1; i++)
		{
			tablica[i] = tablica[i + 1];
		}
		liczba_elementow--;
	}
	
}

template <typename T, int N>
void Lista<T, N>::wyczysc_liste()
{
	tablica = new T[N];
	liczba_elementow = 0;
}

template <typename T, int N>
const T* Lista<T, N>::zwroc_niemodyfikowalna_tablice()const
{
	return tablica;
}