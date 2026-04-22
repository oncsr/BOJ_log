#include <iostream>
using namespace std;

int main() {
	int e[1000001]{}, N;
	long long s = 0;
	cin >> N;
	for (int i = 2; i <= N; i++)
		if (!e[i])
			for (int j = i * 2; j <= N; j += i)
				if (!e[j])	e[j] = i;
	for (int i = 2; i <= N; i++)	s += (e[i] ? e[i] : i);
	cout << s;
}