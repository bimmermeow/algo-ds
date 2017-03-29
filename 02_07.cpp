#include <iostream>

using namespace std;

double harmReihe_r(int n) {
	if (n==1) return 1;
	double x =((double)1/(double)n) + harmReihe_r(n-1);
	return x;
}
double harmReihe_i(int n) {
	if (n==1) return 1;
	double x=0;
	for (int i = 1; i<=n;i++){
		x+=(1/(double)i);
	}
	return x;
}
int main() {
	cout << "Harmonische Reihe" <<
	endl << "=================" << endl <<
	endl << "n eingeben: ";
	int z;
	cin >> z;
	cout << endl << "h(n)(rekursiv) = " << harmReihe_r(z);
	cout << endl << "h(n)(iterativ) = " << harmReihe_i(z);
	cin >> z;
	return 0;
}
