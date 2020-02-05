#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isVPS(const string& tData) {
	stack<char> st;

	for (int i = 0; i < tData.size(); ++i) {
		if (tData[i] == ')') {
			if (st.empty() || st.top() == ')')
				return false;
			else {
				st.pop();
			}
		}
		else {
			st.push(tData[i]);
		}
	}
	if (!st.empty())
		return false;
	
	return true;
}

int main() {
	int T;
	string tData;

	cin >> T;
	cin.ignore();
	while (T--) {
		getline(cin, tData);
		if (isVPS(tData))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}