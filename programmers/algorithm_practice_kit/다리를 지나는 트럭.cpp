#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int runningW = weight;
	deque<pair<int, int>> bridge;

	vector<int>::const_iterator it = truck_weights.begin();
	while (!bridge.empty() || it != truck_weights.end()) {
		answer++;
		if (!bridge.empty()) {
			for (deque<pair<int, int>>::iterator iter = bridge.begin(); iter != bridge.end(); ++iter) {
				(*iter).first -= 1;
			}
			if (bridge.front().first == 0) {
				runningW += bridge.front().second;
				bridge.pop_front();
			}
		}
		if (it != truck_weights.end()) {
			if (runningW >= *it) {
				runningW -= *it;
				bridge.push_back({ bridge_length, *it });
				it++;
			}
		}
	}

	return answer;
}