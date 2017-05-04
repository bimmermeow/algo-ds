#include "stack.cpp"
#include <iostream>
#include <string>

using namespace std;

string to_postfix(string infix) {
	Stack<char> stack;
	string postfix;
	int len = infix.length();
	for (int i = 0; i < len; i++) {
		char c = infix[i];
		if(c=='(') {
			stack.push(c);
		} else if(isdigit(c)) {
			postfix += c;
		} else if(c=='+' || c=='-') {
			while(stack.top()=='-' || stack.top()=='+' || stack.top()=='/' || stack.top()=='*') postfix+=stack.pop();
			stack.push(c);
		} else if(c=='*' || c=='/') {
			while (stack.top()=='/' || stack.top()=='*') postfix+=stack.pop();
			stack.push(c);
		} else if(c==')') {
			while(stack.top()!='(') postfix+=stack.pop();
			stack.pop();
		} else {
			postfix = "Es wurde ein Zeichen nicht erkannt. Bitte nur Klammern, Zahlen und Operatoren verwenden.";
		}
	}
	return postfix;
}

int calc_postfix(string postfix) {
	Stack<int> stack;
	int len = postfix.length();
	for (int i = 0; i < len; i++) {
		char c = postfix[i];
		if(isdigit(c)) {
			stack.push(isdigit(c));
		} else if(c=='+') {
			stack.push(stack.pop()+stack.pop());
		} else if(c=='-') {
			int var1 = stack.pop();
			int var2 = stack.pop();
			stack.push(var2-var1);
		} else if(c=='*') {
			stack.push(stack.pop()*stack.pop());
		} else if(c=='/') {
			int var1 = stack.pop();
			int var2 = stack.pop();
			stack.push(var2-var1);
		}
	}
	return stack.pop();
}

int main() {
	cout << "        Bitte Eingabe in Infix-Notation: " << endl;
	string eingabe;
	cin >> eingabe;
	cout << "Ihre Eingabe in Postfix-Notation lautet: " << to_postfix(eingabe) << endl;
	cout << "         Das Ergebnis ihrer Eingabe ist: " << calc_postfix(eingabe) << endl;
	return 0;
}
