#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, arr[1000001]{}, a, b, c, s = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		if (!arr[a] && !arr[b] && !arr[c]) {
			s++;
			arr[a]++, arr[b]++, arr[c]++;
		}
		else {
			if (!arr[a])	arr[a]++;
			if (!arr[b])	arr[b]++;
			if (!arr[c])	arr[c]++;
		}
	}
	cout << s;
}