#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

int main() {

	ll W, H, A;
	cin >> W >> H >> A;
	vector<pl> arr;
	for (ll i = 1; i <= A; i++) {
		if (A % i == 0)	arr.push_back({ i,A / i });
	}

	ll WW = W, HH = H;

	vector<ll> cnt(arr.size(), 0);
	int id = arr.size() - 1;
	ll s = 0;
	while (id >= 0 && arr[id].first > WW)	cnt[id--] = -1;
	if (arr[id].first == WW)	cnt[id--] = 0;
	while (id >= 0) {
		while (WW > arr[id].first)	WW = (WW + 1) / 2, s++;
		while (id >= 0 && WW <= arr[id].first)	cnt[id--] = s;
	}
	
	id = 0, s = 0;
	while (id < arr.size() && arr[id].second > HH)	cnt[id++] = -1;
	if (arr[id].second == H)	id++;
	while (id < arr.size()) {
		while (HH > arr[id].second)	HH = (HH + 1) / 2, s++;
		while (id < arr.size() && HH <= arr[id].second) {
			if (cnt[id] != -1)
				cnt[id] += s;
			id++;
		}
	}

	ll mn1 = 1000000001;
	for (int i = 0; i < arr.size(); i++) {
		if (cnt[i] == -1)	continue;
		mn1 = min(mn1, cnt[i]);
	}
	if (mn1 == 1000000001)	cout << -1;
	else	cout << mn1;

}