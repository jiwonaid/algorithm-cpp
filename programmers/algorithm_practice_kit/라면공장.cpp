#include <string>
#include <vector>
#include <map>

using namespace std;

multimap<int, int, greater<int>> plan;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	for (int i = 0; i < supplies.size(); ++i)
		plan.insert({ supplies[i], dates[i] });

	while (stock < k) {
		for (multimap<int, int>::iterator it = plan.begin(); it != plan.end(); ++it) {
			if (it->second <= stock) {
				answer++;
				stock += it->first;
				plan.erase(it);
				break;
			}
		}
	}

	return answer;
}