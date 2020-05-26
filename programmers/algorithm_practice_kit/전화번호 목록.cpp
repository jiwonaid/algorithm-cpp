#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<unordered_set<string>> uS;

bool solution(vector<string> phone_book) {
	bool answer = true;
	uS.resize(21, unordered_set<string>());
	for (vector<string>::iterator it = phone_book.begin(); it != phone_book.end(); ++it)
		uS[(*it).length()].insert(*it);

	for (vector<string>::iterator it = phone_book.begin(); it != phone_book.end(); ++it) {
		for (size_t i = 1; i < 21; ++i) {
			if (i == (*it).length())
				break;
			if (uS[i].find((*it).substr(0, i)) != uS[i].end()) {
				answer = false;
				return answer;
			}
		}
	}

	return answer;
}