#include <iostream>
using namespace std;

int main() {
	long long N;
	cin >> N;
	long long g = 0;
	int cnt = 0;
	while (g < N) {
		if (g == 0)	g++;
		else	g *= 2;
		cnt++;
	}
	cout << cnt;
}