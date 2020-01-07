#include <iostream>
#include <random>
#include <time.h>
#include <tuple>

using namespace std;

// double temperaturaPowietrza[] = {5.0, 1.4, 2.1, -1.0, -2.2, 3.1, 2.5, 4.0 ,-5.3 ,-2.2 ,3.6 ,6.1 ,5.4 ,-3.1 ,0 ,-4.2 ,2.1};
// int predkoscWiatru[] = {3,2,2,1,2,0,0,4,2,2,3,5,3,0,1,4,2};
// double cisnienieAtmosferyczne[] = { 1012.0, 992.8, 996.4, 1039.6, 1047.6, 1004.4, 1016.9, 1005.8, 1043.5, 1010.6, 993.4,
//       1031.1, 1025.9, 1008.5, 1041.9 };
double *temperaturaPowietrza;
int *predkoscWiatru;
double *cisnienieAtmosferyczne;

int * utworz_int(int n){
	return new int[n];
}

double * utworz_double(int n){
	return new double[n];
}

void dodajTemperature(double *temperaturaPowietrza){
  double wejscie;
  cout << "Wprowadz temperature (mozesz dodac pojedyncza wartosc lub kilka odzielone spacja): ";
  cin >> wejscie;
}


void wygeneruj_wartosci(int * a, int n, int d, int g){
	default_random_engine gen(unsigned(time(0)));
	uniform_int_distribution<int> los(d, g);
	for (int i = 0; i < n; i++)
		a[i] = los(gen);
}

void wygeneruj_wartosci(double * a, int n, double d, double g){
	default_random_engine gen(unsigned(time(0)));
	uniform_real_distribution<double> los(d, g);
	for (int i = 0; i < n; i++)
		a[i] = los(gen);
}

void wpisz_wartosci(int * a, int n){
	cout << "podaj " << n << " wartosci calkowitych: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void wpisz_wartosci(double * a, int n){
	cout << "podaj " << n << " wartosci rzeczywistych: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void drukuj_tablice(int * a, int n){
	cout << "\n\n";
	for (int i = 0; i < n; i++)
		cout << a[i]<<" ";
}

void drukuj_tablice(double * a, int n){
	cout << "\n\n";
	for (int i = 0; i < n; i++)
		cout << a[i]<<" ";
}

// 1. Wyznaczyć dzień, w którym wartość temperatury jest największa

	std::tuple<double, int> wyznacz_max(double* a, int n) {
	double max = a[0];
	int dzien = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			dzien = i;
		}
	}

	return std::make_tuple(max, dzien); 
}

// 2. Sprawdzić, czy w podanym przedziale czasu wartości cisniene atmosferyczne tworzą ciąg rosnący;
bool jest_rosnacy_w_przedziale(double* a, int n, int poczatek, int koniec) {
	for (int i = poczatek-1; i < koniec; i++) {
		if (a[i - 1] >= a[i]) { //czy nastepnik jest wiekszy od poprzednika
			return false;
		}
	}
	return true;
}

// 3. Posortować wskazane okresy czasu dni w kolejności niemalejących wartości predkosci wiatru ;
int* sortuj_niemalejaco(int* a, int n) {
	int i, j, minIndeks, tmp;
	for (i = 0; i < n - 1; i++) {
		minIndeks = i;

		for (j = i + 1; j < n; j++) {
			if (a[j] < a[minIndeks]) {
				minIndeks = j;
			}
		}

		if (minIndeks != i) {
			tmp = a[i];
			a[i] = a[minIndeks];
			a[minIndeks] = tmp;
		}
	}
	return a;
}


int main(int argc, char const *argv[])
{
int n;
	cout << "podaj rozmiar tablic: ";
	cin >> n;

	double* temperaturaPowietrza = utworz_double(n);
	int* predkoscWiatru = utworz_int(n);
	double* cisnienieAtmosferyczne = utworz_double(n);


	char wybor = 'l';
	cout << "tablice losowe (l) czy z klawiatury (k)?: ";
	cin >> wybor;
	if (wybor == 'l') {
		wygeneruj_wartosci(temperaturaPowietrza, n, -20.0, 45.0);
		wygeneruj_wartosci(predkoscWiatru, n, 0, 10);
		wygeneruj_wartosci(cisnienieAtmosferyczne, n, 980.0, 1100.0);
		
		cout << "\nWygenerowana tablica temperatur powietrza:\n";
		drukuj_tablice(temperaturaPowietrza, n);
		cout << "\nWygenerowana tablica predkosci wiatru:\n";
		drukuj_tablice(predkoscWiatru, n);
		cout << "\nWygenerowana tablica cisnienia atmosferycznego:\n";
		drukuj_tablice(cisnienieAtmosferyczne, n);

	}
	else {
		cout << "wpisz wartosci temperatury powietrza:\n";
		wpisz_wartosci(temperaturaPowietrza, n);
		cout << "wpisz wartosci predkosc wiatru:\n";
		wpisz_wartosci(predkoscWiatru, n);
		cout << "wpisz wartosci cisnienia atmosferycznego:\n";
		wpisz_wartosci(cisnienieAtmosferyczne, n);

		cout << "\nTablica temperatur powietrza:\n";
		drukuj_tablice(temperaturaPowietrza, n);
		cout << "\nTablica predkosci wiatru:\n";
		drukuj_tablice(predkoscWiatru, n);
		cout << "\nTablica cisnienia atmosferycznego:\n";
		drukuj_tablice(cisnienieAtmosferyczne, n);
	}



	int operacja;
	while (true)
	{
		cout << "\n\nOPERACJE:\n";
		cout << "(1). Wyznaczyć dzień w którym wartość temperatury jest największa:\n";
		cout << "(2). Sprawdzić, czy w podanym przedziale czasu wartości cisniene atmosferyczne tworzą ciąg rosnacy:\n";
		cout << "(3). Posortować wskazane okresy czasu dni w kolejności niemalejących wartości predkosci wiatru:\n";
		cout << "\n\Wybierz 1-3, 0 aby zakonczyc:\n";
		cin >> operacja;

		switch (operacja) {
		case 1:
			double temperatura;
			int dzien;
			std::tie(temperatura, dzien) = wyznacz_max(temperaturaPowietrza, n);
			cout << "Maksymalna temperatura o wartosci " << temperatura << " byla dnia " << dzien + 1 << "\n";
			break;

		case 2:
			int poczatek, koniec;
			bool wynik2;
			cout << "podaj przedzial w dniach 1 - " << n << "\n";
			cin >> poczatek >> koniec;

			wynik2 = jest_rosnacy_w_przedziale(cisnienieAtmosferyczne, n, poczatek - 1, koniec);
			if (wynik2) {
				cout << "W podanym przedziale czasu wartości cisniene atmosferyczne tworzą ciąg rosnacy";
			}
			else {
				cout << "W podanym przedziale czasu wartości cisniene atmosferyczne nie tworzą ciągu rosnacego";
			}
			break;
			
		case 3:
			int* wynik3;
			wynik3 = sortuj_niemalejaco(predkoscWiatru, n);
			cout << "Posortowana predkosc wiatru w kolejnosci niemalejacej:\n";
			drukuj_tablice(wynik3, n);
			break;

		default:
			return 0;
			break;
		}

	}



	




  
}