#include <iostream>

using namespace std;

int main(void)
{
	int B;
	int A;
	cout << "Größter gemeinsamer Teiler" <<
	endl << "==========================" << endl <<
	endl << "Geben sie die erste Zahl an: ";
	cin >> A;
	cout << "       Und jetzt die Zweite: ";
	cin >> B;
	int M = A;
	int N = B;
	int R = 1;
	while (R != 0)
	{
		if (M < N)
		{
			int TMP = M;
			M = N;
			N = TMP;
		}
		R = M - N;
		M = N;
		N = R;
	}
	cout << endl << "Kleinster gemeinsamer Teiler: " << M << endl;
	cin >> A;
	return 0;
}
