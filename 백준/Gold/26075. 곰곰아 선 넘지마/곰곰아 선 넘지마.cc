#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	string a, b;
	cin >> N >> M >> a >> b;
	long long one[100000]{}, id = 0, sz = a.size(), s = 0;
	for (int i = 0; i < sz; i++) {
		if (a[i] == '1')	one[id++] = i;
	}
	id = 0;
	for (int i = 0; i < sz; i++) {
		if (b[i] == '1')
			s += abs(one[id++] - i);
	}
	long long g = s / 2, h = s - g;
	cout << g * g + h * h;
}