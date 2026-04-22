#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	for (cin >> T; T--;) {
		int arr[9]{}, id = 0, x = -1;
		int pos[9] = { 0,1,2,7,0,3,6,5,4 };
		for (int i = 0; i < 9; i++) {
			char a;
			cin >> a;
			if (i == 4)	continue;
			if (a == 'O')	arr[pos[i]] = 1;
			else {
				x = pos[i];
				arr[pos[i]] = 0;
			}
		}
		vector<int> ch;
		if (x == -1)	ch.push_back(8);
		else {
			int cnt = 0;
			for (int i = x; i < x + 8; i++) {
				if (arr[i % 8] == 0) {
					if (cnt)	ch.push_back(cnt);
					cnt = 0;
				}
				else	cnt++;
			}
			if (cnt)	ch.push_back(cnt);
			sort(ch.begin(), ch.end());
		}
		int n;
		cin >> n;
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			ans.push_back(a);
		}
		sort(ans.begin(), ans.end());
		if (ans == ch)	cout << "1\n";
		else	cout << "0\n";
	}
}