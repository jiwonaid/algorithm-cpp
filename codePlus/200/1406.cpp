#include <iostream>
#include <list>

using namespace std;

int main() {
	string line;
	list<char> listLine;
	int M;
	char command, addedChar;

	cin >> line >> M;
	listLine = list<char>(line.begin(), line.end());
	list<char>::iterator it = listLine.end();
	while (M--) {
		cin >> command;
		if (command == 'L') {
			if (it != listLine.begin())
				it--;
		}
		else if (command == 'D') {
			if (it != listLine.end())
				it++;
		}
		else if (command == 'B') {
			if (it != listLine.begin()) {
				it--;
				it = listLine.erase(it);
			}
		}
		else {
			cin >> addedChar;
			it = listLine.insert(it, addedChar);
			it++;
		}
	}

	for (list<char>::const_iterator it = listLine.begin(); it != listLine.end(); ++it)
		cout << *it;

	return 0;
}