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

int main() {
	int arr[5]{}, n;
	char a;
	for (cin >> n; n--;) {
		cin >> a;
		if (a == 'H')	arr[0]++;
		if (a == 'I')	arr[1]++;
		if (a == 'A')	arr[2]++;
		if (a == 'R')	arr[3]++;
		if (a == 'C')	arr[4]++;
	}
	cout << min({ arr[0],arr[1],arr[2],arr[3],arr[4] });
}