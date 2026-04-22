#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	map<int, int> card;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		card[a]++;
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		cout << card[a] << ' ';
	}

}