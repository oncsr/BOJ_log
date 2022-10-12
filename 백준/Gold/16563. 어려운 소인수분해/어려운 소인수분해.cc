#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, k, e[5000001]{};
	vector<int> P;
	for (int i = 2; i * i <= 5000000; i++) {
		if (!e[i])
			for (int j = i * 2; j <= 5000000; j += i)
				if (!e[j])	e[j] = i;
	}
	for (int i = 2; i <= 5000000; i++)
		if (!e[i])	P.push_back(i);
	for (cin >> N; N--;) {
		cin >> k;
		while (e[k]) {
			cout << e[k] << ' ';
			k /= e[k];
		}
		if (k != 1)	cout << k;
		cout << '\n';
	}
}