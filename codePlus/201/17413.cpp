#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	string S, result = "";
	stack<char> st;

	getline(cin, S);
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == '<') {
			while (!st.empty()) {
				result += st.top();
				st.pop();
			}
			while (S[i] != '>') {
				result += S[i];
				i++;
			}
			result += S[i];
		}
		else if (S[i] == ' ') {
			while (!st.empty()) {
				result += st.top();
				st.pop();
			}
			result += S[i];
		}
		else {
			st.push(S[i]);
		}
	}

	if (!st.empty()) {
		while (!st.empty()) {
			result += st.top();
			st.pop();
		}
	}
	cout << result << endl;

	return 0;
}