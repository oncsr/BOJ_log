#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, x, y, s = 4;
	cin >> N >> x >> y;
	if (x == 1 || x == N)	s--;
	if (y == 1 || y == N)	s--;
	if (N == 1)	s = 0;
	if (N == 2)	s = 2;
	cout << s;
}