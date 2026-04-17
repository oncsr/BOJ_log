#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define x first
#define y second

ld area(vector<pair<ld, ld>> V) {
	ld ans = 0;
	int N = V.size();
	for (int i = 0; i < N; i++)
		ans += (V[i].x * (V[(i + 1) % N].y - V[(i + N - 1) % N].y));
	return abs(ans) / 2;
}


int main() {
	int N;
	cin >> N;
	vector<pair<ld, ld>> arr(4);
	for (int i = 0; i < 4; i++)	cin >> arr[i].x >> arr[i].y;

	cout.precision(10);
	cout << fixed << area(arr) / N;
}