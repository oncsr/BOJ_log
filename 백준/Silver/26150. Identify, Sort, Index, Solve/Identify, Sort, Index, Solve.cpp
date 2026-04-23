#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, b, c;
	string a;
	vector<pair<int, char> > V;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		c--;
		if (a[c] > 90)	a[c] -= 32;
		V.push_back({ b, a[c] });
	}
	sort(V.begin(), V.end());
	for (auto& i : V)	cout << i.second;
}