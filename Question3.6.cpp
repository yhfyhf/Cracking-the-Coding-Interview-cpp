/**
 * Write a program to sort a stack in ascending order. You should not make any assumptions about how the stack is implemented.
 * The following are the only functions that should be used to write this program: push | pop | peek | isEmpty.
 */

#include <iostream>
#include <stack>
using namespace std;

stack<int> sortStack(stack<int> s) {
	stack<int> t;
	while (!s.empty()) {
		int data = s.top();
		s.pop();
		while (!t.empty() && t.top()>data) {
			s.push(t.top());
			t.pop();
		}
		t.push(data);
	}
	return t;
}

int main() {
	stack<int> s;
	for (int i = 10; i > 0 ; --i)
		s.push(i);
	s = sortStack(s);
	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}
