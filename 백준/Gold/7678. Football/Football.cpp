#include <iostream>
#include <vector>
using namespace std;

vector<vector<double> > P(129, vector<double>(9));
vector<vector<double> > arr(129, vector<double>(129));
int n, N;

void dp(int d) {
	if (d == 1) {
		for (int i = 1; i <= n; i++)	P[i][d] = 1;
		return;
	}
	dp(d - 1);
	int interval = 1 << (d - 1);
	int pos = 1;
	for (int i = 1; i <= n; i++) {
		if (pos + interval == i)	pos += interval;
		P[i][d] = P[i][d - 1];
		bool left = 0;
		if (i < pos + interval / 2)	left = 1;
		double D = 0;
		if (left) {
			for (int j = pos + interval / 2; j < pos + interval; j++) {
				D += P[j][d - 1] * arr[i][j];
			}
		}
		else {
			for (int j = pos; j < pos + interval / 2; j++) {
				D += P[j][d - 1] * arr[i][j];
			}
		}
		P[i][d] *= D;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	while (N != -1) {
		n = 1 << N;
		P = vector<vector<double> >(129, vector<double>(9));
		arr = vector<vector<double> >(129, vector<double>(129));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> arr[i][j];

		// P[i][j] : i번 팀이 j번째 라운드까지 올라올 확률
		dp(N + 1);
		double mx = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			if (P[i][N + 1] > mx) {
				mx = P[i][N + 1];
				ans = i;
			}
		}
		cout << ans << '\n';
		cin >> N;
	}
}