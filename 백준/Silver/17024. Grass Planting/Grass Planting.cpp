#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	int V[100001]{}, mx = 0;
	for (int i = 1; i < n; i++) {
		mx = 2;
		int a, b;
		cin >> a >> b;
		V[a]++, V[b]++;
	}
	for (int i = 1; i <= n; i++)
		mx = max(mx, V[i]);
	cout << mx + 1;
}