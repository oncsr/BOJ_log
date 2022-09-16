#include <iostream>
#include <vector>
#define min(a,b) (a<b?a:b)
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> d;
	for (int i = 0; i <= n; i++)
		d.push_back(0);
	for (int i = n; i >= 1; i--) {
		if (i % 3 == 0) {
			if (d[i / 3] == 0)
				d[i / 3] = d[i] + 1;
			else
				d[i / 3] = min(d[i / 3], d[i] + 1);
		}
		if (i % 2 == 0) {
			if (d[i / 2] == 0)
				d[i / 2] = d[i] + 1;
			else
				d[i / 2] = min(d[i / 2], d[i] + 1);
		}
		if (d[i - 1] == 0)
			d[i - 1] = d[i] + 1;
		else
			d[i - 1] = min(d[i - 1], d[i] + 1);
	}
	cout << d[1] << '\n';
}