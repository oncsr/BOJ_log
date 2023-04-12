#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using dd = pair<double, double>;

int ccw(dd a, dd b, dd c) {
	return (b.first - a.first) * (c.second - a.second) - (c.first - a.first) * (b.second - a.second);
}

double integral(dd a, dd b) {
	double t = (b.second - a.second) / (b.first - a.first);
	double F = -t * a.first + a.second;
	double high = t * t * b.first * b.first * b.first / 3;
	high += t * F * b.first * b.first;
	high += F * F * b.first;
	double low = t * t * a.first * a.first * a.first / 3;
	low += t * F * a.first * a.first;
	low += F * F * a.first;
	return M_PI * (high - low);
}

void solve(dd a, dd b, dd c) {
	double S1 = 0, S2 = 0, S3 = 0;
	if (a.first != b.first)	S1 = integral(a, b);
	if (b.first != c.first)	S2 = integral(b, c);
	if (c.first != a.first)	S3 = integral(a, c);

	cout.setf(ios::fixed);
	cout.precision(10);
	if (ccw(a, b, c) > 0)	cout << S3 - (S1 + S2) << ' ';
	else	cout << S1 + S2 - S3 << ' ';
	cout.unsetf(ios::fixed);
}

int main() {
	dd arr[3]{};
	for (int i = 0; i < 3; i++)	cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + 3);
	solve(arr[0], arr[1], arr[2]);
	swap(arr[0].first, arr[0].second);
	swap(arr[1].first, arr[1].second);
	swap(arr[2].first, arr[2].second);
	sort(arr, arr + 3);
	solve(arr[0], arr[1], arr[2]);
	
}