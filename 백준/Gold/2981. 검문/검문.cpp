#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	return a % b ? gcd(b, a%b) : b;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);


	int N, A[100];
	cin >> N >> A[0] >> A[1];
	int g = abs(A[1] - A[0]);
	for (int i = 2; i < N; i++) {
		cin >> A[i];
		g = gcd(g, abs(A[i] - A[i - 1]));
	}
	vector<int> ans;
	for (int j = 2; j*j <= g; j++) {
		if (g%j) continue;
		ans.push_back(j);
		if (j != g / j && g / j != 1) ans.push_back(g / j);
	}
	ans.push_back(g);
	sort(ans.begin(), ans.end());
	for (int i : ans) cout << i << ' ';
	

}