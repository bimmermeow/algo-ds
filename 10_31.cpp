#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

#define ARR_LEN 10000000

template <class Tr>
int insertionsort_count(vector<Tr> A, int size) {
	int vergleiche = 0;
	int count = size;
	Tr einzusortierender_wert;
	int j;
	for (int i = 1; i < count; i++) {
		einzusortierender_wert = A[i];
		j = i;
		if(j>0) vergleiche++;
		else vergleiche++;
		while(j>0 && A[j-1]>einzusortierender_wert) {
			if(j>0) vergleiche++;
			else vergleiche++;
			A[j] = A[j-1];
			j = j-1;
		}
		A[j] = einzusortierender_wert;
	}
	return vergleiche;
}

template <class Tr>
void Mean(int l,int r, vector<Tr> &array) {
	int m=(l+r)/2;
	Tr tmp = array[m];
	array[m] = array[r];
	array[r] = tmp;
}

template <class Tr>
int Partition(int l,int r, vector<Tr> &array, int &vergleiche) {
	int i=l-1,j=r;
	Mean(l,r, array);
	while (i<j) {
		vergleiche++;
		while(array[++i]<=array[r])
			if (i==r) break;
			vergleiche++;
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
void QuicksortTable(int l,int r, vector<Tr> &array, int &vergleiche) {
	int m;
	m=Partition(l,r, array, vergleiche);
	if (l<m-1)
		QuicksortTable(l,m-1, array, vergleiche);
	if (m+1<r)
		QuicksortTable(m+1,r, array, vergleiche);
}

int main() {
	cout << "a)" << endl << "   Array wird erstellt... " << flush;
	vector<int> array(ARR_LEN);
	for (size_t i = 0; i < ARR_LEN; i++) {
		if(i%2==0)
			array[i] = i+2;
		else
			array[i] = i;
		// cout << array[i] << " ";
	}
	cout << "Fertig. " << endl << endl << "   Starte Insertionsort... " << flush;
	clock_t begin = clock();
	int vergleiche = insertionsort_count(array, ARR_LEN);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Fertig." << endl << "   Prozessorzeit: " << elapsed_secs << "s" << endl << "   Vergleiche: " << vergleiche << endl << endl << "   Starte Quicksort... "<< flush;
	vergleiche = 0;
	begin = clock();
	QuicksortTable(0,ARR_LEN-1, array, vergleiche);
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Fertig." << endl << "   Prozessorzeit: " << elapsed_secs << "s" << endl << "   Vergleiche: " << vergleiche << endl << endl;

	cout << "b)" << endl << "   Array wird erstellt... " << flush;
	for (size_t i = 0; i < ARR_LEN; i+=5) {
		array[i] = i+5;
		if(i+1<ARR_LEN) array[i+1] = i+4;
		if(i+2<ARR_LEN) array[i+2] = i+3;
		if(i+3<ARR_LEN) array[i+3] = i+2;
		if(i+4<ARR_LEN) array[i+4] = i+1;
	}
	cout << "Fertig. " << endl << endl << "   Starte Insertionsort... " << flush;
	begin = clock();
	vergleiche = insertionsort_count(array, ARR_LEN);
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Fertig." << endl << "   Prozessorzeit: " << elapsed_secs << "s" << endl << "   Vergleiche: " << vergleiche << endl << endl << "   Starte Quicksort... "<< flush;
	vergleiche = 0;
	begin = clock();
	QuicksortTable(0,ARR_LEN-1, array, vergleiche);
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Fertig." << endl << "   Prozessorzeit: " << elapsed_secs << "s" << endl << "   Vergleiche: " << vergleiche << endl << endl;

	cout << "c) mit k=10" << endl << "   Array wird erstellt... " << flush;
	for (size_t i = 0; i < ARR_LEN; i+=10) {
		for (size_t j = 0; j < 10; j++) {
			if(i+j<ARR_LEN) array[i+j] = i+(10-j);
		}
	}
	cout << "Fertig. " << endl << endl << "   Starte Insertionsort... " << flush;
	begin = clock();
	vergleiche = insertionsort_count(array, ARR_LEN);
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Fertig." << endl << "   Prozessorzeit: " << elapsed_secs << "s" << endl << "   Vergleiche: " << vergleiche << endl << endl << "   Starte Quicksort... "<< flush;
	vergleiche = 0;
	begin = clock();
	QuicksortTable(0,ARR_LEN-1, array, vergleiche);
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Fertig." << endl << "   Prozessorzeit: " << elapsed_secs << "s" << endl << "   Vergleiche: " << vergleiche << endl << endl;

	cout << "c) mit k=100" << endl << "   Array wird erstellt... " << flush;
	for (size_t i = 0; i < ARR_LEN; i+=100) {
		for (size_t j = 0; j < 100; j++) {
			if(i+j<ARR_LEN) array[i+j] = i+(100-j);
		}
	}
	cout << "Fertig. " << endl << endl << "   Starte Insertionsort... " << flush;
	begin = clock();
	vergleiche = insertionsort_count(array, ARR_LEN);
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Fertig." << endl << "   Prozessorzeit: " << elapsed_secs << "s" << endl << "   Vergleiche: " << vergleiche << endl << endl << "   Starte Quicksort... "<< flush;
	vergleiche = 0;
	begin = clock();
	QuicksortTable(0,ARR_LEN-1, array, vergleiche);
	end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Fertig." << endl << "   Prozessorzeit: " << elapsed_secs << "s" << endl << "   Vergleiche: " << vergleiche << endl << endl;
}
