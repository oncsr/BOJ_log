#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, a;
	vector<int> V;
	cin >> N >> a;
	for (int i = 1; i < N; i++) {
		cin >> a;
		if (V.empty())	V.push_back(a - 1);
		else {
			int find = 0;
			for (int j : V) {
				if ((a - 1) % j == 0) {
					find = 1;
					break;
				}
			}
			if (!find)	V.push_back(a - 1);
		}
	}
	cout << V.size();
}