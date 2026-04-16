#include <iostream>
using namespace std;


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;

	int s = 1, e = 1, sum = 1, ans = 0;
	while (e <= N) {
		if (sum == N) {
			ans++;
		}
		if (sum < N) {
			e++;
			sum += e;
		}
		else {
			sum -= s;
			s++;
		}
	}
	cout << ans;

}