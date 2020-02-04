#include <iostream>

using namespace std;

enum Command { PUSH, POP, SIZE, EMPTY, TOP };

Command convert(const string& str) {
	if (str == "push") return PUSH;
	else if (str == "pop") return POP;
	else if (str == "size") return SIZE;
	else if (str == "empty") return EMPTY;
	else if (str == "top") return TOP;
}

class Stack {
private:
	int size;
	int arr[10001];
public:
	Stack() {
		size = 0;
	}

	void push(int x) {
		size++;
		arr[size] = x;
	}
	void pop() {
		if (size == 0)
			cout << -1 << endl;
		else {
			cout << arr[size] << endl;
			size--;
		}
	}
	void getSize() {
		cout << size << endl;
	}
	void empty() {
		if (size == 0)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	void top() {
		if (size == 0)
			cout << -1 << endl;
		else {
			cout << arr[size] << endl;
		}
	}
};

int main() {
	int N, intInput;
	string strInput;
	Stack st;
	Command cd;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> strInput;
		if (strInput == "push")
			cin >> intInput;

		cd = convert(strInput);
		switch (cd) {
			case PUSH:
				st.push(intInput);
				break;
			case POP:
				st.pop();
				break;
			case SIZE:
				st.getSize();
				break;
			case EMPTY:
				st.empty();
				break;
			case TOP:
				st.top();
				break;
		}
	}

	return 0;
}