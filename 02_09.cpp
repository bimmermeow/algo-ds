#include <iostream>
#include <stdio.h>

using namespace std;

void printCharArrayIteratively(char* charArr, int length) {
	for(int i=0;i<length;i++) {
		cout << charArr[i];
	}
}
void printCharArrayRecursively(char* charArr, int length) {
	if (length!=0) {
		cout << charArr[0];
		printCharArrayRecursively(++charArr, length-1);
	}
}

int main() {
	cout << "Ein String wird nun iterativ ausgegeben:"<< endl << endl;
	char str[11] = "teststring";
	printCharArrayIteratively(str, 10);
	cout << endl << endl << "Ein String wird nun rekursiv ausgegeben:"<< endl << endl;
	printCharArrayRecursively(str, 10);
	getchar();
	return 0;
}
