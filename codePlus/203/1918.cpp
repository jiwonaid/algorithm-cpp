#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool isHigher(char oper1, char oper2) {
	// Everything is higher than '('
	if (oper2 == '(')
		return true;

	if (oper1 == '*' && (oper2 == '+' || oper2 == '-'))
		return true;
	else if (oper1 == '/' && (oper2 == '+' || oper2 == '-'))
		return true;
	else
		return false;
}

int main() {
	string notation, result;
	const char operArr[] = { '+', '-', '*', '/' };
	stack<char> st;
	
	cin >> notation;
	for (int i = 0; i < notation.length(); ++i) {
		if (notation[i] == '(')
			st.push('(');
		else if (notation[i] == ')') {
			while (st.top() != '(') {
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		else if (find(operArr, operArr + 4, notation[i]) == operArr + 4)
			result += notation[i];
		else {
			if (st.empty() || isHigher(notation[i], st.top())) {
				st.push(notation[i]);
			}
			else {
				while (!st.empty() && !isHigher(notation[i], st.top())) {
					result += st.top();
					st.pop();
				}
				st.push(notation[i]);
			}
		}
	}

	while (!st.empty())
	{
		result += st.top();
		st.pop();
	}

	cout << result;

	return 0;
}