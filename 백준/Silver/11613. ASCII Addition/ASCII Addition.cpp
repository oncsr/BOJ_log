#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

string arr[7]{};

vector<vector<string> > number(10);
vector<string> pls;

void number_init() {
	number[0] = { "xxxxx","x...x","x...x","x...x","x...x","x...x","xxxxx" };
	number[1] = { "....x","....x","....x","....x","....x","....x","....x" };
	number[2] = { "xxxxx","....x","....x","xxxxx","x....","x....","xxxxx" };
	number[3] = { "xxxxx","....x","....x","xxxxx","....x","....x","xxxxx" };
	number[4] = { "x...x","x...x","x...x","xxxxx","....x","....x","....x" };
	number[5] = { "xxxxx","x....","x....","xxxxx","....x","....x","xxxxx" };
	number[6] = { "xxxxx","x....","x....","xxxxx","x...x","x...x","xxxxx" };
	number[7] = { "xxxxx","....x","....x","....x","....x","....x","....x" };
	number[8] = { "xxxxx","x...x","x...x","xxxxx","x...x","x...x","xxxxx" };
	number[9] = { "xxxxx","x...x","x...x","xxxxx","....x","....x","xxxxx" };
	pls = { ".....","..x..","..x..","xxxxx","..x..","..x..","....." };
}

int main() {
	number_init();
	for (int i = 0; i < 7; i++)	cin >> arr[i];
	int a = 0, b = 0, c = 0;
	int ga = 1, gb = 1;
	vector<int> A, B;
	for (int i = 0; i < arr[0].size(); i += 6) {
		vector<string> temp;
		for (int j = 0; j < 7; j++) {
			temp.push_back(arr[j].substr(i, 5));
		}
		if (temp == pls) {
			for (int j = A.size() - 1; j >= 0; j--) {
				a += ga * A[j];
				ga *= 10;
			}
			c++;
			
		}
		else {
			int j = 0;
			for (; j < 10; j++) {
				if (temp == number[j])	break;
			}
			if (c)	B.push_back(j);
			else	A.push_back(j);
		}
	}
	for (int j = B.size() - 1; j >= 0; j--) {
		b += gb * B[j];
		gb *= 10;
	}
	int s = a + b, g = log10(s), p = pow(10, g);
	vector<vector<string> > ans(7);
	while (s) {
		int temp = s / p;
		s -= s / p * p;
		p /= 10;
		for (int j = 0; j < 7; j++) {
			ans[j].push_back(number[temp][j]);
			ans[j].push_back(".");
		}
	}
	while (p) {
		for (int j = 0; j < 7; j++) {
			ans[j].push_back(number[0][j]);
			ans[j].push_back(".");
		}
		p /= 10;
	}

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < ans[i].size() - 1; j++)	cout << ans[i][j];
		cout << '\n';
	}
}