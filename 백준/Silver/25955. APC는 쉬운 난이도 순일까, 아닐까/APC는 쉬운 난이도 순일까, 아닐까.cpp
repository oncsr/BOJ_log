#include <iostream>
#include <algorithm>
using namespace std;

/*
* 2022.11.13
* [used algorithm]
* =>
* [point]
* =>
*/

int arr1[1000]{}, N, b, arr2[1000]{};
void print(int x) {
	int tier = arr1[x] / 1000;
	int lev = arr1[x] % 1000;
	lev = 1000 - lev;
	if (tier == 4)	cout << 'D';
	else if (tier == 3)	cout << 'P';
	else if (tier == 2)	cout << 'G';
	else if (tier == 1)	cout << 'S';
	else cout << 'B';
	cout << lev << ' ';
}

int main() {
	cin >> N;
	char a;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		b = 1000 - b;
		if (a == 'D')	b += 4000;
		else if (a == 'P')	b += 3000;
		else if (a == 'G')	b += 2000;
		else if (a == 'S')	b += 1000;
		arr1[i] = b;
		arr2[i] = b;
	}
	sort(arr1, arr1 + N);
	int x = -1, y = -1;
	for (int i = 0; i < N; i++) {
		if (arr1[i] != arr2[i]) {
			if (x == -1)	x = i;
			else	y = i;
		}
	}
	if (x == -1)	cout << "OK";
	else {
		cout << "KO\n";
		print(x);	print(y);
	}
}