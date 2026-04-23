#include<iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, b;
	cin >> n >> m;
	int a[200001]{};
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + m; j++) {
			cin >> b;
			a[j] += b;
			a[i] -= b;
		}
	}
	for (int i = 0; i < n + m; i++)	cout << a[i] << ' ';
}