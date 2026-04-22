#include <iostream>
using namespace std;
using ll = long long;

int main() {
	int n, e[1000001]{}, v[1000001]{};
	for (int i = 2; i * i <= 1000000; i++)
		if (!e[i])
			for (int j = i * 2; j <= 1000000; j += i)
				e[j] = 1;
	ll s = 1, a;
	for (cin >> n; n--;) {
		cin >> a;
		if (!e[a] && !v[a])	s *= a, v[a]++;
	}
	cout << (s > 1 ? s : -1);
}