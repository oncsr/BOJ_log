#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	ll arr[1000000]{};
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	sort(arr, arr + N);
	ll T[1000000]{};
	for (int i = 0; i < N / 2; i++) {
		T[i * 2] = arr[i];
		T[i * 2 + 1] = arr[N - 1 - i];
	}
	if (N % 2)	T[N - 1] = arr[N / 2];
	ll s = 0;
	for (int i = 0; i < N - 1; i++)	s += abs(T[i] - T[i + 1]);
	ll mx = s;
	for (int i = 0; i < N - 1; i++) {
		s -= abs(T[i] - T[i + 1]);
		if (i == 0)	s += abs(T[i] - T[N - 1]);
		else	s += abs(T[i] - T[i - 1]);
		mx = max(mx, s);
	}
	for (int i = 0; i < N / 2; i++) {
		T[i * 2] = arr[N - 1 - i];
		T[i * 2 + 1] = arr[i];
	}
	if (N % 2)	T[N - 1] = arr[N / 2];
	s = 0;
	for (int i = 0; i < N - 1; i++)	s += abs(T[i] - T[i + 1]);
	for (int i = 0; i < N - 1; i++) {
		s -= abs(T[i] - T[i + 1]);
		if (i == 0)	s += abs(T[i] - T[N - 1]);
		else	s += abs(T[i] - T[i - 1]);
		mx = max(mx, s);
	}
	cout << mx;
}