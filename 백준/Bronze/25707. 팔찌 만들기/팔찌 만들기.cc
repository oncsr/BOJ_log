#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, a[1000]{};
	cin >> N;
	for (int i = 0; i < N; i++)	cin >> a[i];
	sort(a, a + N);
	long long s = abs(a[N - 1] - a[0]);
	for (int i = 0; i < N - 1; i++)	s += abs(a[i] - a[i + 1]);
	cout << s;
}