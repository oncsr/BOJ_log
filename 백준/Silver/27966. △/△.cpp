#include <iostream>
using namespace std;
using ll = long long;

int main() {
	ll N;
	cin >> N;
	cout << (N - 1) * (N - 1) << '\n';
	for (int i = 2; i <= N; i++)	cout << "1 " << i << '\n';
}