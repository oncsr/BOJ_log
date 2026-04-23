#include <iostream>
using namespace std;

int main() {
	int N, M, arr[101]{};
	cin >> N >> M;
	for (int i = 1; i <= N; i++)	arr[i] = i;
	for (; M--;) {
		int a, b, c;
		cin >> a >> b >> c;
		int temp[100]{}, id = 0;
		for (int i = c; i <= b; i++)	temp[id++] = arr[i];
		for (int i = a; i < c; i++)	temp[id++] = arr[i];
		id = 0;
		for (int i = a; i <= b; i++)	arr[i] = temp[id++];
	}
	for (int i = 1; i <= N; i++)	cout << arr[i] << ' ';
}