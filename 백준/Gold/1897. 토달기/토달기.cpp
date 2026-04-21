#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	string s;
	cin >> N >> s;
	vector<string> arr;
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		arr.push_back(a);
	}
	int cango[1001][1001]{};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)	continue;
			if (arr[i].size() + 1 != arr[j].size())	continue;
			int pos = 0;
			for (char k : arr[j]) {
				if (k == arr[i][pos])	pos++;
				if (pos == arr[i].size())	break;
			}
			if (pos == arr[i].size())	cango[i][j] = 1;
		}
	}
	int now[1001]{}, cnt = 1;
	for (int i = 0; i < N; i++)	if (arr[i] == s)	now[i] = 1;
	string ans = s;
	while (cnt > 0) {
		int next[1001]{};
		for (int i = 0; i < N; i++) {
			if (!now[i])	continue;
			for (int j = 0; j < N; j++) {
				if (!cango[i][j])	continue;
				
				next[j] = 1;
			}
		}
		cnt = 0;
		for (int i = 0; i < N; i++) {
			if (next[i]) {
				cnt++;
				if (arr[i].size() > ans.size())	ans = arr[i];
			}
			now[i] = next[i];
		}
	}

	cout << ans;


}