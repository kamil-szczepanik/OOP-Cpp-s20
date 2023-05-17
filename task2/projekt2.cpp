#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

//----------------------------------------
// Funkcja ktorej miejsce zerowe obliczamy
// f(x) = x^2 - sin(x) - 1
// <-1;0> i <1,2>
//----------------------------------------

double f(double x)
{
    return x * x - sin(x) - 1;
}


//--------------------------------
// Funkcja obliczajaca pierwiastek
//--------------------------------

double* root(double x1, double x2, double eps)
{
    cout << setprecision(16);

    double x0;
    double array_with_ten_last_aproximations_and_x[65];
    int i;

    //cout << "Obliczanie pierwiastka funkcji - metoda siecznych \n"
    //    "f(x) = x^2 - sin(x) - 1\n"
    //    "--------------------------------------------------\n";
    while (eps == 0)
    {
        cout << "\nWartosc E nie jest poprawna\n";
        //cout << "E = "; cin >> eps;
        return 0;
    }
    while (x1 == x2)
    {
        cout << "\nWartosc punktow poczatkowych nie jest poprawna\n";
        //cout << "Wpisz wartosc inna niz " << x1 << "\n x2 = "; cin >> x2;
        return 0;
    }

    if (fabs(x1 - x2) > eps)
    {
        i = 64; // zmienna zabezpieczająca przed nieskończoną pętlą while

        while (i && (fabs(x1 - x2) > eps))
        {
            if (fabs(f(x1) - f(x2)) < eps)
            {
                cout << "\nNiepoprawne punkty startowe\n";
                i = 0;
                return 0;
            }
            x0 = x1 - f(x1) * (x1 - x2) / (f(x1) - f(x2)); // wzor na kolejne przyblizenie
            if (fabs(f(x0)) < eps) break;

            x2 = x1;
            x1 = x0;
            array_with_ten_last_aproximations_and_x[64 - i] = x0;
            --i;

            if (i == 0)
            {
                cout << "\nPrzekroczony limit obiegow\n";
                return 0;
            }
        }
        i++;

        double solution_array[11];
        solution_array[0] = x0;
        //if (i) cout << "x0 = " << x0 << endl;
        //cout << "\n\n";
        //cout << "10 ostatnich przyblizen: \n" << endl;
        for (int k = 1; k < 11; k++)
        {
            //cout << k << ". " << array_with_ten_last_aproximations_and_x[64 - i - k] << endl;
            solution_array[k] = array_with_ten_last_aproximations_and_x[64 - i - k];
        }
        return solution_array; // zwracanie wskaznika do pierwszego elementu tablicy
                               // z pierwiastkiem rownania oraz 10 przyblizeniami
    }
    else
    {
        cout << "\nNiepoprawne punkty startowe\n";
        return 0;
    }
}
//----------------
// Funckje testowe
//----------------
bool test_of_root_function_1(double x1, double x2, double eps, int num_of_approximation)
{
    if (fabs(f(root(x1, x2, eps)[num_of_approximation])) <= eps) return true;
    else return false;
}

bool test_of_root_function_2(double x1, double x2, double eps, int num_of_approximation)
{
    if (fabs(f(root(x1, x2, eps)[num_of_approximation])) >= eps) return true;
    else return false;
}

bool test_of_root_function_x1_is_x2(double x1, double x2, double eps)
{
    if (root(x1, x2, eps)== 0) return true;
    else return false;
}

bool test_of_root_function_eps_is_0(double x1, double x2, double eps)
{
    if (root(x1, x2, eps) == 0) return true;
    else return false;
}

bool test_of_root_function_3(double x1, double x2, double eps)
{
    if (root(x1, x2, eps) == 0) return true;
    else return false;
}



int main()
{
    //root(-100, 100, 0.0000000000001)[0];
    
    cout << "\n\n========================================\nTesty: \n" << endl;

    cout << "Test 1: "; 
    cout << test_of_root_function_1(-100, 100, 0.0000000000001, 0) << endl;
    cout << "============\n";

    cout << "Test 2: ";
    cout << test_of_root_function_2(-100, 100, 0.0000000000001, 1) << endl;
    cout << "============\n";

    cout << "Test 3: ";
    cout << test_of_root_function_2(-100, 100, 0.0000000000001, 7) << endl;
    cout << "============\n";

    cout << "Test 4: ";
    cout << test_of_root_function_x1_is_x2(-100, -100, 0.0000000000001) << endl;
    cout << "============\n";

    cout << "Test 5: ";
    cout << test_of_root_function_eps_is_0(-100, 100, 0) << endl;
    cout << "============\n";

    cout << "Test 6: ";
    cout << test_of_root_function_3(0.001, 0.00101, 0.1) << endl;
    cout << "============\n";

    cout << f(0.001) << " ---\n";
    cout << f(0.00101) << " ---\n";
    cout << fabs(f(0.001) - f(0.00101)) << " ---\n";
    cout << fabs(0.001 - 0.00101) << " ---\n";
    return 0;
}
