#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> V;
vector<int> ans;

vector<int> divide(int s, int e) {
	if (s == e) {
		vector<int> G;
		if (V[s] == M) {
			ans.push_back(V[s]);
			G.push_back(1);
		}
		return G;
	}
	int m = (s + e) / 2;
	vector<int> T1 = divide(s, m);
	vector<int> T2 = divide(m + 1, e);
	// left find
	if (T2.empty()) {
		int sz = T1.size();
		for (int i = 0; i < sz; i++) {
			ans.push_back(V[m + T1[i]]);
			T1.push_back(T1[i] + m + 1 - s);
		}
	}
	else {
		int sz = T2.size();
		for (int i = 0; i < sz; i++) {
			ans.push_back(V[s - 1 + T2[i]]);
			T1.push_back(T2[i] + m + 1 - s);
		}
		for (int i : T2)	T1.push_back(i);
	}
	return T1;
}

int main() {
	cin >> N >> M;
	V.push_back(0);
	for (int i = 1; i <= N / 2; i++) {
		V.push_back(i);
		V.push_back(N + 1 - i);
	}
	divide(1, N);
	for (int i : ans)	cout << i << ' ';
}