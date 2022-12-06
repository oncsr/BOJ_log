#include <iostream>
using namespace std;

int main() {
	int N, a[101]{}, b, mx = 0, s = 0, c = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> b;
		if(b)	a[b]++;
		if (a[b] > mx)	mx = a[b], s = 1, c = b;
		else if (a[b] == mx)	s++;
	}
	if (s == 1)	cout << c;
	else	cout << "skipped";
}