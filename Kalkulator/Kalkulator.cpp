/*
		wersja 1

Obslugiwane dzialania matematyczne:
Dodawanie
-dziala 
Odejmowanie 
-dziala
Mnozenie 
-dziala
Dzielenie 
-dziala
Potegowanie 
-dziala
Pierwiastkowanie 
-dziala
Procent 
-dziala
Odwrotnosc 
-dziala
Logarytmowanie 
-dziala
Sinus 
-dziala
Cosinus 
-dziala

		wersja 2

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

		wersja 3

- pierwsze napisy w programie sklejone i brak "K"
- POPRAWIONE

- po wybraniu obliczenia przykładowo: drugiego stopnia pierwiastka z -4 dostaję 0.841 ??
-POPRAWIONE

- przydała by się opcja /? lub /h /help coś w tym stylu ładnie opisane bo teraz nie wiadomo jaki operator z wiersza poleceń zastosować
-DODANO

- menu z wiersza poleceń: prog.exe 2 p 4 daje mi "Pierwiastek 0.0000 stopnia z 2.0000 wynosi: inf" - takie rzeczy trzeba poprawic
-POPRAWIONE 

- prog.exe 2 * 3 daje 0.0000 itd
-Wynika z wymogu podania dokładności
-POPRAWIONE

	wersja 4

- z jakiegoś powodu nie przyjmuje mi operatora ^ z wiersza poleceń
- zamieniono pierwiastek na r (root) potęga na p (power)
-ZMIENIONE

- lepsza obsługa z wiersza polecen
- dodano sprawdzanie ilosci zmiennych przy krytycznych funkcjach oraz przesunięto miejsce wywołania funkcji kalkulator
-DODANE

nie wiem dlaczego w momencie konwersji liczb STOD "gubią się" częsci ułamkowe liczby która jest zapisana za pomocą kropki a nie przecinka 
--potrzebuje pomocy
*/

//===============================================//===============================================

#include "pch.h" // precompiled header
#include <iostream> // standard input/output stream objects
#include <stdlib.h> // C++ standard library
#include <math.h> // common mathematical operations and transformations
#include <regex> // regular expression library

const double PI = 3.14159265358979323846; // stała PI zdefioniowana na początku programu

using namespace std; // deklaracja użycia przestrzeni nazw std::

//===============================================//===============================================
//Funkcja sprawdzania czy wprowadzone warotsci są liczbami (całkowite lub zmiennoprzecinkowe)
//Przyjmuje string - zwraca liczbe w double
//===============================================
double tylkoLiczby(string inputString) {

	//floatpoint regex formula: ((\+|-)?\d{1,})+((\.{1})+(\d{1,}))? 
	string regexFloat = "((\\+|-)?\\d+)(\\.((\\d+)?))?"; // wyrazenie regularne dla liczby zmiennoprzcinkowej 
	smatch regexMatch;
	double result;
	if (!regex_search(inputString, regexMatch, regex(regexFloat))){
		
		cout << "Niepoprawna wartosc... sprobuj ponownie" << endl;
		cin >> inputString;
		tylkoLiczby(inputString);
	}
	result = stod(inputString); // w tym miejscu 
	return result;
}

void tylkoLiczbyNoReturn(string inputString) {
	cout << inputString << endl;
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
	cout << "\n" << "Dokladnosc ustawiona na: " << n << " miejsc po przecinku" << "\n" << endl;
}

//===============================================//===============================================
//Funkcja dodawania
//===============================================

void Dodawanie(double x, double y)
{
	double wynik = x + y;
	cout << "\n" << "Suma wynosi: " << fixed << wynik << "\n" << endl;
}

//===============================================//===============================================
//Funkcja odejmowania
//===============================================

void Odejmowanie(double x, double y)
{
	double wynik = x - y;
	cout << "\n" << "Roznica wynosi: " << fixed << wynik << "\n" << endl;
}

//===============================================//===============================================
//Funkcja mnożenia
//===============================================

void Mnozenie(double x, double y)
{
	double wynik = x * y;
	cout << "\n" << "Iloczyn wynosi: " << fixed << wynik << "\n" << endl;
}

//===============================================//===============================================
//Funkcja dzielenia ze sprawdzeniem założeń zgodym z zasadami dzielenia
//===============================================

void Dzielenie(double x, double y)
{
	if (y == 0)
	{
		cout << "\n" << "Nie dzielimy przez zero!\n" << "\n" << endl;;
	}
	else
	{
		if (x == 0)
		{
			cout << "\n" << "Iloraz wynosi: 0" << "\n" << endl;
		}
		else
		{
			double wynik = x / y;
			cout << "\n" << "Iloraz wynosi: " << fixed << wynik << "\n" << endl;
		}
	}
}

//===============================================//===============================================
//Funckcja potęgowania wykluczająca możliwość podnoszenia 0 do potęgi 0
//===============================================

void Potegowanie(double a, double x)
{
	if (x == 0 && a == 0)
	{
		cout << "\n" << "Nie moge potegowac 0^0!" << "\n" << endl;
	}
	else
	{
		double wynik = pow(x, a);
		cout << "\n" << "Potega " << a << " stopnia z: " << x << " wynosi: " << wynik << "\n" << endl;
	}
}
//===============================================//===============================================
//Funkcja pierwiastkowania dowolnego stopnia w przestrzeni liczb rzeczywistych
//===============================================

void Pierwiastkowanie(double a, double x)
{
	if (x < 0)
	{
		cout << "\n" << "Kalkulator nie daje mozliwosci pierwiastkowania liczb ujemnych!" << "\n" << endl;
	}
	else
	{
		double wynik = pow(x, 1 / a);
		cout << "\n" << "Pierwiastek " << a << " stopnia z: " << x << " wynosi: " << wynik << "\n" << endl;
	}
}

//===============================================//===============================================
//Funkcja licząca procentową wartość liczby w stosunku do innej liczby
//===============================================

void Procenty(double x, double y)
{
	if (y == 0)
	{
		cout << "\n" << "Nie dzielimy przez zero!" << "\n" << endl;
	}
	else
	{
		double wynik = ((x / y) * 100);
		cout << "\n" << "Procentowa wartosc: " << x << " z " << y << " wynosi: " << wynik << "%" << "\n" << endl;
	}
}

//===============================================//===============================================
//Funkcja licząca odwrotność liczby
//===============================================

void Odwrotnosc(double x)
{
	if (x == 0)
	{
		cout << "\n" << "Nie dzielimy przez zero!" << "\n" << endl;
	}
	else
	{
		double wynik = (1 / x);
		cout << "\n" << "Odwrotnosc liczby " << x << " wynosi: " << wynik << "\n" << endl;
	}
}

//===============================================//===============================================
//Funkcja licząca logartym o dowolnej podstawie
//===============================================

void Logarytmowanie(double a, double x)
{ 
	if (a == 1) 
	{
		cout << "\n" << "Liczba podstawy logarytmu musi byc rozna od 1!" << "\n" << endl;
	}
	else if(a <= 0)
	{
		cout << "\n" << "Liczba podstawy logarytmu musi byc wieksza od 0 oraz rozna od 1!" << "\n" << endl;
	}
	else if (x <= 0)
	{
		cout << "\n" << "Liczba logarytmowana musi byc wieksza od 0!" << "\n" << endl;
	}
	//else if x=1??
	else
	{
		double wynik = (log(x) / log(a)); //check
		cout << "\n" << "Logarytm o podstawie " << a << " z " << x << " wynosi: " << fixed << wynik << "\n" << endl;
	}
}

//===============================================//===============================================
//Funkcja licząca sinus kąta
//===============================================

void Sinus(double x)
{
	double wynik = sin(x * PI / 180);
	cout << "\n" << "Sinus kata " << x << " wynosi: " << fixed << wynik << "\n" << endl;
}

//===============================================//===============================================
//Funkcja licząca cosinus kąta
//===============================================

void Cosinus(double x)
{
	double wynik = cos(x * PI / 180);
	cout << "\n" << "Cosinus kata " << x << " wynosi: " << fixed << wynik << "\n" << endl;
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
			if (b == NULL) {
				cout << "\n"<< "brak drugiej zmiennej" << endl;
				break;
			}
			Dodawanie(a, b);
			system("pause");
			break;
		}case '-':{
			if (b == NULL) {
				cout << "\n" << "brak drugiej zmiennej" << endl;
				break;
			}
			Odejmowanie(a, b);
			system("pause");
			break;
		}case '*':{
			if (b == NULL) {
				cout << "\n" << "brak drugiej zmiennej" << endl;
				break;
			}
			Mnozenie(a, b);
			system("pause");
			break;
		}case '/':{
			if (b == NULL) {
				cout << "\n" << "brak drugiej zmiennej" << endl;
				break;
			}
			Dzielenie(a, b);
			system("pause");
			break;
		}case 'p':{
			if (b == NULL) {
				cout << "\n" << "brak drugiej zmiennej" << endl;
				break;
			}
			Potegowanie(a, b);
			system("pause");
			break;
		}case 'r':{
			if (b == NULL) {
				cout << "\n" << "brak drugiej zmiennej" << endl;
				break;
			}
			Pierwiastkowanie(a, b);
			system("pause");
			break;
		}case '%':{
			if (b == NULL) {
				cout << "\n" << "brak drugiej zmiennej" << endl;
				break;
			}
			Procenty(a, b);
			system("pause");
			break;
		}case 'o':{
			Odwrotnosc(a);
			system("pause");
			break;
		}case 'l':{
			if (b == NULL) {
				cout << "\n" << "brak drugiej zmiennej" << endl;
				break;
			}
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
			case 2: {
				cho = *argv[1];
				xx = NULL;
				yy = NULL;
				if (cho == 'h' || cho == '?') {
					cout << "Poprawna skladnia oraz dostepne operatory kalkulatora to:" << "\n" << "\n"
					 << "Dodawanie" << "\t " << "+ " << "\n"
						<< "\t" << "{liczba} + {liczba} {dokladnosc}" << "\n" << "\n"

					  << "Odejmowanie" << "\t " << "- " << "\n"
						<< "\t" << "{liczba} - {liczba} {dokladnosc}" << "\n" << "\n"

					 << "Mnozenie" << "\t " << "* " << "\n"
						<< "\t" << "{liczba} * {liczba} {dokladnosc}" << "\n" << "\n"

					 << "Dzielenie" << "\t " << "/ " << "\n"
						<< "\t" << "{liczba} / {liczba} {dokladnosc}" << "\n" << "\n"

					 << "Potegowanie" << "\t " << "p " << "\n"
						<< "\t" << "{stopien} p {liczba podstawy} {dokladnosc}" << "\n" << "\n"

					 << "Pierwiastkowanie" << "\t " << "r " << "\n"
						<< "\t" << "{stopien} r {liczba pierwiastkowana} {dokladnosc}" << "\n" << "\n"

					 << "Procent" << "\t " << "% " << "\n"
						<< "\t" << "{liczba} % {liczba} {dokladnosc}" << "\n" << "\n"

					 << "Odwrotnosc" << "\t " << "o " << "\n"
						<< "\t" << "{liczba} o {dokladnosc}" << "\n" << "\n"

					 << "Logarytmowanie" << "\t " << "l " << "\n"
						<< "\t" << "{podstawa} l {liczba logarytmowana} {dokladnosc}" << "\n" << "\n"

					 << "Sinus" << "\t " << "s " << "\n"
						<< "\t" << "{stopnie} s {dokladnosc}" << "\n" << "\n"

					  << "Cosinus" << "\t " << "c " << "\n"
						<< "\t" << "{stopnie} c {dokladnosc}" << "\n" << "\n"
					<< endl;
				}	
				else {
					cout << "Nieprawidlowa ilosc argumentow!" << "\n"
						<< "Uruchom program z poleceniem h lub ? aby zobaczyc wiecej informacji..." << endl;
				}
				break;
			}
			case 4: // w przypadku gdy chcemy skorzystać z obliczenia sinusa druga liczba jest zbędna - zostaje wyzerowana 
			{
				tylkoLiczbyNoReturn(argv[1]);
				tylkoLiczbyNoReturn(argv[3]);

				xx = stod(argv[1]); // atof zamienia typ danych string(char) na double 
				cho = *argv[2]; // przypisanie wartości zapisanej pod pointerem do zmiennej odpowiedzialej za wybór opracji matematycznej
				yy = NULL; // zerowanie zbędnej (nie podanej) zmiennej
				prec = stoi(argv[3]); // ostatni argument jest deklaracją dokłądności wyświetlania liczb po przecinku 
				cout.precision(prec); // ustawienie dokładności wyświetlania
				cout << "\n" << "Z dokladnoscia do: " << prec << " liczb po przecinku." << "\n" << endl;
				cout << fixed << xx << endl;
				cout << cho << endl;
				kalkulator(xx, cho, yy); // wywołanie funkcji kalkulatora (liczba , operacja , NULL)
				cout << "\n" << "Zamykam program..." << "\n" << endl;
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
				cout << "\n" << "Z dokladnoscia do: " << prec << " liczb po przecinku." << "\n" << endl;
				cout << fixed << xx << endl;
				cout << cho << endl;
				cout << fixed << yy << endl;
				kalkulator(xx, cho, yy); // wywołanie funkcji kalkulatora (liczba , operacja , liczba)
				cout << "\n" << "Zamykam program..." << "\n" << endl;
				break;
			}
			default:
			{
				cout << "Nieprawidlowa ilosc argumentow!" << "\n"
					 << "Uruchom program z poleceniem h lub ? aby zobaczyc wiecej informacji..." << endl;
				system("pause");
				exit(0);
				break;
			}
		}
		//system("pause"); // pozwala użytkownikowi zapoznać się z wyświetloną odpowiedzią przed zamknięciem programu
		exit(0);
	}
	else //===============================================//===============================================
	{
		cout << "Witaj w Kalkulatorze!" << "\n" << endl;
		UstawDokladnosc();

		system("pause");
		system("cls");

		for (;;) // pozwala na wyświetlanie "menu" programu pomimo czyszcznia konsoli
		{
			system("cls");

			cout << "Wybierz operacje:\n"
				<< "\t" << " d " << "\t" << "Zmien dokladnosc" << "\n"
				<< "\t" << " + " << "\t" << "Dodawanie" << "\n"
				<< "\t" << " - " << "\t" << "Odejmowanie" << "\n"
				<< "\t" << " * " << "\t" << "Mnozenie" << "\n"
				<< "\t" << " / " << "\t" << "Dzielenie" << "\n"
				<< "\t" << " ^ " << "\t" << "Potegowanie" << "\n"
				<< "\t" << " p " << "\t" << "Pierwiastkowanie" << "\n"
				<< "\t" << " % " << "\t" << "Procent" << "\n"
				<< "\t" << " o " << "\t" << "Odwrotnosc" << "\n"
				<< "\t" << " l " << "\t" << "Logarytmowanie" << "\n"
				<< "\t" << " s " << "\t" << "Sinus" << "\n"
				<< "\t" << " c " << "\t" << "Cosinus" << "\n"
				<< "\t" << "q/Q " << "\t" << "Aby wyjsc." << "\n"
				<< "\n" << "Wybieram: " << "\t"
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
				cout << "\n" << "Podaj pierwsza liczbe: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				cout << "\n" << "Podaj druga liczbe: ";
				cin >> inputB;
				b = tylkoLiczby(inputB);

				Dodawanie(a, b);
				system("pause");
				break;
			}
			case '-':
			{
				cout << "\n" << "Podaj pierwsza liczbe: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				cout << "\n" << "Podaj druga liczbe: ";
				cin >> inputB;
				b = tylkoLiczby(inputB);

				Odejmowanie(a, b);
				system("pause");
				break;
			}
			case '*':
			{
				cout << "\n" << "Podaj pierwsza liczbe: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				cout << "\n" << "Podaj druga liczbe: ";
				cin >> inputB;
				b = tylkoLiczby(inputB);

				Mnozenie(a, b);
				system("pause");
				break;
			}
			case '/':
			{
				cout << "\n" << "Podaj licznik: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				cout << "\n" << "Podaj mianownik: ";
				cin >> inputB;
				b = tylkoLiczby(inputB);

				Dzielenie(a, b);
				system("pause");
				break;
			}
			case '^':
			{
				cout << "\n" << "Podaj stopien potegi: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				cout << "\n" << "Podaj podstawe potegi: ";
				cin >> inputB;
				b = tylkoLiczby(inputB);

				Potegowanie(a, b);
				system("pause");
				break;
			}
			case 'p':
			{
				cout << "\n" << "Podaj stopien pierwiastka: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				cout << "\n" << "Podaj liczbe pierwiastkowana: ";
				cin >> inputB;
				b = tylkoLiczby(inputB);

				Pierwiastkowanie(a, b);
				system("pause");
				break;
			}
			case '%':
			{
				cout << "\n" << "Funkcja oblicza procentowa wartosc z liczby pierwszej w stosunku do drugiej" << endl;

				cout << "\n" << "Podaj pierwsza liczbe: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				cout << "\n" << "Podaj druga liczbe: ";
				cin >> inputB;
				b = tylkoLiczby(inputB);

				Procenty(a, b);
				system("pause");
				break;
			}
			case 'o':
			{
				cout << "\n" << "Podaj liczbe: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				Odwrotnosc(a);
				system("pause");
				break;
			}
			case 'l':
			{
				cout << "\n" << "Podaj podstawe: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				cout << "\n" << "Podaj liczbe logarytmowana: ";
				cin >> inputB;
				b = tylkoLiczby(inputB);


				Logarytmowanie(a, b);
				system("pause");
				break;
			}
			case 's':
			{
				cout << "\n" << "Podaj kat w stopniach: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				Sinus(a);
				system("pause");
				break;
			}
			case 'c':
			{
				cout << "\n" << "Podaj kat w stopniach: ";
				cin >> inputA;
				a = tylkoLiczby(inputA);

				Cosinus(a);
				system("pause");
				break;
			}
			case 'q':
			{
				cout << "\n" << "Zamykam program..." << endl;

				exit(0);
				break;
			}
			case 'Q':
			{
				cout << "\n" << "Zamykam program..." << endl;

				exit(0);
				break;
			}
			default:
			{
				cout << "\n" << "Niepoprawny operator!" << "\n" << endl;
				system("pause");
				break;
			}
			}
		}
	}
}