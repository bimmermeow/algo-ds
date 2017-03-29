#include <iostream>

using namespace std;

int F_r(int n) {
	if(n<=2) {
		return 1;
	} else {
		return ( n*F_r(n-1)-F_r(n-2));
	}
}

int F_i(int n) {
	if(n<=2) return 1;
	int fnm1 = 1;
	int fnm2 = 1;
	int x = 1;
	for(int i = 3;i<=n;i++) {
		fnm2 = fnm1;
		fnm1 = x;
		x = i*fnm1-fnm2;
	}
	return x;
}
int main() {
	int var;
	while(1<2) {
		cin >> var;
		cout << F_i(var);
		cout << endl << F_r(var)<< endl <<endl;
	}
}
