#include <iostream>

using namespace std;

long fibonacci_r( int n)
{
	if (n<=1)
	return 1;
	else
	return fibonacci_r(n-1) + fibonacci_r(n-2);
}
long fibonacci_i( int n)
{
	long afib[500], i;
	afib[0] = 1;
	afib[1] = 1;
	for (i=2 ; i<=n; i++)
		afib[i]=afib[i-1] + afib[i-2];
	return afib[n];
}
long fibonacci_o(int n) {
	if(n<=2) return 1;
	long fnm1 = 1;
	long fnm2 = 1;
	long x = 1;
	for(int i = 3;i<=n;i++) {
		fnm2 = fnm1;
		fnm1 = x;
		x = i*fnm1-fnm2;
	}
	return x;
}

int main() {
	cout << "Fibonacci-Zahlen: Geben sie zuerst an, bis zu welcher Stelle sie berechnet werden sollen, dann mit welcher Methode ('r'=Rekursiv, 'i'=Iterativ, 'o'=optimiert Iterativ)" << endl;
	int stellen;
	cin >> stellen;
	char variante;
	cin >> variante;
	if(variante=='r') {
		cout << "Rekursive Berechnung mit "<<stellen<<" Stellen: ";
		cout << fibonacci_r(stellen) << endl;
	} else if(variante=='i') {
		cout << "Iterative Berechnung mit "<<stellen<<" Stellen: ";
		cout << fibonacci_i(stellen) << endl;
	} else if(variante=='o') {
		cout << "Optimierte Iterative Berechnung mit "<<stellen<<" Stellen: ";
		cout << fibonacci_o(stellen) << endl;
	} else {
		cout << "Bitte Programm neu starten und nur i, r oder o angeben.";
	}
	return 0;
}
