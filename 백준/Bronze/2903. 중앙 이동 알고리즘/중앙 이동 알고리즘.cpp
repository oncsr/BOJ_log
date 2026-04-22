#include <iostream>
using namespace std;
using ll = long long;

ll N;

int main() {
	cin >> N;
	ll s = 2;
	for (ll i = 1; i <= N; i++)	s = s * 2 - 1;
	cout << s * s;
}