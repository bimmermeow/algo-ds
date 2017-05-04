#include <stack>
#include <iostream>
#include <string>

#define DEBUG false
using namespace std;

string to_postfix(string infix) {
	stack<char> s;
	string postfix;
	int len = infix.length();
	for (int i = 0; i < len; i++) {
		char c = infix[i];
		if(DEBUG) cout << c << endl;
		if(c=='(') {
			s.push(c);
		} else if(isdigit(c)) {
			postfix += c;
			if(DEBUG) cout << "Zahl: Auf stapel gelegt" << endl;
		} else if(c=='+' || c=='-') {
			if(DEBUG) cout << "+/- Operator " << endl;
			while(!s.empty() && (s.top()=='-' || s.top()=='+' || s.top()=='/' || s.top()=='*')) {
				postfix += s.top();
				s.pop();
			}
			s.push(c);
		} else if(c=='*' || c=='/') {
			while (!s.empty() && (s.top()=='/' || s.top()=='*')) {
				postfix+=s.top();
				if(DEBUG) cout << c << endl;
				s.pop();
			}
			s.push(c);
		} else if(c==')') {
			while(s.top()!='(') {
				postfix+=s.top();
				s.pop();
			}
			s.pop();
		} else {
			postfix = "Es wurde ein Zeichen nicht erkannt. Bitte nur Klammern, Zahlen und Operatoren verwenden.";
		}
	}
	while(!s.empty()) {
		postfix += s.top();
		s.pop();
	}
	return postfix;
}

int calc_postfix(string postfix) {
	stack<int> s;
	int len = postfix.length();
	for (int i = 0; i < len; i++) {
		char c = postfix[i];
		if(DEBUG) cout << c << endl;
		if(isdigit(c)) {
			s.push((int)(c-'0'));
		} else if(c=='+') {
			int vara = s.top();
			s.pop();
			int varb = s.top();
			s.pop();
			if(DEBUG) cout << "Rechenoperation + " << vara << varb << endl;
			s.push(varb+vara);
		} else if(c=='-') {
			int var1 = s.top();
			s.pop();
			int var2 = s.top();
			s.pop();
			s.push(var2-var1);
		} else if(c=='*') {
			int var1 = s.top();
			s.pop();
			int var2 = s.top();
			s.pop();
			s.push(var2*var1);
		} else if(c=='/') {
			int var1 = s.top();
			s.pop();
			int var2 = s.top();
			s.pop();
			s.push(var2-var1);
		}
	}
	int ret = s.top();
	s.pop();
	return ret;
}

int main() {
	cout << "        Bitte Eingabe in Infix-Notation: ";
	string eingabe;
	cin >> eingabe;
	string postfix = to_postfix(eingabe);
	cout << "Ihre Eingabe in Postfix-Notation lautet: " << postfix << endl;
	cout << "         Das Ergebnis ihrer Eingabe ist: " << calc_postfix(postfix) << endl;
	return 0;
}
