#include <iostream>
#include "lista.h"
#include "posortowanaLista.h"
#include "osoba.h"

using namespace std;

void next_test()
{
    cout << endl << "###################" << endl;
}

bool test_Lista_int_1()
{
    Lista<int, 10> a;
    cout << "liczba elementow: " << a.get_liczbe_elementow() << endl;
    a.dodaj_element_na_pozycje(2, 0);
    cout << "dodanie elementu int 2 na pozycje 0" << endl;
    cout << "element na miejscu 0: " << a[0] << endl;
    cout << "liczba elementow: " << a.get_liczbe_elementow() << endl;
    if (a[0] == 2) return true;
    else return false;
}    

bool test_Lista_int_2()
{
    Lista<int, 10> a;
    cout << "liczba elementow: " << a.get_liczbe_elementow() << endl;
    a.dodaj_element_na_pozycje(1, 0);
    a.dodaj_element_na_pozycje(2, 1);
    a.dodaj_element_na_pozycje(3, 2);
    cout << "liczba elementow: "<< a.get_liczbe_elementow() << endl;
    cout << "usuwanie z pozycji 1 czyli element z pozycji 2 (3) wejdzie na jego miejsce" << endl;
    a.usun_element_z_pozycji(1);
    cout << "element na miejscu 1: " << a[1] << endl;
    cout << "liczba elementow: " << a.get_liczbe_elementow() << endl;
    if (a[1] == 3 && a.get_liczbe_elementow() == 2) return true;
    else return false;
}

bool test_ListaPosortowana_int_1()
{
    PosortowanaLista<int, 10> b;
    b.dodaj_na_pozycje_i_posortuj(3, 0);
    b.dodaj_na_pozycje_i_posortuj(3, 1);
    b.dodaj_na_pozycje_i_posortuj(2, 1);
    b.dodaj_na_pozycje_i_posortuj(1, 2);
    cout << "liczba elementow: " << b.get_liczbe_elementow() << endl;
    cout << " Dodano w następujacej kolejnosci: 3, 3, 2, 1 " << endl;
    cout << "liczba elementow: "<< b.get_liczbe_elementow() << endl;
    cout << " Elementy na liscie posortowanej oraz po usunieciu duplikatow: " << endl;
    for (int i = 0; i < b.get_liczbe_elementow() ; i++)
    {
        cout << b[i] << endl;
    }
    if (b[0] == 1 && b[1] == 2 && b[2] == 3) return true;
    else return false;
}

bool test_ListaPosortowana_Osoba()
{
    Osoba o1;
    Osoba o2("Ola");
    Osoba o3("Jan");
    Osoba o4("Arkadiusz");
    Osoba o5("Zenon");
    Osoba o6("Grzegorz");
    Osoba o7("Kamil");
    PosortowanaLista<Osoba, 10> people;
    people.dodaj_na_pozycje_i_posortuj(o1, 0);
    people.dodaj_na_pozycje_i_posortuj(o2, 1);
    people.dodaj_na_pozycje_i_posortuj(o3, 2);
    people.dodaj_na_pozycje_i_posortuj(o4, 3);
    people.dodaj_na_pozycje_i_posortuj(o5, 4);
    people.dodaj_na_pozycje_i_posortuj(o6, 5);
    people.dodaj_na_pozycje_i_posortuj(o7, 6);
    cout << "Orginalna kolejnosc: Kamil, Ola, Jan, Arkadiusz, Zenon, Grzegorz, Kamil" << endl;
    cout << "liczba elementow po wyrzuceniu duplikatow: " << people.get_liczbe_elementow() << endl;
    for (int i = 0; i < people.get_liczbe_elementow(); i++)
    {
        cout << people[i].imie << endl;
    }
    if (people[0].imie == "Arkadiusz" && people[1].imie == "Grzegorz" && people[5].imie == "Zenon")
    {
        return true;
    }
    else return false;
}

int main()
{
    cout << "#########  Sprawdzenie klasy Lista  #########" << endl << endl;
    cout << "Test 1: " << test_Lista_int_1() << endl;
    next_test();
    cout << "Test 2: " << test_Lista_int_2() << endl;
    cout << endl << "#########  Sprawdzenie klasy dziedziczacej PosortowanaLista  #########" << endl << endl;
    cout << "Test 3: " << test_ListaPosortowana_int_1() << endl;
    next_test();
    cout << "Test 4: " << test_ListaPosortowana_Osoba() << endl;
}

