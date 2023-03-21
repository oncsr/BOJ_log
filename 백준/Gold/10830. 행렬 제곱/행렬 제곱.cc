#include <iostream>
#include <vector>
using namespace std;

int N, mod = 1000;
vector<vector<int> > arr(5);
vector<vector<int> > I(5);

vector<vector<int> > P(long long b) {
	if (b == 0)	return I;
	if (b == 1)	return arr;
	vector<vector<int> > part = P(b / 2);
	vector<vector<int> > temp(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i].push_back(0);
			for (int k = 0; k < N; k++)
				temp[i][j] = (temp[i][j] + (part[i][k] * part[k][j])) % mod;
			temp[i][j] %= mod;
		}
	}
	if (b % 2) {
		part = temp;
		temp = vector<vector<int> >(N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				temp[i].push_back(0);
				for (int k = 0; k < N; k++)
					temp[i][j] = (temp[i][j] + part[i][k] * arr[k][j]) % mod;
				temp[i][j] %= mod;
			}
		}
	}
	return temp;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	long long B;
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)	I[i].push_back(1);
			else	I[i].push_back(0);
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			arr[i].push_back(a % mod);
		}

	vector<vector<int> > ans = P(B);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}