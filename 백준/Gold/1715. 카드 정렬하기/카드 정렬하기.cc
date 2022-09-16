#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<> > Q;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		Q.push(a);
	}
	ll sum = 0, ans = 0;
	while (!Q.empty()) {
		int a = Q.top();
		Q.pop();
		int b = 0;
		if (!Q.empty()) {
			b = Q.top();
			Q.pop();
		}
		sum = ((ll)a + (ll)b);
		ans += sum;
		if (Q.empty())
			break;
		else
			Q.push(sum);
	}
	if (n == 1)
		cout << "0\n";
	else
		cout << ans << '\n';
}