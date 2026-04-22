#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	vector<int> ans;
	for (cin >> N, cin.ignore(); N--;) {
		string a;
		getline(cin, a);
		char temp = ' ';
		int len = 0;
		for (char i : a) {
			if (temp == ' ' && i != ' ')	len++;
			temp = i;
		}
		ans.push_back(len);
	}
	sort(ans.begin(), ans.end());
	int cnt = 1, temp = ans[0];
	cout << ans[0] << ' ';
	for (int i = 1; i < ans.size(); i++) {
		if (temp != ans[i]) {
			cout << cnt << '\n' << ans[i] << ' ';
			cnt = 1;
		}
		else	cnt++;
		temp = ans[i];
	}
	cout << cnt;
}