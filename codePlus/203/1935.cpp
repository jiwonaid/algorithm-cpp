#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

double operation(double a, double b, char oper) {
	switch (oper) {
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	case '/':
		return a / b;
		break;
	}
}

int main() {
	const char oper[] = { '+','-','*','/' };
	int N;
	double values[26];
	string notation;
	stack<double> st;

	cin >> N;
	cin >> notation;
	for (int i = 0; i < N; ++i)
		cin >> values[i];

	for (int i = 0; i < notation.length(); ++i) {
		if (find(oper, oper + 4, notation[i]) != oper + 4) {
			double b = st.top();
			st.pop();
			double a = st.top();
			st.pop();
			st.push(operation(a, b, notation[i]));
		}
		else {
			st.push(values[notation[i] - 'A']);
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << st.top();

	return 0;
}