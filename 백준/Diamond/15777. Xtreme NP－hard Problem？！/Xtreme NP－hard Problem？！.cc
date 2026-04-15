#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K;
	cin >> N >> M >> K;
	vector<tuple<int, int, ll>> edge(M);
	for (auto& [a, b, c] : edge)	cin >> a >> b >> c;

	if (N <= 5) {
		if (K >= N)	cout << -1;
		else {
			ll cost[6][6]{};
			for (auto& [a, b, c] : edge) {
				if (!cost[a][b])	cost[a][b] = cost[b][a] = c;
				else	cost[a][b] = cost[b][a] = min(cost[a][b], c);
			}
			// K-1개의 수를 2~(N-1) 중에서 고르기
			vector<vector<int>> all;
			function<void(int, vector<int>)> comb = [&](int pos, vector<int> choice) -> void {
				if (pos == K - 1) {
					choice.push_back(N);
					all.push_back(choice);
					return;
				}
				for (int i = 2; i <= N - 1; i++) {
					int no = 0;
					for (int j : choice)	if (j == i)	no++;
					if (!no) {
						choice.push_back(i);
						comb(pos + 1, choice);
						choice.pop_back();
					}
				}
			};
			comb(0, { 1 });

			ll res = -1;
			for (auto& route : all) {
				ll v = 0;
				for (int j = 1; j < route.size(); j++) {
					int a = route[j - 1], b = route[j];
					if (!cost[a][b]) { v = -1; break; }
					v += cost[a][b];
				}
				if (v == -1)	continue;
				res = (res == -1 ? v : min(res, v));
			}
			cout << res;
		}
	}
	else if (M <= 5) {
		if (K > M)	cout << -1;
		else {
			set<int> temp;
			for (auto& [a, b, c] : edge)	temp.insert(a), temp.insert(b);
			int c = 1;
			map<int, int> num;
			for (int i : temp)	num[i] = c++;
			if (!num[1]) { cout << -1; return 0; }

			ll cost[11][11]{};
			for (auto [a, b, c] : edge) {
				a = num[a], b = num[b];
				if (!cost[a][b])	cost[a][b] = cost[b][a] = c;
				else	cost[a][b] = cost[b][a] = min(cost[a][b], c);
			}
			// K-1개의 수를 2~(N-1) 중에서 고르기
			vector<vector<int>> all;
			function<void(int, vector<int>)> comb = [&](int pos, vector<int> choice) -> void {
				if (pos == K - 1) {
					choice.push_back(num[N]);
					all.push_back(choice);
					return;
				}
				for (int i = 2; i <= num[N] - 1; i++) {
					int no = 0;
					for (int j : choice)	if (j == i)	no++;
					if (!no) {
						choice.push_back(i);
						comb(pos + 1, choice);
						choice.pop_back();
					}
				}
			};
			comb(0, { 1 });

			ll res = -1;
			for (auto& route : all) {
				ll v = 0;
				for (int j = 1; j < route.size(); j++) {
					int a = route[j - 1], b = route[j];
					if (!cost[a][b]) { v = -1; break; }
					v += cost[a][b];
				}
				if (v == -1)	continue;
				res = (res == -1 ? v : min(res, v));
			}
			cout << res;

		}
	}
	else {
		if (K == 1) {
			for (auto& [a, b, c] : edge) {
				if (min(a, b) == 1 && max(a, b) == N) { cout << c; return 0; }
			}
			cout << -1;
		}
		else if (K == 2) {
			vector<vector<pair<int, ll>>> V(N + 1);
			for (auto& [a, b, c] : edge) {
				V[a].emplace_back(b, c);
				V[b].emplace_back(a, c);
			}
			int res = -1;
			for (int i = 2; i < N; i++) {
				int A = 0, B = 0;
				for (auto& [j, c] : V[i]) {
					if (j == 1)	A = c;
					if (j == N)	B = c;
				}
				if (!A || !B)	continue;
				if (res == -1)	res = A + B;
				else	res = min(res, A + B);
			}
			cout << res;
		}
		else if (K == 3) {
			vector<int> to1(N + 1);
			vector<int> toN(N + 1);
			for (auto& [a, b, c] : edge) {
				if (a == 1 && b != N)	to1[b] = c;
				if (a == N && b != 1)	toN[b] = c;
				if (b == 1 && a != N)	to1[a] = c;
				if (b == N && a != 1)	toN[a] = c;
			}
			int res = -1;
			for (auto& [a, b, c] : edge) {
				if (to1[a] && toN[b]) {
					int v = to1[a] + toN[b] + c;
					res = (res == -1 ? v : min(res, v));
				}
				if (toN[a] && to1[b]) {
					int v = toN[a] + to1[b] + c;
					res = (res == -1 ? v : min(res, v));
				}
			}

			cout << res;
		}
		else if (K == 5) {
			vector<int> to1(N + 1);
			vector<int> toN(N + 1);
			for (auto& [a, b, c] : edge) {
				if (a == 1 && b != N)	to1[b] = c;
				if (a == N && b != 1)	toN[b] = c;
				if (b == 1 && a != N)	to1[a] = c;
				if (b == N && a != 1)	toN[a] = c;
			}

			vector<tuple<int, int, int, int, int, int>> toto1(N + 1);
			vector<tuple<int, int, int, int, int, int>> totoN(N + 1);
			for (auto& [a, b, c] : edge) {
				if (to1[a] && b != N) {
					auto& [p1, q1, p2, q2, p3, q3] = toto1[b];
					int v = to1[a] + c;
					if (!p1)	p1 = a, q1 = v;
					else {
						if (v < q1) {
							p3 = p2, q3 = q2;
							p2 = p1, q2 = q1;
							p1 = a, q1 = v;
						}
						else {
							if (!p2)	p2 = a, q2 = v;
							else {
								if (v < q2) {
									p3 = p2, q3 = q2;
									p2 = a, q2 = v;
								}
								else if (!p3 || v < q3)	p3 = a, q3 = v;
							}
						}
					}
				}
				if (to1[b] && a != N) {
					auto& [p1, q1, p2, q2, p3, q3] = toto1[a];
					int v = to1[b] + c;
					if (!p1)	p1 = b, q1 = v;
					else {
						if (v < q1) {
							p3 = p2, q3 = q2;
							p2 = p1, q2 = q1;
							p1 = b, q1 = v;
						}
						else {
							if (!p2)	p2 = b, q2 = v;
							else {
								if (v < q2) {
									p3 = p2, q3 = q2;
									p2 = b, q2 = v;
								}
								else if (!p3 || v < q3)	p3 = b, q3 = v;
							}
						}
					}
				}
				if (toN[a] && b != 1) {
					auto& [p1, q1, p2, q2, p3, q3] = totoN[b];
					int v = toN[a] + c;
					if (!p1)	p1 = a, q1 = v;
					else {
						if (v < q1) {
							p3 = p2, q3 = q2;
							p2 = p1, q2 = q1;
							p1 = a, q1 = v;
						}
						else {
							if (!p2)	p2 = a, q2 = v;
							else {
								if (v < q2) {
									p3 = p2, q3 = q2;
									p2 = a, q2 = v;
								}
								else if (!p3 || v < q3)	p3 = a, q3 = v;
							}
						}
					}
				}
				if (toN[b] && a != 1) {
					auto& [p1, q1, p2, q2, p3, q3] = totoN[a];
					int v = toN[b] + c;
					if (!p1)	p1 = b, q1 = v;
					else {
						if (v < q1) {
							p3 = p2, q3 = q2;
							p2 = p1, q2 = q1;
							p1 = b, q1 = v;
						}
						else {
							if (!p2)	p2 = b, q2 = v;
							else {
								if (v < q2) {
									p3 = p2, q3 = q2;
									p2 = b, q2 = v;
								}
								else if (!p3 || v < q3)	p3 = b, q3 = v;
							}
						}
					}
				}
			}

			int res = -1;
			for (auto& [a, b, c] : edge) {
				// 1-a, b-N인지 확인
				auto& [p1, cp1, q1, cq1, r1, cr1] = toto1[a];
				auto& [p2, cp2, q2, cq2, r2, cr2] = totoN[b];

				vector<pair<int, int>> left, right;
				if (p1)	left.emplace_back(p1, cp1);
				if (q1)	left.emplace_back(q1, cq1);
				if (r1)	left.emplace_back(r1, cr1);
				if (p2)	right.emplace_back(p2, cp2);
				if (q2)	right.emplace_back(q2, cq2);
				if (r2)	right.emplace_back(r2, cr2);

				for (auto& [aaa, bbb] : left) {
					for (auto& [ccc, ddd] : right) {
						if (1 == aaa || 1 == a || 1 == b || 1 == ccc || 1 == N)	continue;
						if (aaa == a || aaa == b || aaa == ccc || aaa == N)	continue;
						if (a == b || a == ccc || a == N)	continue;
						if (b == ccc || b == N)	continue;
						if (ccc == N)	continue;
						int v = bbb + ddd + c;
						res = (res == -1 ? v : min(res, v));
					}
				}

			}
			for (auto& [a, b, c] : edge) {
				// N-a, b-1인지 확인
				auto& [p1, cp1, q1, cq1, r1, cr1] = totoN[a];
				auto& [p2, cp2, q2, cq2, r2, cr2] = toto1[b];

				vector<pair<int, int>> left, right;
				if (p1)	left.emplace_back(p1, cp1);
				if (q1)	left.emplace_back(q1, cq1);
				if (r1)	left.emplace_back(r1, cr1);
				if (p2)	right.emplace_back(p2, cp2);
				if (q2)	right.emplace_back(q2, cq2);
				if (r2)	right.emplace_back(r2, cr2);

				for (auto& [aaa, bbb] : left) {
					for (auto& [ccc, ddd] : right) {
						if (N == aaa || N == a || N == b || N == ccc || N == 1)	continue;
						if (aaa == a || aaa == b || aaa == ccc || aaa == 1)	continue;
						if (a == b || a == ccc || a == 1)	continue;
						if (b == ccc || b == 1)	continue;
						if (ccc == 1)	continue;
						int v = bbb + ddd + c;
						res = (res == -1 ? v : min(res, v));
					}
				}
			}
			cout << res;

		}
		else {
			// 지나는 점 1, 최솟값, 지나는 점 2, 두 번째 최솟값
			vector<int> to1(N + 1);
			vector<int> toN(N + 1);
			for (auto& [a, b, c] : edge) {
				if (a == 1 && b != N)	to1[b] = c;
				if (a == N && b != 1)	toN[b] = c;
				if (b == 1 && a != N)	to1[a] = c;
				if (b == N && a != 1)	toN[a] = c;
			}

			vector<tuple<int, int, int, int>> toto1(N + 1);
			vector<tuple<int, int, int, int>> totoN(N + 1);
			for (auto& [a, b, c] : edge) {
				if (to1[a] && b != N) {
					auto& [p, q, r, s] = toto1[b];
					int v = to1[a] + c;
					if (!p)	p = a, q = v;
					else {
						if (v < q) {
							r = p, s = q;
							p = a, q = v;
						}
						else if (!r || v < s)	r = a, s = v;
					}
				}
				if (to1[b] && a != N) {
					auto& [p, q, r, s] = toto1[a];
					int v = to1[b] + c;
					if (!p)	p = b, q = v;
					else {
						if (v < q) {
							r = p, s = q;
							p = b, q = v;
						}
						else if (!r || v < s)	r = b, s = v;
					}
				}
				if (toN[a] && b != 1) {
					auto& [p, q, r, s] = totoN[b];
					int v = toN[a] + c;
					if (!p)	p = a, q = v;
					else {
						if (v < q) {
							r = p, s = q;
							p = a, q = v;
						}
						else if (!r || v < s)	r = a, s = v;
					}
				}
				if (toN[b] && a != 1) {
					auto& [p, q, r, s] = totoN[a];
					int v = toN[b] + c;
					if (!p)	p = b, q = v;
					else {
						if (v < q) {
							r = p, s = q;
							p = b, q = v;
						}
						else if (!r || v < s)	r = b, s = v;
					}
				}
			}

			int res = -1;
			for (int i = 2; i < N; i++) {
				auto& [p1, q1, r1, s1] = toto1[i];
				auto& [p2, q2, r2, s2] = totoN[i];
				if (!p1 || !p2)	continue;
				if (p1 != p2) {
					int v = q1 + q2;
					res = (res == -1 ? v : min(res, v));
				}
				else {
					if (r1) {
						int v = q2 + s1;
						res = (res == -1 ? v : min(res, v));
					}
					if (r2) {
						int v = q1 + s2;
						res = (res == -1 ? v : min(res, v));
					}
				}
			}
			cout << res;
		}
	}

}