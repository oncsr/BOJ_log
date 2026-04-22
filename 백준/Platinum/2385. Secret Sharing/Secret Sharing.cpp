#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool bcmp(string a, string b) {
	return a + b < b + a;
}

bool wcmp(pair<string, string> a, pair<string, string> b) {
	return a.first + a.second < b.first + b.second;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n;
	cin >> n;
	vector<vector<string> > V(10);
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		V[a[0] - '0'].push_back(a);
	}
	if (!V[0].empty()) {
		sort(V[0].begin(), V[0].end(), bcmp);
		int j = -1;
		for (int i = 1; i < 10; i++) {
			if (V[i].empty())	continue;
			j = i;
			break;
		}
		if (j == -1) {
			cout << "INVALID";
			return 0;
		}
		vector<pair<string, string> > W;
		for (int i = 0; i < V[j].size(); i++) {
			W.push_back({ V[j][i], V[0][0] });
		}
		sort(W.begin(), W.end(), wcmp);

		string tep = W[0].first;
		int id = 0;
		for (int i = 1; i < W.size(); i++) {
			string next = W[i].first;
			if (next.size() < tep.size())	break;
			if (tep == next)	continue;
			string next_part = next.substr(0, tep.size());
			if (next_part != tep)	break;
			bool fd = 1;
			for (int k = tep.size(); k < next.size(); k++) {
				if (next[k] == '0')	continue;
				fd = 0;
				break;
			}
			if (fd)	tep = next, id = i;
			else	break;
		}

		
		cout << tep << W[0].second;
		vector<string> temp;
		int cnt = 1;
		for (int i = 0; i < V[j].size(); i++) {
			if (W[id].first == V[j][i] && cnt) {
				cnt--;
				continue;
			}
			temp.push_back(V[j][i]);
		}
		V[j] = temp;
		sort(V[0].begin() + 1, V[0].end(), bcmp);
	}
	for (int i = 1; i < 10; i++) {
		if (V[i].empty())	continue;
		sort(V[i].begin(), V[i].end(), bcmp);
	}

	for (int i = 0; i < 10; i++) {
		if (V[i].empty())	continue;
		if (i == 0) {
			for (int k = 1; k < V[0].size(); k++)	cout << V[0][k];
		}
		else {
			for (int k = 0; k < V[i].size(); k++)	cout << V[i][k];
		}
	}
}