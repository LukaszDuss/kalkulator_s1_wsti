/*
- brak obslugi linii polecen
- ZROBIONE

- brak polskich liter zamiast nich "krzaczki", to trzeba poprawic lub zrezygnowac z PL znakow \
- SKASOWAC POLSKIE ZNAKI - ZROBIONE

- przy wyliczaniu % malo jasne komunikaty dla usera
- DODANE - ZROBIONE

- logarytmowanie, jakie ln czy log ? dziala nieprawidlowo!
- POPRAWIONE - ZROBIONE

- brak obslugi bledow np mnozenie 23 * a daje 0
- DODANE - ZROBIONE

- przydalo by sie dodac jeszcze opcje ile miejsc po przecinku wyswietla kalk
- DODANE - ZROBIONE


	<< "Obslugiwane dzialania matematyczne:\n"
	<< "\t + \tDodawanie\n" -dziala 
	<< "\t - \tOdejmowanie\n" -dziala
	<< "\t * \tMnozenie\n" -dziala
	<< "\t / \tDzielenie\n" -dziala
	<< "\t ^ \tPotegowanie\n" -dziala
	<< "\t p \tPierwiastkowanie\n" -dziala
	<< "\t % \tProcent\n" -dziala
	<< "\t o \tOdwrotnosc\n" -dziala
	<< "\t l \tLogarytmowanie\n" -dziala
	<< "\t s \tSinus\n" -dziala
	<< "\t c \tCosinus\n" -dziala

*///

//===============================================//===============================================

#include "pch.h" // precompiled header
#include <iostream> // standard input/output stream objects
#include <stdlib.h> // C++ standard library
#include <math.h> // common mathematical operations and transformations
#include <regex> // regular expression library


//regex rw("([d\+\-\*/\^p%olscqQ])");

const double PI = 3.14159265358979323846; // stała PI zdefioniowana na początku programu

using namespace std; // deklaracja użycia przestrzeni nazw std::


//===============================================//===============================================
//Funkcja sprawdzania czy wprowadzone warotsci są liczbami (całkowite lub zmiennoprzecinkowe)
//Przyjmuje string - zwraca liczbe w double
//===============================================
double tylkoLiczby(string inputString) {
	string regexFloat = "((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?"; // wyrazenie regularne dla liczby zmiennoprzcinkowej 
	smatch regexMatch;
	double result;
	if (!regex_search(inputString, regexMatch, regex(regexFloat)))
	{
		cout << "Niepoprawna wartosc... sprobuj ponownie" << endl;
		cin >> inputString;
		tylkoLiczby(inputString);
	}
	result = stod(inputString);
	return result;
}

void tylkoLiczbyNoReturn(string inputString) {
	string regexFloat = "((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?"; // wyrazenie regularne dla liczby zmiennoprzcinkowej 
	smatch regexMatch;
	if (!regex_search(inputString, regexMatch, regex(regexFloat)))
	{
		cout << "Niepoprawna wartosc... sprobuj ponownie" << endl;
	}
	
}
//===============================================//===============================================
//Funkcja pobierająca i ustawiająca ilość wyświetlanych liczb po przecinku
//===============================================

void UstawDokladnosc() 
{
	string str;
	cout << "Podaj ilosc wyswietlanych liczb po przecinku: " << endl;
	cin >> str;

	double n;
	n = tylkoLiczby(str);
	
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

//===============================================//===============================================
//Funkcja dodawania
//===============================================

void Dodawanie(double x, double y)
{
	double wynik = x + y;
	cout << "Suma wynosi: " << fixed << wynik << endl;
}

//===============================================//===============================================
//Funkcja odejmowania
//===============================================

void Odejmowanie(double x, double y)
{
	double wynik = x - y;
	cout << "Roznica wynosi: " << fixed << wynik << endl;
}

//===============================================//===============================================
//Funkcja mnożenia
//===============================================

void Mnozenie(double x, double y)
{
	double wynik = x * y;
	cout << "Iloczyn wynosi: " << fixed << wynik << endl;
}

//===============================================//===============================================
//Funkcja dzielenia ze sprawdzeniem założeń zgodym z zasadami dzielenia
//===============================================

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

//===============================================//===============================================
//Funckcja potęgowania wykluczająca możliwość podnoszenia 0 do potęgi 0
//===============================================

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
//===============================================//===============================================
//Funkcja pierwiastkowania dowolnego stopnia w przestrzeni liczb rzeczywistych
//===============================================

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

//===============================================//===============================================
//Funkcja licząca procentową wartość liczby w stosunku do innej liczby
//===============================================

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

//===============================================//===============================================
//Funkcja licząca odwrotność liczby
//===============================================

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

//===============================================//===============================================
//Funkcja licząca logartym o dowolnej podstawie
//===============================================

void Logarytmowanie(double a, double x)
{ 
	if (a == 1) 
	{
		cout << "Liczba podstawy logarytmu musi byc rozna od 1!";
	}
	else if(a <= 0)
	{
		cout << "Liczba podstawy logarytmu musi byc wieksza od 0 oraz rozna od 1!";
	}
	else if (x <= 0)
	{
		cout << "Liczba logarytmowana musi byc wieksza od 0!";
	}
	//else if x=1??
	else
	{
		double wynik = (log(x) / log(a)); //check
		cout << "Logarytm o podstawie " << a << " z " << x << " wynosi: " << fixed << wynik << endl;
	}
}

//===============================================//===============================================
//Funkcja licząca sinus kąta
//===============================================

void Sinus(double x)
{
	double wynik = sin(x * PI / 180);
	cout << "Sinus kata " << x << " wynosi: " << fixed << wynik << endl;
}

//===============================================//===============================================
//Funkcja licząca cosinus kąta
//===============================================

void Cosinus(double x)
{
	double wynik = cos(x * PI / 180);
	cout << "Cosinus kata " << x << " wynosi: " << fixed << wynik << endl;
}

//===============================================//===============================================
//Funkcja wykorzystująca w/w funkcje odzwierciedlające operacje matematyczne 
// - wykorzysywane przy użyciu programu z wiersza poleceń
//===============================================

void kalkulator(double a, char wybor, double b)
{
	switch (wybor){
		case 'd':{
			UstawDokladnosc();
			system("pause");
			break;
		}case '+':{
			Dodawanie(a, b);
			system("pause");
			break;
		}case '-':{
			Odejmowanie(a, b);
			system("pause");
			break;
		}case '*':{
			Mnozenie(a, b);
			system("pause");
			break;
		}case '/':{
			Dzielenie(a, b);
			system("pause");
			break;
		}case '^':{
			Potegowanie(a, b);
			system("pause");
			break;
		}case 'p':{
			Pierwiastkowanie(a, b);
			system("pause");
			break;
		}case '%':{
			Procenty(a, b);
			system("pause");
			break;
		}case 'o':{
			Odwrotnosc(a);
			system("pause");
			break;
		}case 'l':{
			Logarytmowanie(a, b);
			system("pause");
			break;
		}case 's':{
			Sinus(a);
			system("pause");
			break;
		}case 'c':{
			Cosinus(a);
			system("pause");
			break;
		}default:{
			cout << "Niepoprawny operator!\n";
			system("pause");
			system("cls");
			break;
		}
	}
}


//===============================================//===============================================
//Funckja main przyjmująca argumenty z wiersza poleceń- Kalkulator.exe ${liczba} ${operacja} ${liczba} ${dokładność}
//===============================================

int main(int argc, char *argv[]) // main( ilość argumentów, tablica pointerów argumentów)
{
	setlocale(LC_ALL, "pl_PL"); // próba umożliwienia programowi wyświetlania polskich znaków --FAILED
	
	string inputA, inputB;
	double a, b;
	char wybor;
	double dokladnosc = 2; // domyślna dokładność 
	cout.precision(dokladnosc); // ustaw dokładność wyświetlania liczb domyślną

	system("CLS"); // wyczyść konsole

	if (argc != 1) // domyślnie pliki *.exe są uruchamiane z jednym argumentem - nazwą/ścieżką danego pliku *.exe
	{
		//cout << "Ilosc wprowadzonych argumentow: " << argc << endl; 
		double xx;
		char cho;
		double yy;
		int prec;
		switch (argc)
		{
			case 4: // w przypadku gdy chcemy skorzystać z obliczenia sinusa druga liczba jest zbędna - zostaje wyzerowana 
			{
				tylkoLiczbyNoReturn(argv[1]);
				tylkoLiczbyNoReturn(argv[3]);

				xx = stod(argv[1]); // atof zamienia typ danych string(char) na double 
				cho = *argv[2]; // przypisanie wartości zapisanej pod pointerem do zmiennej odpowiedzialej za wybór opracji matematycznej
				yy = 0; // zerowanie zbędnej (nie podanej) zmiennej
				prec = stoi(argv[3]); // ostatni argument jest deklaracją dokłądności wyświetlania liczb po przecinku 
				cout.precision(prec); // ustawienie dokładności wyświetlania
				cout << "Z dokladnoscia do: " << prec << " liczb po przecinku." << endl;
				cout << fixed << xx << endl;
				cout << cho << endl;
				break;
			}
			case 5: // analogicznie do case 4 
			{
				tylkoLiczbyNoReturn(argv[1]);
				tylkoLiczbyNoReturn(argv[3]);
				tylkoLiczbyNoReturn(argv[4]);

				xx = stod(argv[1]); 
				cho = *argv[2]; 
				yy = stod(argv[3]);
				prec = stoi(argv[4]);
				cout.precision(prec);
				cout << "Z dokladnoscia do: " << prec << " liczb po przecinku." << endl;
				cout << fixed << xx << endl;
				cout << cho << endl;
				cout << fixed << yy << endl;
				break;
			}
			default:
			{
				cout << "Nieprawidlowa ilosc argumentow!\n" 
					 << "Poprawna skladnia kalkulatora to:\n "
					 << "{liczba} {operator} {liczba}* {dokladnosc}" 
					 << "(*jeżeli wymagane)" << endl;
				system("pause");
				exit(0);
				break;
			}
		}

		kalkulator(xx, cho, yy); // wywołanie funkcji kalkulatora (liczba , operacja , liczba)

		cout << "Zamykam program..." << endl;
		system("pause"); // pozwala użytkownikowi zapoznać się z wyświetloną odpowiedzią przed zamknięciem programu
		exit(0);
	}
	else //===============================================//===============================================
	{
		cout << "Witaj w C++alkulatorze!\n"<< endl;
		UstawDokladnosc();

		system("pause");
		system("cls");

		for (;;) // pozwala na wyświetlanie "menu" programu pomimo czyszcznia konsoli
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
				cin >> inputA;
				a = tylkoLiczby(inputA);

				cout << "Podaj druga liczbe: ";
				cin >> inputB;
				b = tylkoLiczby(inputB);

				Dodawanie(a, b);
				system("pause");
				break;
			}
			case '-':
			{
				cout << "Podaj pierwsza liczbe: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				cout << "Podaj druga liczbe: ";
				cin >> inputB;
				b = tylkoLiczby(inputB);

				Odejmowanie(a, b);
				system("pause");
				break;
			}
			case '*':
			{
				cout << "Podaj pierwsza liczbe: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				cout << "Podaj druga liczbe: ";
				cin >> inputB;
				b = tylkoLiczby(inputB);

				Mnozenie(a, b);
				system("pause");
				break;
			}
			case '/':
			{
				cout << "Podaj licznik: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				cout << "Podaj mianownik: ";
				cin >> inputB;
				b = tylkoLiczby(inputB);

				Dzielenie(a, b);
				system("pause");
				break;
			}
			case '^':
			{
				cout << "Podaj stopien potegi: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				cout << "Podaj podstawe potegi: ";
				cin >> inputB;
				b = tylkoLiczby(inputB);

				Potegowanie(a, b);
				system("pause");
				break;
			}
			case 'p':
			{
				cout << "Podaj stopien pierwiastka: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				cout << "Podaj liczbe pierwiastkowana: ";
				cin >> inputB;
				b = tylkoLiczby(inputB);

				Pierwiastkowanie(a, b);
				system("pause");
				break;
			}
			case '%':
			{
				cout << "Funkcja oblicza jaka jest procentowa wartosc liczby pierwszej w stosunku do drugiej" << endl;

				cout << "Podaj pierwsza liczbe: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				cout << "Podaj druga liczbe: ";
				cin >> inputB;
				b = tylkoLiczby(inputB);

				Procenty(a, b);
				system("pause");
				break;
			}
			case 'o':
			{
				cout << "Podaj liczbe: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				Odwrotnosc(a);
				system("pause");
				break;
			}
			case 'l':
			{
				cout << "Podaj podstawe: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				cout << "Podaj liczbe logarytmowana: ";
				cin >> inputB;
				b = tylkoLiczby(inputB);


				Logarytmowanie(a, b);
				system("pause");
				break;
			}
			case 's':
			{
				cout << "Podaj kat w stopniach: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				Sinus(a);
				system("pause");
				break;
			}
			case 'c':
			{
				cout << "Podaj kat w stopniach: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

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