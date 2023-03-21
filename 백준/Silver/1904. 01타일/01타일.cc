#include <iostream>
using namespace std;

int main() {
	int N, d[1000001] = { 0,1,2 };
	cin >> N;
	for (int i = 3; i <= N; i++)
		d[i] = (d[i - 1] + d[i - 2]) % 15746;
	cout << d[N];
}