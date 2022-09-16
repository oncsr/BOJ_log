#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, a, b, s = 0, c = 0;
	cin >> n;
	vector<pair<int, int> > V;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		V.push_back({b,a});
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < n; i++) {
		if (c <= V[i].second) {
			s++;
			c = V[i].first;
		}
	}
	cout << s;
}