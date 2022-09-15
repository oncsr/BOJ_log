#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;	cin >> n;
	
	vector<pair<int, string> > v;
	while (n--) {
		string c;
		cin >> c;
		v.push_back({ c.size(), c });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i].second == v[i + 1].second) {
			continue;
		}
		cout << v[i].second << '\n';
	}
	cout << v[v.size() - 1].second << '\n';
}