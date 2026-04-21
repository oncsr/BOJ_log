#include <iostream>
#include <queue>
using namespace std;
#define x first
#define y second


double area(vector<pair<double, double>> V) {
	double ans = 0;
	int N = V.size();
	for (int i = 0; i < N; i++)
		ans += (V[i].x * (V[(i + 1) % N].y - V[(i + N - 1) % N].y));
	return abs(ans);
}


int main() {
	long long N;
	cin >> N;
	vector<pair<double, double>> arr(N);
	for (int i = 0; i < N; i++)	cin >> arr[i].x >> arr[i].y;

	cout.setf(ios::fixed);
	cout.precision(1);
	cout << area(arr) / 2;
}