/* Kalkulator
Aplikacja konsolowa typu zaawansowany kalkulator.Program ma umożliwiać wykonywanie operacji :

-dodawanie
- odejmowanie
- mnożenie
- dzielenie
- potęgowanie(dowolna potęga)
- pierwiastkowanie(dowolny stopień)
- obliczanie procentów
- logarytmowanie
- 1 / x
- sin, cos

Program ma działać na zasadzie menu ekranowego jak i musi rozumieć argumenty uruchomieniowe.Przykładowo aby wykonać operację potęgowania 210 uruchamiamy program z argumentami :

c:\ > kalk.exe 2 ^ 10

	Jeśli chcemy obliczyć 23 % z 2734 wydajemy polecenie :

c:\ > kalk.exe 23 z 2734

	I podobnie z pozostałymi operacjami jakie rozumie nasz kalkulator.Należy zapewnić obsługę ewentualnych błędów typu wpisanie 2a zamiast 2, wybranie złego operatora itp.*/


#include <iostream>
#include <stdlib.h>
#include <math.h>
#include<limits>

const double PI = 3.14159265358979323846;

using namespace std;

int IsInt() {
	int a;
	cin >> a;
	while (cin.fail())
	{
		cout << "Enter only an integer please. Try again." << std::endl;
		cin.clear();
		cin.ignore();
		cin >> a;
	}
	return a;
}

	void Dodawanie(double x, double y) {
		long int wynik = x + y;
		cout << "Suma wynosi: " << fixed << wynik << endl;
	}
	
	void Odejmowanie( double x, double y ) {
		long int wynik = x - y;
		cout << "Roznica wynosi: " << fixed << wynik << endl;
	}

	void Mnozenie( double x, double y ) {
		long int wynik = x * y;
		cout << "Iloczyn wynosi: " << fixed << wynik << endl;
	}

	void Dzielenie( double x, double y ) {
		if (y == 0){
			cout << "Nie dzielimy przez zero!\n";
		} else{
			if(x == 0){ 
				cout << "Iloraz wynosi: 0" << endl; 
			} else {
				double wynik = x / y;
				cout << "Iloraz wynosi: " << fixed << wynik << endl;
			}
		}
	}

	void Potegowanie( double x, double a ) {
		if (x == 0 && a == 0) {
			cout << "Nie moge potegowac 0^0!" << endl;
		} else {
			long int wynik = pow(x, a);
			cout << "Potega " << a << " stopnia z: " << x << " wynosi: " << wynik << endl;
		}
	}

	void Pierwiastkowanie( double x, double a ) {
		if (x < 0) {
			cout << "Kalkulator nie daje mozliwosci pierwiastkowania liczb ujemnych!" << endl;
		} else {
			double wynik = pow(x, 1 / a);
			cout << "Pierwiastek " << a << " stopnia z: " << x << " wynosi: " << wynik << endl;			
		}
	}
	
	void Procenty( double x, double y ) {
		if (y == 0) {
			cout << "Nie dzielimy przez zero!\n";
		} else {
			double wynik = ((x / y) * 100);
			cout << "Procentowa wartość " << x << " z: " << y << " wynosi: " << wynik << "%" << endl;
		}
	}

	void Odwrotnosc( double x ) {
		if (x == 0) {
			cout << "Nie dzielimy przez zero!\n";
		} else {
			double wynik = (1 / x);
			cout << "Odwrotnosc liczby " << x << " wynosi: " << wynik << endl;
		}
	}

	void Logarytmowanie( double x, double a ) {
		if ( a = 1 && a <= 0 ) {
			if ( x<=0 ) {
				cout << "Liczba logarytmowana musi być większa od 0!";
			} else {
				cout << "Liczba podstawy logarytmu musi być większa od 0 oraz różna od 1!";
			}
		} else {
			double wynik = log(x) / log(a);
			cout << "Logarytm o podstawie " << a << " z " << x << " wynosi: " << fixed << wynik << endl;
		}
	}
	
	void Sinus( double x ) {
		double wynik = sin( x * PI / 180); 
		cout << "Sinus kąta " << x << " wynosi: " << fixed << wynik << endl;
	}


	void Cosinus( double x ) {
		double wynik = cos(x * PI / 180);
		cout << "Cosinus kąta " << x << " wynosi: " << fixed << wynik << endl;
	}

	
int main( int argc, double argv[] )
{
	double a;
	double b;
	char wybor;
	
	system("CLS");
	cout << "Witaj w calkulatorze!\n" 
		 << "Program przyjmuje tylko liczby calkowite jako dane wejsciowe!\n"
		 << endl;
	
	system("pause");

	for( ; ; ) {
		switch ( argc ) {
		case 3 : {
				a = argv[0];
				wybor = argv[1];
			}

		case 4 : {
				a = argv[1];
				wybor = argv[2];
				b = argv[3];
			}
		}

		system("cls");
		
		cout << "Wybierz operację:\n" 
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
			<< "\t q \tAby wyjsc.\n"
			<< "\nWybieram: \t"
			<<endl;
		
		cin >> wybor;
		
		switch ( wybor ) {
			case '+': {
				if (argc != 4) {
					cout << "Podaj pierwsza liczbe: ";
					a = IsInt();
				
					cout << "Podaj druga liczbe: ";
					b = IsInt();
				}
				Dodawanie(a, b);	
				system("pause");
				break;

			} case '-': {
				if (argc != 3) {
					cout << "Podaj pierwsza liczbe: ";
					a = IsInt();
					cout << "Podaj druga liczbe: ";
					b = IsInt();
				}
				Odejmowanie(a, b);
				system("pause");
				break;

			} case '*': {
				if (argc != 3) {
					cout << "Podaj pierwsza liczbe: ";
					a = IsInt();
					
					cout << "Podaj druga liczbe: ";
					b = IsInt();
				}
				Mnozenie(a, b);
				system("pause");
				break;

			} case '/': {
				if (argc != 3) {
					cout << "Podaj licznik: ";
					a = IsInt();
					
					cout << "Podaj mianownik: ";
					b = IsInt();
				}
				Dzielenie(a, b);
				system("pause");
				break;

			} case '^': {
				if (argc != 3) {
					cout << "Podaj stopien potegi: ";
					a = IsInt();
					cout << "Podaj podstawe potegi: ";
					b = IsInt();
				}
				Potegowanie(a, b);
				system("pause");
				break;

			} case 'p': {
				if (argc != 3) {
					cout << "Podaj stopien pierwiastka: ";
					a = IsInt();
					
					cout << "Podaj liczbe pierwiastkowana: ";
					b = IsInt();
				}
				Pierwiastkowanie(a, b);
				system("pause");
				break;

			} case '%': {
				if (argc != 3) {
					cout << "Podaj pierwsza liczbe: ";
					a = IsInt();
					
					cout << "Podaj druga liczbe: ";
					b = IsInt();
				}
				Procenty(a, b);
				system("pause");
				break;

			} case 'o': {
				if (argc != 2) {
					cout << "Podaj liczbe: ";
					a = IsInt();
				}
				Odwrotnosc(a);
				system("pause");
				break;

			} case 'l': {
				if (argc != 3) {
					cout << "Podaj podstawe: ";
					a = IsInt();
					
					cout << "Podaj liczbe logarytmowana: ";
					b = IsInt();
				}
				Logarytmowanie(a, b);
				system("pause");
				break;

			} case 's': {
				if (argc != 2) {
					cout << "Podaj kat w stopniach: ";
					a = IsInt();
				}
				Sinus(a);
				system("pause");
				break;

			} case 'c': {
				if (argc != 2) {
					cout << "Podaj kat w stopniach: ";
					a = IsInt();
				}
				Cosinus(a);
				system("pause");
				break;

			} case 'q': {
				exit(0);
				break;

			} default: {
				cout << "Niepoprawny operator!\n";
				system("pause");
				break;
			}
		}
	}	
}