#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int gr[7][2]{};
	for (int i = 0; i < N; i++) {
		int S, Y;
		cin >> S >> Y;
		gr[Y][S]++;
	}
	int room = 0;
	for (int i = 1; i <= 6; i++) {
		if (gr[i][0])	room += (gr[i][0] - 1) / K + 1;
		if (gr[i][1])	room += (gr[i][1] - 1) / K + 1;
	}
	cout << room;
}