#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
using dd = pair<double, double>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	double a, b, c, d;
	dd arr[100000]{};
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		double d1 = b / a, d2 = d / c;
		if (d1 > d2)	swap(d1, d2);
		arr[i] = { d1,d2 };
	}
	sort(arr, arr + N);
	int mx = 1;
	priority_queue<double, vector<double>, greater<> > Q;
	Q.push(arr[0].second);
	for (int i = 1; i < N; i++) {
		dd now = arr[i];
		if (now.first > Q.top()) {
			while (!Q.empty() && now.first > Q.top())
				Q.pop();
		}
		Q.push(now.second);
		mx = max(mx, (int)Q.size());
	}
	cout << mx;
}