#include <bits/stdc++.h>
using namespace std;

int R, C;
int vis[999 * 702]{};
vector<vector<int>> V(999 * 702);
int deg[999 * 702]{};

int toint(string a) {
	int res = 0, pos;
	if ('0' <= a[1] && a[1] <= '9') {
		res += a[0] - 'A';
		pos = 1;
	}
	else {
		res += 26;
		res += 26 * (a[0] - 'A') + (a[1] - 'A');
		pos = 2;
	}

	string g = "";
	for (; pos < a.size(); pos++)	g += a[pos];
	int k = stoi(g);
	res += (k - 1) * C;

	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int now = i * C + j;
			string a;
			cin >> a;
			if (a == ".")	continue;
			string t1 = "";
			int idx = 0;
			while (idx < a.size() && a[idx] != '+')	t1 += a[idx++];
			V[toint(t1)].push_back(now);
			deg[now]++;
			if (idx == a.size())	continue;
			idx++;
			t1 = "";
			while (idx < a.size())	t1 += a[idx++];
			V[toint(t1)].push_back(now);
			deg[now]++;
		}
	}

	int c = 0;
	queue<int> Q;
	for (int i = 0; i < R * C; i++) {
		if (deg[i])	continue;
		Q.push(i);
		c++;
	}

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int i : V[now]) {
			if (!(--deg[i]))	Q.push(i), c++;
		}
	}
	cout << (c == R * C ? "no" : "yes");

}