#include <iostream>
#include "stack.cpp"
using namespace std;


int main() {
	Stack<int> stack;
	stack.push(3);
	cout << stack.top() << endl;
	stack.push(4);
	cout << stack.top() << endl;
	stack.push(12);
	cout << stack.top() << endl;
	cout << stack.top() << endl;
	// cout << stack.length() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	// cout << stack.pop() << endl;
	// cout << stack.pop() << endl;
	return 0;
}
