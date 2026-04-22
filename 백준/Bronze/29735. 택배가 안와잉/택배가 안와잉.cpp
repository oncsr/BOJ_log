#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ii st, ed;
	char _;
	cin >> st.first >> _ >> st.second >> ed.first >> _ >> ed.second;
	int s = st.first * 60 + st.second;
	int e = ed.first * 60 + ed.second;

	int N, T;
	cin >> N >> T;
	int K = (e - s - 1) / T;
	cout << N / K << '\n';
	N %= K;
	s += (N + 1) * T;
	int h = s / 60, m = s % 60;
	if (h < 10)	cout << '0';
	cout << h << ':';
	if (m < 10)	cout << '0';
	cout << m;
}