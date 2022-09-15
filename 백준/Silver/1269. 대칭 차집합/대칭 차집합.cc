#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	map<int, int> A;
	map<int, int> B;
	set<int> G;
	int n, m, a, s = 0;
	cin >> n >> m;
	while (n--) {
		cin >> a;
		A[a] = 1;
		G.insert(a);
	}
	while (m--) {
		cin >> a;
		B[a] = 1;
		G.insert(a);
	}
	s = G.size();
	for (auto& i : G)
		if (A[i] && B[i])	s--;
	cout << s;
}