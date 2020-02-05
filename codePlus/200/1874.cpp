#include <iostream>
#include <string>
#include <stack>

using namespace std;

int cur;
stack<int> arrStack;

string getNumber(int number) {
	string ret = "";

	if (number > cur) {
		int n = number - cur;
		while (n--) {
			arrStack.push(++cur);
			ret += "+\n";
		}
	}
	else {
		while (number < arrStack.top()) {
			arrStack.pop();
			ret += "-\n";
		}
	}
	if (number == arrStack.top()) {
		arrStack.pop();
		ret += "-\n";
	}
	else {
		ret = "NO";
	}

	return ret;
}

int main() {
	int n, number;
	string result, temp;

	cur = 0;
	arrStack.push(cur);
	cin >> n;
	while (n--) {
		cin >> number;
		temp = getNumber(number);
		if (temp == "NO") {
			result = "NO";
			break;
		}
		else
			result += temp;
	}
	cout << result;

	return 0;
}