#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[250001]{}, a, Q, mn[250001]{};
	cin >> N;
	for (int i = 1; i <= N; i++)	cin >> arr[i];
	for (int i = 1; i <= N; i++) {
		cin >> a;
		arr[i] -= a;
		if (i == 1)	mn[i] = arr[i];
		else	mn[i] = min(arr[i], mn[i - 1]);
	}
	for (cin >> Q; Q--;) {
		cin >> a;
		int s = 1, e = N, m = (s + e) / 2;
		while (s < e) {
			if (mn[m] >= a)	s = m + 1;
			else	e = m;
			m = (s + e) / 2;
		}
		if (mn[m] < a)	m--;
		cout << m << '\n';
	}
}