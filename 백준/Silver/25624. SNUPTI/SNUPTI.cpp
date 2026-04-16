#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, M;
	cin >> N >> M;
	set<char> arr[26]{};
	set<string> chk;
	for (int i = 0; i < M; i++) {
		string a;
		cin >> a;
		if (chk.count(a))	return cout << "NO", 0;
		chk.insert(a);
		for (int j = 0; j < a.size(); j++)	arr[j].insert(a[j]);
	}

	int cnt = 1;
	for (int i = 0; i < N; i++) {
		cnt *= arr[i].size();
		for (int j = i + 1; j < N; j++) {
			for (char a : arr[i]) {
				if (arr[j].count(a))	return cout << "NO", 0;
			}
		}
	}
	if (cnt != M)	return cout << "NO", 0;

	set<string> temp;
	function<void(int, string)> make = [&](int pos, string now) -> void {
		if (pos == N) {
			temp.insert(now);
			return;
		}
		for (char i : arr[pos])	make(pos + 1, now + i);
	};
	make(0, "");
	if (temp != chk)	return cout << "NO", 0;
	
	cout << "YES\n";
	for (int i = 0; i < N; i++) {
		for (char k : arr[i])	cout << k;
		cout << '\n';
	}

}