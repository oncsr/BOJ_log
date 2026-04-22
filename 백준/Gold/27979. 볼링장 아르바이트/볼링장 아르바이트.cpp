#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)	cin >> v[i];
	vector<int> base = v;
	sort(v.begin(), v.end(), greater<int>());
	int s = N, j = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (v[j] == base[i])	j++, s--;
	}
	cout << s;
}