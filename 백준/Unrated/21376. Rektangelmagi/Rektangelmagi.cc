#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
const ll INF = 9'223'372'036'854'775'807LL;
const string IMPOSSIBLE = "ej magisk";

ll R, C;
vector<vector<ll>> Origin;
vector<vector<pl>> ans;

ll gcd(ll a, ll b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

// 분수 통분
pl COMM(pl a) {
	if (a.second < 0)	a.first *= -1, a.second *= -1;
	if (a.first == 0)	return { 0,1 };
	ll g = gcd(abs(a.first), a.second);
	a.first /= g, a.second /= g;
	return a;
}

// 분수 연산
pl ADD(pl a, pl b) {
	pl res;
	res.first = a.first * b.second + b.first * a.second;
	res.second = a.second * b.second;
	return COMM(res);
}

pl SUB(pl a, pl b) {
	pl res;
	res.first = a.first * b.second - b.first * a.second;
	res.second = a.second * b.second;
	return COMM(res);
}

pl MUL(pl a, pl b) {
	pl res;
	res.first = a.first * b.first;
	res.second = a.second * b.second;
	return COMM(res);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> R >> C;

	Origin = vector<vector<ll>>(R, vector<ll>(C, INF));
	ans = vector<vector<pl>>(R, vector<pl>(C, { INF, 1 }));

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			string a;
			cin >> a;
			if (a == ".")	continue;
			Origin[i][j] = stoi(a);
			ans[i][j] = { stoi(a),1 };
		}
	}


	// 완성 가능한 행 채우기 1
	for (int i = 0; i < R; i++) {
		ll cnt = 0, J;
		pl V, A, D;
		for (int j = 0; j < C; j++) {
			if (ans[i][j] == make_pair(INF, 1LL))	continue;
			if (!cnt) {
				V = ans[i][j], J = j;
				cnt++;
				continue;
			}
			D = MUL(SUB(ans[i][j], V), {1,j - J});
			A = SUB(V, MUL({ J,1 }, D));
			cnt++;
			break;
		}
		if (cnt < 2)	continue;
		for (int j = 0; j < C; j++) {
			pl P = ADD(A, MUL({ j,1 }, D));
			if (ans[i][j] == make_pair(INF, 1LL))	ans[i][j] = P;
			else {
				if (ans[i][j] != P) {
					cout << IMPOSSIBLE;
					return 0;
				}
			}
		}
	}

	ll row = 0, col = 0;

	vector<pair<pl, pl>> row_ad(R);
	vector<pair<pl, pl>> col_ad(C);
	vector<ll> rows(R);
	vector<ll> cols(C);
	
	// 완성 가능한 열 채우기
	for (int j = 0; j < C; j++) {
		ll cnt = 0, I;
		pl V, A, D;
		for (int i = 0; i < R; i++) {
			if (ans[i][j] == make_pair(INF, 1LL))	continue;
			if (!cnt) {
				V = ans[i][j], I = i;
				cols[j] = 1;
				cnt++;
				continue;
			}
			D = MUL(SUB(ans[i][j], V), {1,i - I});
			A = SUB(V, MUL({ I,1 }, D));
			col_ad[j] = { A,D };
			cnt++;
			break;
		}
		if (cnt < 2)	continue;
		col++;
		for (int i = 0; i < R; i++) {
			pl P = ADD(A, MUL({ i,1 }, D));
			if (ans[i][j] == make_pair(INF, 1LL))	ans[i][j] = P;
			else {
				if (ans[i][j] != P) {
					cout << IMPOSSIBLE;
					return 0;
				}
			}
		}
		cols[j] = 2;
	}

	// 완성 가능한 행 채우기 2
	for (int i = 0; i < R; i++) {
		ll cnt = 0, J;
		pl V, A, D;
		for (int j = 0; j < C; j++) {
			if (ans[i][j] == make_pair(INF, 1LL))	continue;
			if (!cnt) {
				V = ans[i][j], J = j;
				cnt++;
				rows[i] = 1;
				continue;
			}
			D = MUL(SUB(ans[i][j], V), {1,j - J});
			A = SUB(V, MUL({ J,1 }, D));
			row_ad[i] = { A,D };
			cnt++;
			break;
		}
		if (cnt < 2)	continue;
		row++;
		for (int j = 0; j < C; j++) {
			pl P = ADD(A, MUL({ j,1 }, D));
			if (ans[i][j] == make_pair(INF, 1LL))	ans[i][j] = P;
			else {
				if (ans[i][j] != P) {
					cout << IMPOSSIBLE;
					return 0;
				}
			}
		}
		rows[i] = 2;
	}
	// 표가 완성된 경우

	if (R == row || C == col) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << ans[i][j].first;
				if (ans[i][j].second != 1)	cout << '/' << ans[i][j].second;
				cout << ' ';
			}
			cout << '\n';
		}
		return 0;
	}

	// 완성된 행,열이 (1,1)개인 경우
	int rr, cc;
	for (int i = 0; i < R; i++) {
		if (rows[i] == 2) { rr = i; break; }
	}
	for (int j = 0; j < C; j++) {
		if (cols[j] == 2) { cc = j; break; }
	}
	if (row == 1 && col == 1) {
		for (int i = 0; i < R; i++) {
			if (i == rr) {
				for (int j = 0; j < C; j++) {
					cout << ans[i][j].first;
					if (ans[i][j].second != 1)	cout << '/' << ans[i][j].second;
					cout << ' ';
				}
			}
			else {
				pl d = row_ad[rr].second;
				pl A = SUB(ans[i][cc], MUL({ cc,1 }, d));
				for (int j = 0; j < C; j++) {
					pl P = ADD(A, MUL({ j,1 }, d));
					cout << P.first;
					if (P.second != 1)	cout << '/' << P.second;
					cout << ' ';
				}
			}
			cout << '\n';
		}
		return 0;
	}
	
	// 행,열이 (1,0)인 경우
	if (row == 1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << ans[rr][j].first;
				if (ans[rr][j].second != 1)	cout << '/' << ans[rr][j].second;
				cout << ' ';
			}
			cout << '\n';
		}
		


		return 0;
	}

	// 행,열이 (0,1)인 경우
	if (col == 1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << ans[i][cc].first;
				if (ans[i][cc].second != 1)	cout << '/' << ans[i][cc].second;
				cout << ' ';
			}
			cout << '\n';
		}

		
		return 0;
	}

	ll cnt = 0;
	vector<pl> temp(R);
	vector<int> row_list;
	vector<int> col_list;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (ans[i][j] == make_pair(INF, 1LL))	continue;
			cnt++;
			temp[i] = { Origin[i][j], -j };
			row_list.push_back(i);
			col_list.push_back(j);
			break;
		}
	}

	if (cnt == 0) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++)	cout << "0 ";
			cout << '\n';
		}
		return 0;
	}
	if (cnt == 1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++)	cout << temp[row_list[0]].first << ' ';
			cout << '\n';
		}
		return 0;
	}

	// cnt = 2인 경우랑 2보다 큰 경우만 하자.
	if (cnt == 2) {
		ll A = temp[row_list[0]].first;
		ll B = temp[row_list[1]].first;
		pl D, AA;
		D.first = B - A, D.second = row_list[1] - row_list[0];
		if (D.first == 0) {
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++)	cout << temp[row_list[0]].first << ' ';
				cout << '\n';
			}
			return 0;
		}
		ll g = gcd(abs(B - A), D.second);
		D.first /= g, D.second /= g;
		AA = SUB({ A,1 }, MUL({ row_list[0], 1 }, D));
		for (int i = 0; i < R; i++) {
			pl P = ADD(AA, MUL({ i, 1 }, D));
			for (int j = 0; j < C; j++) {
				cout << P.first;
				if (P.second != 1)	cout << '/' << P.second;
				cout << ' ';
			}
			cout << '\n';
		}
		return 0;
	}
	
	// coef가 D의 계수
	vector<vector<pl>> con(R, vector<pl>(C, { INF, 1 }));
	vector<vector<pl>> coef(R, vector<pl>(C, { INF, 1 }));
	
	for (int j = 0; j < C; j++) {
		con[row_list[0]][j] = { temp[row_list[0]].first, 1 };
		coef[row_list[0]][j] = { col_list[0] - j, 1 };
	}

	con[row_list[1]][col_list[1]] = { temp[row_list[1]].first, 1 };
	coef[row_list[1]][col_list[1]] = { 0,1 };

	pl AAc, AAf, DDc, DDf;
	DDc = MUL(SUB(con[row_list[1]][col_list[1]], con[row_list[0]][col_list[1]]), { 1,row_list[1] - row_list[0] });
	DDf = MUL(SUB(coef[row_list[1]][col_list[1]], coef[row_list[0]][col_list[1]]), { 1,row_list[1] - row_list[0] });
	AAc = SUB(con[row_list[1]][col_list[1]], MUL({ row_list[1], 1 }, DDc));
	AAf = SUB(coef[row_list[1]][col_list[1]], MUL({ row_list[1], 1 }, DDf));
	for (int i = 0; i < R; i++) {
		pl Pc, Pf;
		Pc = ADD(AAc, MUL({ i,1 }, DDc));
		Pf = ADD(AAf, MUL({ i,1 }, DDf));
		con[i][col_list[1]] = Pc;
		coef[i][col_list[1]] = Pf;
	}

	con[row_list[2]][col_list[2]] = { temp[row_list[2]].first, 1 };
	coef[row_list[2]][col_list[2]] = { 0,1 };

	DDc = MUL(SUB(con[row_list[2]][col_list[2]], con[row_list[0]][col_list[2]]), { 1,row_list[2] - row_list[0] });
	DDf = MUL(SUB(coef[row_list[2]][col_list[2]], coef[row_list[0]][col_list[2]]), { 1,row_list[2] - row_list[0] });
	AAc = SUB(con[row_list[2]][col_list[2]], MUL({ row_list[2], 1 }, DDc));
	AAf = SUB(coef[row_list[2]][col_list[2]], MUL({ row_list[2], 1 }, DDf));
	for (int i = 0; i < R; i++) {
		pl Pc, Pf;
		Pc = ADD(AAc, MUL({ i,1 }, DDc));
		Pf = ADD(AAf, MUL({ i,1 }, DDf));
		con[i][col_list[2]] = Pc;
		coef[i][col_list[2]] = Pf;
	}

	DDc = MUL(SUB(con[row_list[1]][col_list[2]], con[row_list[1]][col_list[1]]), { 1,col_list[2] - col_list[1] });
	DDf = MUL(SUB(coef[row_list[1]][col_list[2]], coef[row_list[1]][col_list[1]]), { 1,col_list[2] - col_list[1] });
	AAc = SUB(con[row_list[1]][col_list[1]], MUL({ col_list[1], 1 }, DDc));
	AAf = SUB(coef[row_list[1]][col_list[1]], MUL({ col_list[1], 1 }, DDf));
	for (int j = 0; j < C; j++) {
		pl Pc, Pf;
		Pc = ADD(AAc, MUL({ j,1 }, DDc));
		Pf = ADD(AAf, MUL({ j,1 }, DDf));
		con[row_list[1]][j] = Pc;
		coef[row_list[1]][j] = Pf;
	}

	// D 구하기 (row_list[2] 행 채우기)
	
	DDc = MUL(SUB(con[row_list[2]][col_list[2]], con[row_list[2]][col_list[1]]), { 1,col_list[2] - col_list[1] });
	DDf = MUL(SUB(coef[row_list[2]][col_list[2]], coef[row_list[2]][col_list[1]]), { 1,col_list[2] - col_list[1] });
	AAc = SUB(con[row_list[1]][col_list[1]], MUL({ col_list[1], 1 }, DDc));
	AAf = SUB(coef[row_list[1]][col_list[1]], MUL({ col_list[1], 1 }, DDf));
	for (int j = 0; j < C; j++) {
		pl Pc, Pf;
		Pc = ADD(AAc, MUL({ j,1 }, DDc));
		Pf = ADD(AAf, MUL({ j,1 }, DDf));
		con[row_list[2]][j] = Pc;
		coef[row_list[2]][j] = Pf;
	}
	int K = 0;
	if (col_list[0] == 0 || col_list[1] == 0) {
		K = 1;
		if (col_list[0] == 1 || col_list[1] == 1)	K = 2;
	}
	pl Fc, Ff;
	Fc = con[row_list[2]][K];
	Ff = coef[row_list[2]][K];

	// D 구하기 (K 열 채우기)
	
	DDc = MUL(SUB(con[row_list[1]][K], con[row_list[0]][K]), { 1,row_list[1] - row_list[0] });
	DDf = MUL(SUB(coef[row_list[1]][K], coef[row_list[0]][K]), { 1,row_list[1] - row_list[0] });
	AAc = SUB(con[row_list[0]][K], MUL({ row_list[0], 1 }, DDc));
	AAf = SUB(coef[row_list[0]][K], MUL({ row_list[0], 1 }, DDf));
	
	pl Sc, Sf;
	Sc = ADD(AAc, MUL({ row_list[2], 1 }, DDc));
	Sf = ADD(AAf, MUL({ row_list[2], 1 }, DDf));
	
	pl child, par, D;
	child = SUB(Sc, Fc), par = SUB(Ff, Sf);
	if (par == make_pair(0LL, 1LL)) {
		if (child == make_pair(0LL, 1LL)) {
			// 여기도 이론 상 올 수가 있나? 머리 아파서 모르겠다.
			cout << "What's this case?\n";
			return 0;
		}
		else {
			cout << IMPOSSIBLE;
			return 0;
		}
	}
	else {
		D = MUL(child, { par.second,par.first });
	}

	for (int j = 0; j < C; j++) {
		pl P = ADD(con[row_list[0]][j], MUL(coef[row_list[0]][j], D));
		if (ans[row_list[0]][j] == make_pair(INF, 1LL))	ans[row_list[0]][j] = P;
		else {
			if (ans[row_list[0]][j] != P) {
				cout << IMPOSSIBLE;
				return 0;
			}
		}
	}

	// 이제 1행이 완성되고, 열 -> 행 순으로 다시 채울 차례,
	// 아까 코드 그대로 하면 됨.

	/*
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (ans[i][j] == make_pair(INF, 1LL)) {
				cout << ". ";
				continue;
			}
			cout << ans[i][j].first;
			if (ans[i][j].second != 1)	cout << '/' << ans[i][j].second;
			cout << ' ';
		}
		cout << '\n';
	}
	*/
	// 완성 가능한 열 채우기
	for (int j = 0; j < C; j++) {
		ll cnt = 0, I;
		pl V, A, D;
		for (int i = 0; i < R; i++) {
			if (ans[i][j] == make_pair(INF, 1LL))	continue;
			if (!cnt) {
				V = ans[i][j], I = i;
				cnt++;
				continue;
			}
			D = MUL(SUB(ans[i][j], V), { 1,i - I });
			A = SUB(V, MUL({ I,1 }, D));
			cnt++;
			break;
		}
		if (cnt < 2)	continue;
		col++;
		for (int i = 0; i < R; i++) {
			pl P = ADD(A, MUL({ i,1 }, D));
			if (ans[i][j] == make_pair(INF, 1LL))	ans[i][j] = P;
			else {
				if (ans[i][j] != P) {
					cout << IMPOSSIBLE;
					return 0;
				}
			}
		}
	}

	// 완성 가능한 행 채우기 2
	for (int i = 0; i < R; i++) {
		ll cnt = 0, J;
		pl V, A, D;
		for (int j = 0; j < C; j++) {
			if (ans[i][j] == make_pair(INF, 1LL))	continue;
			if (!cnt) {
				V = ans[i][j], J = j;
				cnt++;
				continue;
			}
			D = MUL(SUB(ans[i][j], V), { 1,j - J });
			A = SUB(V, MUL({ J,1 }, D));
			cnt++;
			break;
		}
		if (cnt < 2)	continue;
		for (int j = 0; j < C; j++) {
			pl P = ADD(A, MUL({ j,1 }, D));
			if (ans[i][j] == make_pair(INF, 1LL))	ans[i][j] = P;
			else {
				if (ans[i][j] != P) {
					cout << IMPOSSIBLE;
					return 0;
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << ans[i][j].first;
			if (ans[i][j].second != 1)	cout << '/' << ans[i][j].second;
			cout << ' ';
		}
		cout << '\n';
	}

}