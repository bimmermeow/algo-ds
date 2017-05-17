#include <iostream>
#include <vector>
#include <iomanip>

#define FETT (char)27 << "[1m"
#define NFETT (char)27 << "[0m"
using namespace std;

void array_ausgeben(vector<int> array) {
	int count = array.size();
	for (int i = 0; i < count; i++) {
		cout << setw(2) << array[i] << ' ';
	}
	cout << endl;
}

vector<int> insertionsort(vector<int> A) {
	cout << FETT << "Sortierung mit Insertionsort" << NFETT << endl;
	array_ausgeben(A);
	int vergleiche = 0;
	int count = A.size();
	int einzusortierender_wert;
	int j;
	for (int i = 1; i < count; i++) {
		einzusortierender_wert = A[i];
		j = i;
		while(j>0 && A[j-1]>einzusortierender_wert) {
			vergleiche+=2;
			A[j] = A[j-1];
			j = j-1;
		}
		A[j] = einzusortierender_wert;
		array_ausgeben(A);
	}
	cout << "Es wurden " << FETT << vergleiche << NFETT << " Vergleiche durchgeführt." << endl << endl;
	return A;
}
vector<int> selectionsort(vector<int> A) {
	cout << FETT << "Sortierung mit Selectionsort" << NFETT << endl;
	array_ausgeben(A);
	int vergleiche = 0;
	int n = A.size()-1;
	int links = 0;
	int min;
	int tmp;
	while(links<n) {
		min = links;
		for(int i = links+1;i<=n;i++) {
			if(A[i] < A[min]) {
				min = i;
				vergleiche++;
			}
		}
		tmp = A[min];
		A[min] = A[links];
		A[links] = tmp;
		links = links+1;
		array_ausgeben(A);
	}
	cout << "Es wurden " << FETT << vergleiche << NFETT << " Vergleiche durchgeführt." << endl << endl;
	return A;
}

vector<int> bubbleSort(vector<int> A) {
	cout << FETT << "Sortierung mit Bubblesort" << NFETT << endl;
	array_ausgeben(A);
	int vergleiche = 0;
	int tmp;
 	for (int n = A.size(); n>1; n--){
		for (int i=0; i<n-1; i=i+1){
			if (A[i] > A[i+1]){
				vergleiche++;
				tmp = A[i];
				A[i] = A[i+1];
				A[i+1] = tmp;
				array_ausgeben(A);
			}
		}
	}
	cout << "Es wurden " << FETT << vergleiche << NFETT << " Vergleiche durchgeführt." << endl << endl;
	return A;
}
int main () {
	vector<int> array {0, 10, 20, 1, 11, 21, 2, 12, 22};
	insertionsort(array);
	selectionsort(array);
	bubbleSort(array);
	return 0;
}
