#include <iostream>
using namespace std;
typedef long long ll;

int main() {
	int N;
	cin >> N;
	ll arr[51];
	int num[51] = { 0 };
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (i == 0 || i == N - 1)
			num[i] = 1;
		else
			num[i] = 2;
	}
	double d = 0;
	int mx = 0;
	for (int i = 0; i < N - 1; i++) {
		d = arr[i + 1] - arr[i];
		for (int j = i + 2; j < N; j++) {
			if (arr[j] > d * (double)(j - i) + (double)arr[i]) {
				num[j]++;
				num[i]++;
				d = (double)(arr[j] - arr[i]) / (double)(j - i);
			}
		}
	}
	for (int i = 0; i < 50; i++)
		mx = max(mx, num[i]);
	if (N == 1)
		cout << "0\n";
	else
		cout << mx << '\n';
}