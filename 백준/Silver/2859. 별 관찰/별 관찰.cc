#include <iostream>
#include <cassert>
#include <map>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	int a[4]{}, b[4]{};
	char c;
	for (int i = 0; i < 4; i++)	cin >> a[i] >> c >> b[i];
	ll aa = a[0] * 60 + b[0], bb = a[1] * 60 + b[1];
	ll da = a[2] * 60 + b[2], db = a[3] * 60 + b[3];
	ll limit = aa + bb + da * db;
	map<ll, ll> M;
	bool find = false;
	for (ll i = aa; i <= limit; i += da)	M[i]++;
	for (ll i = bb; i <= limit; i += db) {
		if (M[i]) {
			aa = i;
			find = true;
			break;
		}
	}
	if (!find)	cout << "Never";
	else {
		ll day = (aa / 1440) % 7;
		ll time = aa % 1440;
		ll hour = time / 60, minute = time % 60;
		if (day == 0)	cout << "Saturday";
		if (day == 1)	cout << "Sunday";
		if (day == 2)	cout << "Monday";
		if (day == 3)	cout << "Tuesday";
		if (day == 4)	cout << "Wednesday";
		if (day == 5)	cout << "Thursday";
		if (day == 6)	cout << "Friday";
		cout << '\n';
		if (hour < 10)	cout << '0';
		cout << hour << ':';
		if (minute < 10)	cout << '0';
		cout << minute;
	}
}