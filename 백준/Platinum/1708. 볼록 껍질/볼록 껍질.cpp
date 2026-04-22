#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
#define x first
#define y second

vector<ii> arr;

ll ccw(ii a, ii b, ii c) {
	ii vec1 = { b.x - a.x,b.y - a.y };
	ii vec2 = { c.x - b.x,c.y - b.y };

	return (ll)vec1.x * vec2.y - (ll)vec1.y * vec2.x;
}

bool cmp(ii a, ii b) { return ccw(arr[0], a, b) > 0; }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	arr = vector<ii>(n);
	for (int i = 0; i < n; i++)	cin >> arr[i].x >> arr[i].y;

	sort(arr.begin(), arr.end());

	sort(arr.begin() + 1, arr.end(), cmp);

	stack<ii> CH;
	arr.push_back(arr[0]);
	CH.push(arr[0]);
	CH.push(arr[1]);
	for (int i = 2; i < arr.size(); i++) {
		ii next = arr[i];
		ii fir = CH.top();
		CH.pop();
		ii sec = CH.top();
		
		ll value = ccw(sec, fir, next);
		if (value > 0) {
			CH.push(fir);
			CH.push(next);
		}
		else {
			while (CH.size() > 2 && value <= 0) {
				fir = CH.top();
				CH.pop();
				sec = CH.top();
				value = ccw(sec, fir, next);
			}
			if (value > 0) {
				CH.push(fir);
			}
			CH.push(next);
		}
	}
	cout << CH.size() - 1;
}