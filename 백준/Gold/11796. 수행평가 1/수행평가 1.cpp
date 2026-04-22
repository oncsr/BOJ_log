#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	int arr[100000]{};
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	if (M == 1) {
		cout << N + 1 << ' ' << 1;
		return 0;
	}
	int p = 1;
	long long G = 1;
	vector<vector<int> > V(100001);
	while (p < N) {
		G *= (long long)M;
		set<vector<int> > S;
		for (int i = p-1; i < N; i++) {
			V[i - p + 1].push_back(arr[i]);
			S.insert(V[i - p + 1]);
		}
		if (G > N) {
			cout << p << ' ' << (G - S.size()) % mod;
			return 0;
		}
		if (S.size() != G) {
			cout << p << ' ' << (G - S.size()) % mod;
			return 0;
		}
		p++;
	}

}