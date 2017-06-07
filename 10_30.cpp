#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

#define ARR_LEN 10000000

template <class Tr>
void Mean(int l,int r, vector<Tr> &array, int mean=1) {
	int m;
	switch (mean) {
		case 0:
			m=(l+r)/2;
			break;
		case 1:
			m = rand() % (r-l) + l;
			break;
		case 2:
			if(array[l]>array[(l+r)/2]) {
				Tr tmp = array[l];
				array[l] = array[(l+r)/2];
				array[(l+r)/2] = tmp;
			}
			if(array[l]>array[r]) {
				Tr tmp = array[l];
				array[l] = array[r];
				array[r] = tmp;
			}
			if(array[(l+r)/2]>array[r]) {
				Tr tmp = array[r];
				array[r] = array[(l+r)/2];
				array[(l+r)/2] = tmp;
			}
			m=(l+r)/2;
			break;
	}
	Tr tmp = array[m];
	array[m] = array[r];
	array[r] = tmp;
}

template <class Tr>
int Partition(int l,int r, vector<Tr> &array, int mean) {
	int i=l-1,j=r;
	Mean(l,r, array, mean);
	while (i<j) {
		while(array[++i]<=array[r])
			if (i==r) break;
		while(array[--j]>array[r])
			if (j==l) break;
		if (i<j) {
			Tr tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	Tr tmp = array[i];
	array[i] = array[r];
	array[r] = tmp;
	return i;
}

template <class Tr>
void QuicksortTable(int l,int r, vector<Tr> &array, int mean) {
	int m;
	m=Partition(l,r, array, mean);
	if (l<m-1)
		QuicksortTable(l,m-1, array, mean);
	if (m+1<r)
		QuicksortTable(m+1,r, array, mean);
}
int main() {
	srand (time(NULL));
	cout << "Array erstellen... " << flush;
	vector<int> array(ARR_LEN);
	for(int i = 0; i<ARR_LEN; i++) {
		array[i] = (i/3) + (i%3)*10;
		// cout << array[i] << " ";
	}
	cout << "Fertig. " << endl;

	cout << "a) Sortieren..." << endl;
	clock_t begin = clock();
	QuicksortTable(0,ARR_LEN-1, array, 0);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Fertig. " << elapsed_secs << "s Prozessorzeit zum Sortieren." << endl << endl;

	cout << "b) Sortieren..." << endl;
	begin = clock();
	QuicksortTable(0,ARR_LEN-1, array, 1);
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Fertig. " << elapsed_secs << "s Prozessorzeit zum Sortieren." << endl << endl;

	cout << "c) Sortieren..." << endl;
	begin = clock();
	QuicksortTable(0,ARR_LEN-1, array, 2);
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Fertig. " << elapsed_secs << "s Prozessorzeit zum Sortieren." << endl << endl;

	cout << endl;
}
