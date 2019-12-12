#include <iostream>
#include <random>

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
	}
	else {
		wpisz_wartosci(temperaturaPowietrza, n);
	}

	drukuj_tablice(temperaturaPowietrza, n);
  return 0;
}