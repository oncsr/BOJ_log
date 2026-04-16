#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, A[1002][1002]{};
	cin >> N;
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)cin >> A[i][j];

	int L[1002][1002]{};
	int R[1002][1002]{};
	int U[1002][1002]{};
	int D[1002][1002]{};
	int Q[1002][1002]{};
	int E[1002][1002]{};
	int Z[1002][1002]{};
	int C[1002][1002]{};
    int ans = 1;
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++) {
		L[i][j] = A[i][j] == 1 ? L[i][j - 1] + 1 : 0;
		U[i][j] = A[i][j] == 1 ? U[i - 1][j] + 1 : 0;
		Q[i][j] = A[i][j] == 1 ? Q[i - 1][j - 1] + 1 : 0;
        ans = max({ ans,L[i][j],U[i][j],Q[i][j] });
	}
	for (int i = N; i >= 1; i--)for (int j = N; j >= 1; j--) {
		R[i][j] = A[i][j] == 1 ? R[i][j + 1] + 1 : 0;
		D[i][j] = A[i][j] == 1 ? D[i + 1][j] + 1 : 0;
		C[i][j] = A[i][j] == 1 ? C[i + 1][j + 1] + 1 : 0;
        ans = max({ ans,R[i][j],D[i][j],C[i][j] });
	}
	for (int i = 1; i <= N; i++)for (int j = N; j >= 1; j--) {
		E[i][j] = A[i][j] == 1 ? E[i - 1][j + 1] + 1 : 0;
        ans = max(ans, E[i][j]);
	}
	for (int i = N; i >= 1; i--)for (int j = 1; j <= N; j++) {
		Z[i][j] = A[i][j] == 1 ? Z[i + 1][j - 1] + 1 : 0;
        ans = max(ans, Z[i][j]);
	}
	for (int i = 1; i <= N; i++)for (int j = 1; j <= N; j++)if (A[i][j] == 2) {
		int hor = L[i][j - 1] + R[i][j + 1] + 1;
		int ver = U[i - 1][j] + D[i + 1][j] + 1;
		int dia = max(Q[i - 1][j - 1] + C[i + 1][j + 1], E[i - 1][j + 1] + Z[i + 1][j - 1]) + 1;
		ans = max({ ans,hor,ver,dia });
	}
	cout << ans;
	
}