#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

ll ans = 0;

int main() {

	cin.tie(0)->sync_with_stdio(0);

	//////////////////////////////////////////////////////

	int N;
	ll arr[200000]{};
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	ll K;
	cin >> K;
	
	for (int i = 0; i < N; i++) {
		if (K / arr[i] == 0)	continue;
		ll id = arr[i], G = 1;
		while (id <= K / arr[i]) {
			G = G * arr[i] + 1;
			id *= arr[i];
		}
		ans += G;
		id /= arr[i];
		ll temp = K / arr[i] - id;
		while (temp >= 1) {
			if (temp >= id) {
				ans += G * (temp / id);
				temp = (temp - temp / id * id);
			}
			G /= arr[i];
			id /= arr[i];
		}
	}
	cout << ans;
}

/*
* [shake! 2022]
*
* < 사용한 자료구조, 알고리즘 >
* math
*
* < 참고한 자료 >
* x
*
* < 출처 >
* x
*
*/