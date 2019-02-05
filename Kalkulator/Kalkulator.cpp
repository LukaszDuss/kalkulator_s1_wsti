﻿/*
- brak obslugi linii polecen
- ZROBIONE

- brak polskich liter zamiast nich "krzaczki", to trzeba poprawic lub zrezygnowac z PL znakow \
-SKASOWAC POLSKIE ZNAKI

- przy wyliczaniu % malo jasne komunikaty dla usera
-Zmienic

- logarytmowanie, jakie ln czy log ? dziala nieprawidlowo!
-WAZNE

- brak obslugi bledow np mnozenie 23 * a daje 0
-WAZNE (wszystkie cin & input cmd line)

- przydalo by sie dodac jeszcze opcje ile miejsc po przecinku wyswietla kalk
-ZROBIONE



cout << "Poprawna skladnia kalkulatora to {liczba} {operator} {liczba} {dokladnosc}\n"
					<< "Obslugiwane dzialania matematyczne:\n"
					<< "\t + \tDodawanie\n"
					<< "\t - \tOdejmowanie\n"
					<< "\t * \tMnozenie\n"
					<< "\t / \tDzielenie\n"
					<< "\t ^ \tPotegowanie\n"
					<< "\t p \tPierwiastkowanie\n"
					<< "\t % \tProcent\n"
					<< "\t o \tOdwrotnosc\n"
					<< "\t l \tLogarytmowanie\n"
					<< "\t s \tSinus\n"
					<< "\t c \tCosinus\n"
					<< endl;
*/

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <limits>

const double PI = 3.14159265358979323846;

using namespace std;
/*
double IsNumber(double number) {
	if (isdigit(number) != 0){
		return number;
	} else {
		cout << "To nie jest liczba... Sprobuj ponownie:" << endl;
		cin >> number;
		IsNumber(number);
	}
}
*/

void UstawDokladnosc()
{
	double n;
	cout << "Podaj ilosc wyswietlanych liczb po przecinku: " << endl;
	cin >> n;
	if (n <= 32000 && n >= 0)
	{
		cout.precision(n);
	}
	else
	{
		cout << "Poza zakresem! Podaj jeszce raz..." << endl;
		UstawDokladnosc();
	}
	cout << "Dokladnosc ustawiona na: " << n << " miejsc po przecinku" << endl;
}

void Dodawanie(double x, double y)
{
	double wynik = x + y;
	cout << "Suma wynosi: " << fixed << wynik << endl;
}

void Odejmowanie(double x, double y)
{
	double wynik = x - y;
	cout << "Roznica wynosi: " << fixed << wynik << endl;
}

void Mnozenie(double x, double y)
{
	double wynik = x * y;
	cout << "Iloczyn wynosi: " << fixed << wynik << endl;
}

void Dzielenie(double x, double y)
{
	if (y == 0)
	{
		cout << "Nie dzielimy przez zero!\n";
	}
	else
	{
		if (x == 0)
		{
			cout << "Iloraz wynosi: 0" << endl;
		}
		else
		{
			double wynik = x / y;
			cout << "Iloraz wynosi: " << fixed << wynik << endl;
		}
	}
}

void Potegowanie(double x, double a)
{
	if (x == 0 && a == 0)
	{
		cout << "Nie moge potegowac 0^0!" << endl;
	}
	else
	{
		double wynik = pow(x, a);
		cout << "Potega " << a << " stopnia z: " << x << " wynosi: " << wynik << endl;
	}
}

void Pierwiastkowanie(double x, double a)
{
	if (x < 0)
	{
		cout << "Kalkulator nie daje mozliwosci pierwiastkowania liczb ujemnych!" << endl;
	}
	else
	{
		double wynik = pow(x, 1 / a);
		cout << "Pierwiastek " << a << " stopnia z: " << x << " wynosi: " << wynik << endl;
	}
}

void Procenty(double x, double y)
{
	if (y == 0)
	{
		cout << "Nie dzielimy przez zero!\n";
	}
	else
	{
		double wynik = ((x / y) * 100);
		cout << "Procentowa wartosc: " << x << " z " << y << " wynosi: " << wynik << "%" << endl;
	}
}

void Odwrotnosc(double x)
{
	if (x == 0)
	{
		cout << "Nie dzielimy przez zero!\n";
	}
	else
	{
		double wynik = (1 / x);
		cout << "Odwrotnosc liczby " << x << " wynosi: " << wynik << endl;
	}
}

void Logarytmowanie(double x, double a)
{ // need fix
	if (a = 1 && a <= 0)
	{
		if (x <= 0)
		{
			cout << "Liczba logarytmowana musi byc wieksza od 0!";
		}
		else
		{
			cout << "Liczba podstawy logarytmu musi byc wieksza od 0 oraz rozna od 1!";
		}
	}
	else
	{
		double wynik = (log(x) / log(a));
		cout << "Logarytm o podstawie " << a << " z " << x << " wynosi: " << fixed << wynik << endl;
	}
}

void Sinus(double x)
{
	double wynik = sin(x * PI / 180);
	cout << "Sinus kata " << x << " wynosi: " << fixed << wynik << endl;
}

void Cosinus(double x)
{
	double wynik = cos(x * PI / 180);
	cout << "Cosinus kata " << x << " wynosi: " << fixed << wynik << endl;
}

void kalkulator(double a, char wybor, double b)
{
	switch (wybor)
	{
	case 'd':
	{
		UstawDokladnosc();
		system("pause");
		break;
	}
	case '+':
	{

		Dodawanie(a, b);
		system("pause");
		break;
	}
	case '-':
	{

		Odejmowanie(a, b);
		system("pause");
		break;
	}
	case '*':
	{

		Mnozenie(a, b);
		system("pause");
		break;
	}
	case '/':
	{

		Dzielenie(a, b);
		system("pause");
		break;
	}
	case '^':
	{

		Potegowanie(a, b);
		system("pause");
		break;
	}
	case 'p':
	{

		Pierwiastkowanie(a, b);
		system("pause");
		break;
	}
	case '%':
	{

		Procenty(a, b);
		system("pause");
		break;
	}
	case 'o':
	{

		Odwrotnosc(a);
		system("pause");
		break;
	}
	case 'l':
	{

		Logarytmowanie(a, b);
		system("pause");
		break;
	}
	case 's':
	{

		Sinus(a);
		system("pause");
		break;
	}
	case 'c':
	{

		Cosinus(a);
		system("pause");
		break;
	}
	default:
	{
		cout << "Niepoprawny operator!\n";
		system("pause");
		system("cls");
		break;
	}
	}
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "pl_PL");
	double dokladnosc = 2;
	float a;
	float b;
	char wybor;
	cout.precision(dokladnosc);

	system("CLS");

	if (argc != 1)
	{
		//for (int i = 0; i < argc; i++) {
		//cout << " what" << argv[i] << endl;
		//}
		cout << "Ilosc wprowadzonych argumentow: " << argc << endl;
		double xx;
		char cho;
		double yy;
		int prec;
		switch (argc)
		{
			//case 2: "HELP"
		case 4:
		{
			xx = atof(argv[1]);
			cho = *argv[2];
			yy = 0;
			prec = atoi(argv[3]);
			cout.precision(prec);
			cout << "Z dokladnoscia do: " << prec << " liczb po przecinku." << endl;
			cout << fixed << xx << endl;
			cout << cho << endl;
			break;
		}
		case 5:
		{
			xx = atof(argv[1]);
			cho = *argv[2];
			yy = atof(argv[3]);
			prec = atoi(argv[4]);
			cout.precision(prec);
			cout << "Z dokladnoscia do: " << prec << " liczb po przecinku." << endl;
			cout << fixed << xx << endl;
			cout << cho << endl;
			cout << fixed << yy << endl;
			break;
		}
		default:
		{
			cout << "Nieprawidlowa ilosc argumentow! \nUruchom program z poleceniem 'pomoc' aby uzyskac wiecej informacji..." << endl;
			system("pause");
			exit(0);
			break;
		}
		}

		kalkulator(xx, cho, yy);

		cout << "Zamykam program..." << endl;
		system("pause");
		exit(0);
	}
	else
	{

		cout << "Witaj w C++alkulatorze!\n"
			<< endl;
		UstawDokladnosc();
		system("pause");
		system("cls");

		for (;;)
		{

			system("cls");

			cout << "Wybierz operacje:\n"
				<< "\t d \tZmien dokladnosc\n"
				<< "\t + \tDodawanie\n"
				<< "\t - \tOdejmowanie\n"
				<< "\t * \tMnozenie\n"
				<< "\t / \tDzielenie\n"
				<< "\t ^ \tPotegowanie\n"
				<< "\t p \tPierwiastkowanie\n"
				<< "\t % \tProcent\n"
				<< "\t o \tOdwrotnosc\n"
				<< "\t l \tLogarytmowanie\n"
				<< "\t s \tSinus\n"
				<< "\t c \tCosinus\n"
				<< "\tq/Q \tAby wyjsc.\n"
				<< "\nWybieram: \t"
				<< endl;

			cin >> wybor;

			switch (wybor)
			{
			case 'd':
			{
				UstawDokladnosc();
				system("pause");
				break;
			}
			case '+':
			{
				cout << "Podaj pierwsza liczbe: ";
				scanf_s("%f", &a);
				//cin >> a;

				cout << "Podaj druga liczbe: ";
				cin >> b;

				Dodawanie(a, b);
				system("pause");
				break;
			}
			case '-':
			{
				cout << "Podaj pierwsza liczbe: ";
				cin >> a;

				cout << "Podaj druga liczbe: ";
				cin >> b;

				Odejmowanie(a, b);
				system("pause");
				break;
			}
			case '*':
			{
				cout << "Podaj pierwsza liczbe: ";
				cin >> a;

				cout << "Podaj druga liczbe: ";
				cin >> b;

				Mnozenie(a, b);
				system("pause");
				break;
			}
			case '/':
			{
				cout << "Podaj licznik: ";
				cin >> a;

				cout << "Podaj mianownik: ";
				cin >> b;

				Dzielenie(a, b);
				system("pause");
				break;
			}
			case '^':
			{
				cout << "Podaj stopien potegi: ";
				cin >> a;

				cout << "Podaj podstawe potegi: ";
				cin >> b;

				Potegowanie(a, b);
				system("pause");
				break;
			}
			case 'p':
			{
				cout << "Podaj stopien pierwiastka: ";
				cin >> a;

				cout << "Podaj liczbe pierwiastkowana: ";
				cin >> b;

				Pierwiastkowanie(a, b);
				system("pause");
				break;
			}
			case '%':
			{
				cout << "Podaj pierwsza liczbe: ";
				cin >> a;

				cout << "Podaj druga liczbe: ";
				cin >> b;

				Procenty(a, b);
				system("pause");
				break;
			}
			case 'o':
			{
				cout << "Podaj liczbe: ";
				cin >> a;

				Odwrotnosc(a);
				system("pause");
				break;
			}
			case 'l':
			{
				cout << "Podaj podstawe: ";
				cin >> a;

				cout << "Podaj liczbe logarytmowana: ";
				cin >> b;

				Logarytmowanie(a, b);
				system("pause");
				break;
			}
			case 's':
			{
				cout << "Podaj kat w stopniach: ";
				cin >> a;

				Sinus(a);
				system("pause");
				break;
			}
			case 'c':
			{
				cout << "Podaj kat w stopniach: ";
				cin >> a;

				Cosinus(a);
				system("pause");
				break;
			}
			case 'q':
			{
				cout << "Zamykam program..." << endl;

				exit(0);
				break;
			}
			case 'Q':
			{
				cout << "Zamykam program..." << endl;

				exit(0);
				break;
			}
			default:
			{
				cout << "Niepoprawny operator!\n";
				system("pause");
				break;
			}
			}
		}
	}
}