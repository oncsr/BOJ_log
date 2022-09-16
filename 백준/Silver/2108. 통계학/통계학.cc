#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int arr[500001];
	int sum = 0;
	int arr2[8001] = { 0 };
	int mx = 0;
	int maxx = -4000, minn = 4000;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		arr2[arr[i] + 4000]++;
		mx = max(mx, arr2[arr[i] + 4000]);
		maxx = max(arr[i], maxx);
		minn = min(arr[i], minn);
	}
	sort(arr, arr + N);
	int g = round((double)sum / (double)N);
	if (g == -0)
		cout << "0\n";
	else
		cout << g << '\n';
	cout << arr[N / 2] << '\n';
	int find = 0, val = 0;
	for (int i = 0; i <= 8000; i++) {
		if (mx == arr2[i]) {
			val = i - 4000;
			find++;
		}
		if (find == 2)
			break;
	}
	cout << val << '\n';
	cout << maxx - minn << '\n';
}