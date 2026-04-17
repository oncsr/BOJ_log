#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> split(string a, char i) {
	vector<string> res;
	string temp = "";
	for (char now : a) {
		if (now == i) {
			if (temp != "") {
				res.push_back(temp);
				temp = "";
			}
			continue;
		}
		temp += now;
	}
	res.push_back(temp);
	return res;
}

bool cmp(tuple<int, string, bool> a, tuple<int, string, bool> b) {
	if (get<0>(a) == get<0>(b))	return get<1>(a) < get<1>(b);
	return get<0>(a) > get<0>(b);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	cin.ignore();
	vector<tuple<int, string, bool>> INFO;
	for (int i = 0; i < N; i++) {
		string line;
		getline(cin, line);
		string name;
		int score;
		bool hidden;
		// name
		int pos = 0;
		vector<string> SP1 = split(line, ',');
		vector<string> SP11 = split(SP1[0], ':');
		name = SP11[1].substr(1, SP11[1].size() - 2);

		score = stoi(split(SP1[1], ':')[1]);

		hidden = split(SP1[2], ':')[1][0] != '0';

		INFO.push_back({ score, name, hidden });

	}
	sort(INFO.begin(), INFO.end(), cmp);
	vector<tuple<int, string, int>> ans;
	int temp = 0, rank = 1, cnt = 1;
	for (auto [score, name, hidden] : INFO) {
		if (temp != score)	rank = cnt;
		cnt++;
		temp = score;
		if (hidden)	continue;
		ans.push_back({ rank, name, score });
	}

	for (auto [a, b, c] : ans)	cout << a << ' ' << b << ' ' << c << '\n';

}