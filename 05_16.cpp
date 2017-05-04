#include <iostream>
#include <stack>
// using namespace std;


int main() {
	std::stack<int> s;
	s.push(3);
	std::cout << s.top() << std::endl;
	s.push(4);
	std::cout << s.top() << std::endl;
	s.push(12);
	std::cout << s.top() << std::endl;
	// cout << s.length() << endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	// cout << s.pop() << endl;
	// cout << s.pop() << endl;
	return 0;
}
