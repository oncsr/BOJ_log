#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
using dd = pair<double, double>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	dd arr[50000]{};
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i].first >> arr[i].second;
	double base = (arr[1].second - arr[0].second) / (arr[1].first - arr[0].first);
	for (int i = 2; i < N; i++) {
		base = max(base, (arr[i].second - arr[0].second) / (arr[i].first - arr[0].first));
	}
	double right = (arr[N - 2].second - arr[N - 1].second) / (arr[N - 1].first - arr[N - 2].first);
	for (int i = N - 3; i >= 0; i--) {
		right = max(right, (arr[i].second - arr[N - 1].second) / (arr[N - 1].first - arr[i].first));
	}
	cout.setf(ios::fixed);
	cout.precision(7);
	cout << atan(max(base, right)) * 360 / (2 * M_PI);
	cout.unsetf(ios::fixed);
}