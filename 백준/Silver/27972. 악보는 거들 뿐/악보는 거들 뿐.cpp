#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, temp = 0, mx = 0, cnt1 = 0, cnt2 = 0, a;
	for (cin >> N; N--;) {
		cin >> a;
		if (a > temp)	cnt2++, mx = max(mx, cnt1), cnt1 = 1;
		else if (a < temp)	cnt1++, mx = max(mx, cnt2), cnt2 = 1;
		temp = a;
	}
	mx = max(mx, max(cnt1, cnt2));
	cout << mx;
}