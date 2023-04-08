#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int rows[3001][3001]{}, cols[3001][3001]{}, N, L, U, D, R;
	cin >> N;
	L = U = N / 2;
	D = R = N / 2 + 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a;
			cin >> a;
			rows[i][j] = rows[i][j - 1] + a;
			cols[i][j] = cols[i - 1][j] + a;
		}
	}
	string ans = "";
	int s = 0;
	int LL = cols[D][L - 1] - cols[U - 1][L - 1];
	int RR = cols[D][R + 1] - cols[U - 1][R + 1];
	int UU = rows[U - 1][R] - rows[U - 1][L - 1];
	int DD = rows[D + 1][R] - rows[D + 1][L - 1];
	while (LL > 0 || RR > 0 || UU > 0 || DD > 0) {
		if (UU > 0 && UU >= LL && UU >= RR && UU >= DD) {
			s += UU;
			ans += 'U';
			U--;
			if (U == 1)	UU = -1;
			else {
				UU = rows[U - 1][R] - rows[U - 1][L - 1];
				
			}
			if (L > 1)
				LL += (cols[U][L - 1] - cols[U - 1][L - 1]);
			if (R < N)
				RR += (cols[U][R + 1] - cols[U - 1][R + 1]);
		}
		else if (DD > 0 && DD >= UU && DD >= RR && DD >= LL) {
			s += DD;
			ans += 'D';
			D++;
			if (D == N)	DD = -1;
			else {
				DD = rows[D + 1][R] - rows[D + 1][L - 1];
				
			}
			if (L > 1)
				LL += (cols[D][L - 1] - cols[D - 1][L - 1]);
			if (R < N)
				RR += (cols[D][R + 1] - cols[D - 1][R + 1]);
		}
		else if (LL > 0 && LL >= DD && LL >= UU && LL >= RR) {
			s += LL;
			ans += 'L';
			L--;
			if (L == 1)	LL = -1;
			else {
				LL = cols[D][L - 1] - cols[U - 1][L - 1];
				
			}
			if (U > 1)
				UU += (rows[U - 1][L] - rows[U - 1][L - 1]);
			if (D < N)
				DD += (rows[D + 1][L] - rows[D + 1][L - 1]);
		}
		else {
			s += RR;
			ans += 'R';
			R++;
			if (R == N)	RR = -1;
			else {
				RR = cols[D][R + 1] - cols[U - 1][R + 1];
				
			}
			if (U > 1)
				UU += (rows[U - 1][R] - rows[U - 1][R - 1]);
			if (D < N)
				DD += (rows[D + 1][R] - rows[D + 1][R - 1]);
		}
	}
	cout << s << '\n' << ans;
}