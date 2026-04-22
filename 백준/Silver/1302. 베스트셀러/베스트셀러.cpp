#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	map<string, int> M;
	int N, mx = 0;
	cin >> N;
	string ans = "";
	for (int i = 0; i < N; i++) {
		string a;
		cin >> a;
		M[a]++;
		if (M[a] > mx || (M[a] == mx && a < ans)) {
			ans = a;
			mx = M[a];
		}
	}
	cout << ans;
}