#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<double> values;
	vector<string> metrics;
	int N;

	cin >> N;

	for (int i = 0; i < N; ++i) {
		double value;
		string metric;

		cin >> value >> metric;

		if (metric == "kg") {
			value = value * 2.2046;
			metric = "lb";
		}
		else if (metric == "lb") {
			value = value * 0.4536;
			metric = "kg";
		}
		else if (metric == "l") {
			value = value * 0.2642;
			metric = "g";
		}
		else {
			value = value * 3.7854;
			metric = "l";
		}

		values.push_back(value);
		metrics.push_back(metric);
	}

	for (int i = 0; i < values.size(); ++i) {
		cout << (i + 1);
		cout << " ";
		printf("%.4f", values[i]);
		cout << " ";
		cout << metrics[i] << endl;
	}

	return 0;
}