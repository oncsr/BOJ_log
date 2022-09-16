#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int line = 0;
	int n;
	cin >> n;
	int temp;
	vector<pair<int, int> > v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		int a, b;
		a = v[i].first, b = v[i].second;
		if (i == 0) {
			line = (b - a);
			temp = b;
		}
		else {
			if (a <= temp) {
				if (b > temp) {
					line += (b - temp);
					temp = b;
				}

			}
			else {
				line += (b - a);
				temp = b;
			}
		}
	}
	cout << line << '\n';
}