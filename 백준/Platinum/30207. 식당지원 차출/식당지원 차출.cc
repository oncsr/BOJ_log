#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, Q;
	cin >> N;
	bool n3 = N % 3 == 0, br = 0;
	bool complete = 0;
	ll base[10001]{}, cur[10001]{}, cnt[20000001]{}, com, com2;
	priority_queue<ii, vector<ii>, greater<>> L;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		base[i] = cur[i] = a;
		cnt[a]++;
		if (cnt[a] == N) complete = 1, com = a, n3 = 0;
		L.push({ a, i });
	}

	cin >> Q;
	vector<pair<ii, int>> QR(Q);
	for (int i = 0; i < Q; i++) {
		cin >> QR[i].first.first >> QR[i].first.second;
		QR[i].second = i;
	}


	sort(QR.begin(), QR.end());

	ll day = 0, ans[100000]{};

	if (N == 3) {
		for (auto query : QR) {
			ll d = query.first.first, n = query.first.second, _ = query.second;
			ans[_] = d;
		}
	}
	else {
		for (auto query : QR) {
			ll d = query.first.first, n = query.first.second, _ = query.second;
			if (complete) {
				ll rem = (d - day) * 3, G = com + rem / N - base[n];
				if (n3)	rem += com2;
				if (rem % N == 0)	ans[_] = G;
				else {
					if (n <= rem % N)	ans[_] = G + 1;
					else	ans[_] = G;
				}
			}
			else {
				while (day < d) {
					ii A = L.top();
					L.pop();
					ii B = L.top();
					L.pop();
					ii C = L.top();
					L.pop();

					cnt[A.first++]--;
					cnt[A.first]++;

					if (n3 && cnt[A.first] == N && A.second == N) {
						com2 = 2;
						complete = 1;
						com = A.first;
						br = 1;
					}

					cnt[B.first++]--;
					cnt[B.first]++;

					if (n3 && cnt[B.first] == N && B.second == N) {
						com2 = 1;
						complete = 1;
						com = B.first;
						br = 1;
					}

					cnt[C.first++]--;
					cnt[C.first]++;

					cur[A.second] = A.first;
					cur[B.second] = B.first;
					cur[C.second] = C.first;

					L.push(A);
					L.push(B);
					L.push(C);

					day++;
					if (cnt[C.first] == N) {
						com = C.first;
						complete = 1;
						n3 = 0;
						break;
					}
					if (br)	break;

				}

				if (complete) {
					ll rem = (d - day) * 3, G = com + rem / N - base[n];
					if (n3)	rem += com2;
					if (rem % N == 0)	ans[_] = G;
					else {
						if (n <= rem % N)	ans[_] = G + 1;
						else	ans[_] = G;
					}
				}
				else	ans[_] = cur[n] - base[n];
			}
		}

	}

	for (int i = 0; i < Q; i++)	cout << ans[i] << '\n';
	
	
}