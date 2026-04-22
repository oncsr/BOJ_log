#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> cnt;

bool cmp(string a, string b) {
	if (cnt[a] == cnt[b]) {
		if (a.size() == b.size())	return a < b;
		return a.size() > b.size();
	}
	return cnt[a] > cnt[b];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;
	vector<string> arr;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		if (a.size() < M)	continue;
		if (!cnt[a])	arr.push_back(a);
		cnt[a]++;
	}
	sort(arr.begin(), arr.end(), cmp);
	for (string i : arr)	cout << i << '\n';
}