#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	int e[5000001]{};
	vector<int> sosu;
	int i = 2;
	for (; i * i <= N; i++) {
		if (!e[i]) {
			sosu.push_back(i);
			for (int j = i * 2; j <= N; j += i)	e[j]++;
		}
	}
	for (; i <= N; i++)
		if (!e[i])	sosu.push_back(i);
	int limit = 21, a = 0, b = sosu.size() - 1;
	int m = (a + b) / 2;
	int p;
	while (limit--) {
		if (a == b) {
			cout << "! " << sosu[a] << endl;
			break;
		}
		cout << "? " << sosu[m] << endl;
		cin >> p;
		if (p)	a = m + 1;
		else	b = m;
		m = (a + b) / 2;
	}
}