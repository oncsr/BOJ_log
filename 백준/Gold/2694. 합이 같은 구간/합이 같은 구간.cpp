#include <bits/stdc++.h>
using namespace std;

vector<int> divd;

void cal(vector<pair<int, int>> V, int now, int res) {
	if (now == V.size()) {
		divd.push_back(res);
		return;
	}
	for (int i = 0; i <= V[now].second; i++) {
		cal(V, now + 1, res);
		res *= V[now].first;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int e[10001]{};
	for (int i = 2; i * i <= 10000; i++)
		if (!e[i])
			for (int j = i * i; j <= 10000; j += i)
				e[j] = 1;

	vector<int> prime;
	for (int i = 2; i <= 10000; i++)
		if (!e[i])	prime.push_back(i);

	int T;
	for (cin >> T; T--;) {
		int N, arr[10000]{}, S = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			S += arr[i];
		}

		divd = vector<int>();
		int G = S;
		vector<pair<int, int>> V;
		for (int i : prime) {
			if (i * i > G)	break;
			if (G % i)	continue;
			int fir = i, cnt = 0;
			while (G % i == 0) {
				G /= i;
				cnt++;
			}
			V.push_back({ fir, cnt });
		}
		if (G > 1)	V.push_back({ G, 1 });

		cal(V, 0, 1);
		sort(divd.begin(), divd.end());

		int ans = S;
		for (int i : divd) {
			int S2 = 0;
			bool poss = 1;
			for (int j = 0; j < N; j++) {
				S2 += arr[j];
				if (S2 == i)	S2 = 0;
				else if (S2 > i) { poss = 0; break; }
			}
			if (S2 != i && S2 != 0)	poss = 0;
			if (poss) { ans = i; break; }
		}
		cout << ans << '\n';

	}

}