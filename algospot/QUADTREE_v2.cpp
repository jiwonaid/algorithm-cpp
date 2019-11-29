#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverse(string::iterator& it) {
	char head = *it;
	++it;
	if (head == 'b' || head == 'w')
		return string(1, head);
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);

	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	vector<string> answers;
	int C;
	string input;

	cin >> C;
	
	for (int i = 0; i < C; ++i) {
		cin >> input;
		string::iterator it = input.begin();
		answers.push_back(reverse(it));
	}

	for (vector<string>::const_iterator ci = answers.begin(); ci != answers.end(); ++ci) {
		cout << *ci << endl;
	}

	return 0;
}
