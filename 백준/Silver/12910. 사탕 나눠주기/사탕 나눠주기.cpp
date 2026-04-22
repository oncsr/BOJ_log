#include <iostream>
using namespace std;

int main() {
	int N, d[51]{};
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		d[a]++;
	}
	int ans = 0, dd = 1;
	for (int i = 1; i <= N; i++) {
		if (!d[i])	break;
		dd *= d[i];
		ans += dd;
	}
	cout << ans;
}