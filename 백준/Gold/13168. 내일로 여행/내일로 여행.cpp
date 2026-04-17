#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll travel(vector<int> course, vector<tuple<string, int, int, ll>> edge) {
	ll res = 0;
	vector<vector<ll>> dist(101, vector<ll>(101, 1e12));
	for (auto [a, b, c, d] : edge)	dist[b][c] = min(dist[b][c], d);

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			for (int k = 1; k <= 100; k++) {
				if (dist[j][k] > dist[j][i] + dist[i][k])	dist[j][k] = dist[j][i] + dist[i][k];
			}
		}
	}

	for (int i = 0; i < course.size() - 1; i++) {
		int s = course[i], e = course[i + 1];
		res += dist[s][e];
	}

	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, R, num = 1;
	cin >> N >> R;
	R <<= 1;
	map<string, int> city;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		if (!city[s])	city[s] = num++;
	}
	int M;
	vector<int> course;
	for (cin >> M; M--;) {
		string s;
		cin >> s;
		course.push_back(city[s]);
	}

	vector<tuple<string, int, int, ll>> edge;
	int K;
	for (cin >> K; K--;) {
		string s, a, b;
		int c;
		cin >> s >> a >> b >> c;
		c <<= 1;
		edge.emplace_back(s, city[a], city[b], c);
		edge.emplace_back(s, city[b], city[a], c);
	}

	ll base = travel(course, edge);
	for (auto& [a, b, c, d] : edge) {
		if (a == "Mugunghwa" || a == "ITX-Saemaeul" || a == "ITX-Cheongchun")	d = 0;
		if (a == "S-Train" || a == "V-Train")	d >>= 1;
	}
	ll tick = travel(course, edge);
	cout << (tick + R < base ? "Yes" : "No");


}