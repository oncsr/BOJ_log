#include <iostream>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll N, s = 0, a, temp;
	cin >> N >> temp;
	for (int i = 1; i < N; i++) {
		cin >> a;
		s += max(a, temp);
		temp = a;
	}
	cout << s;
}