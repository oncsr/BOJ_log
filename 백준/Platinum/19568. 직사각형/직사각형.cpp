#include <bits/stdc++.h>
using namespace std;

int arr[30][30]{};

void print() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++)	cout << arr[i][j] << ' ';
		cout << '\n';
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	for (int j = 0; j < 14; j++)	arr[14][j] = 1;
	for (int j = 15; j < 30; j++)	arr[14][j] = 15;
	for (int i = 0; i < 14; i++)	arr[i][14] = 240;
	for (int i = 15; i < 30; i++)	arr[i][14] = 3600;
	print();

}