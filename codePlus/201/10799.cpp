#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string bat;
	int result = 0;
	stack<char> st;

	getline(cin, bat);
	for (int i = 0; i < bat.size(); ++i) {
		if (bat[i] == '(') {
			st.push('(');
		}
		else {
			if (bat[i - 1] == '(') {
				st.pop();
				result += st.size();
			}
			else {
				st.pop();
				result += 1;
			}
		}
	}
	cout << result;

	return 0;
}