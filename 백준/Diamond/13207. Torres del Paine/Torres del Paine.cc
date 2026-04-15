#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using ii = pair<ll, ll>;
using dd = pair<ld, ld>;
const ld INF = 2000000001.;
#define x first
#define y second

// 13207

ld ccw(dd a, dd b, dd c) {
	dd vec1 = { b.x - a.x,b.y - a.y };
	dd vec2 = { c.x - b.x,c.y - b.y };
	return vec1.x * vec2.y - vec1.y * vec2.x;
}

ld area(vector<dd> arr) {
	ld S = 0.;
	int N = arr.size();
	for (int i = 0; i < N; i++) {
		if (i == 0)	S += (arr[i].x * (arr[i + 1].y - arr[N - 1].y));
		else if (i == N - 1)	S += (arr[i].x * (arr[0].y - arr[i - 1].y));
		else	S += (arr[i].x * (arr[i + 1].y - arr[i - 1].y));
	}
	return S / 2.;
}

ld solve(dd A, vector<dd> B, dd C, dd P, dd Q) {
	vector<dd> V1;
	V1.push_back(A);
	for (dd i : B)	V1.push_back(i);
	V1.push_back(C);
	if (ccw(A, B[0], C) > 0) {
		if (A.x == 0) {
			// 왼쪽
			if (C.y == 0) {
				if (C.x != Q.x)	V1.push_back({ Q.x,0 });
				V1.push_back(Q);
				if (A.y != Q.y)	V1.push_back({ 0,Q.y });
			}
			else if (C.x == Q.x) {
				if (C.y != Q.y)	V1.push_back(Q);
				if (A.y != Q.y)	V1.push_back({ 0,Q.y });
			}
			else if (C.y == Q.y) {
				if (C.x != 0)	V1.push_back({ 0,Q.y });
			}
		}
		else if (A.x == Q.x) {
			// 오른쪽
			if (C.y == Q.y) {
				if (C.x != 0)	V1.push_back({ 0,Q.y });
				V1.push_back(P);
				if (A.y != 0)	V1.push_back({ Q.x,0 });
			}
			else if (C.x == 0) {
				if (C.y != 0)	V1.push_back(P);
				if (A.y != 0)	V1.push_back({ Q.x,0 });
			}
			else if (C.y == 0) {
				if (C.x != Q.x)	V1.push_back({ Q.x,0 });
			}
		}
		else if (A.y == Q.y) {
			// 위쪽
			if (C.x == 0) {
				if (C.y != 0)	V1.push_back(P);
				V1.push_back({ Q.x,0 });
				if (A.x != Q.x)	V1.push_back(Q);
			}
			else if (C.y == 0) {
				if (C.x != Q.x)	V1.push_back({ Q.x,0 });
				if (A.x != Q.x)	V1.push_back(Q);
			}
			else if (C.x == Q.x) {
				if (C.y != Q.y)	V1.push_back(Q);
			}
		}
		else {
			// 아래쪽
			if (C.x == Q.x) {
				if (C.y != Q.y)	V1.push_back(Q);
				V1.push_back({ 0,Q.y });
				if (A.x != 0)	V1.push_back(P);
			}
			else if (C.y == Q.y) {
				if (C.x != 0)	V1.push_back({ 0,Q.y });
				if (A.x != 0)	V1.push_back(P);
			}
			else if (C.x == 0) {
				if (C.y != 0)	V1.push_back(P);
			}
		}
	}
	else {
		if (A.x == 0) {
			// 왼쪽
			if (C.y == Q.y) {
				if (C.x != Q.x)	V1.push_back(Q);
				V1.push_back({ Q.x,0 });
				if (A.y != 0)	V1.push_back(P);
			}
			else if (C.x == Q.x) {
				if (C.y != 0)	V1.push_back({ Q.x,0 });
				if (A.y != 0)	V1.push_back(P);
			}
			else if (C.y == 0) {
				if (C.x != 0)	V1.push_back(P);
			}
		}
		else if (A.x == Q.x) {
			// 오른쪽
			if (C.y == 0) {
				if (C.x != 0)	V1.push_back(P);
				V1.push_back({ 0,Q.y });
				if (A.y != Q.y)	V1.push_back(Q);
			}
			else if (C.x == 0) {
				if (C.y != Q.y)	V1.push_back({ 0,Q.y });
				if (A.y != Q.y)	V1.push_back(Q);
			}
			else if (C.y == Q.y) {
				if (C.x != Q.x)	V1.push_back(Q);
			}
		}
		else if (A.y == Q.y) {
			// 위쪽
			if (C.x == Q.x) {
				if (C.y != 0)	V1.push_back({ Q.x,0 });
				V1.push_back(P);
				if (A.x != 0)	V1.push_back({ 0,Q.y });
			}
			else if (C.y == 0) {
				if (C.x != 0)	V1.push_back(P);
				if (A.x != 0)	V1.push_back({ 0,Q.y });
			}
			else if (C.x == 0) {
				if (C.y != Q.y)	V1.push_back({ 0,Q.y });
			}
		}
		else {
			// 아래쪽
			if (C.x == 0) {
				if (C.y != Q.y)	V1.push_back({ 0,Q.y });
				V1.push_back(Q);
				if (A.x != Q.x)	V1.push_back({ Q.x,0 });
			}
			else if (C.y == Q.y) {
				if (C.x != Q.x)	V1.push_back(Q);
				if (A.x != Q.x)	V1.push_back({ Q.x,0 });
			}
			else if (C.x == Q.x) {
				if (C.y != 0)	V1.push_back({ Q.x,0 });
			}
		}
	}
	return area(V1);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T;
	for (cin >> T; T--;) {
		ld px, py, qx, qy;
		cin >> px >> py >> qx >> qy;
		ld ax, ay, bx, by, cx, cy;
		cin >> ax >> ay >> bx >> by >> cx >> cy;
		ax -= px, bx -= px, cx -= px, qx -= px;
		px = 0;
		ay -= py, by -= py, cy -= py, qy -= py;
		py = 0;
		dd A = { ax, ay }, B = { bx, by }, C = { cx,cy };
		dd P = { px,py }, Q = { qx,qy };


		// 직사각형과의 교점 6개
		// X : AB의 교점
		// Y : CA의 교점
		// Z : BC의 교점
		dd X1, X2, Y1, Y2, Z1, Z2;
		


		ld d1;
		if (B.x == A.x)	d1 = INF;
		else	d1 = ((ld)B.y - A.y) / ((ld)B.x - A.x);
		ld d2;
		if (C.x == B.x)	d2 = INF;
		else	d2 = ((ld)C.y - B.y) / ((ld)C.x - B.x);
		ld d3;
		if (A.x == C.x)	d3 = INF;
		else	d3 = ((ld)A.y - C.y) / ((ld)A.x - C.x);

		// 선분 AB와 직사각형의 교점 X1, X2 구하기

		if (d1 == INF) {
			X1 = { A.x, Q.y };
			X2 = { A.x, 0 };
			if (A.y < B.y)	swap(X1, X2);
		}
		else {
			ld t1 = d1 * -A.x + A.y;
			if (t1 > (ld)Q.y)	X1 = { ((ld)Q.y - A.y) / d1 + A.x, (ld)Q.y };
			else if (t1 < 0.)	X1 = { (ld)A.y * -1. / d1 + A.x, 0. };
			else	X1 = { 0,t1 };

			ld t2 = d1 * ((ld)Q.x - A.x) + A.y;
			if (t2 > (ld)Q.y)	X2 = { ((ld)Q.y - A.y) / d1 + A.x,(ld)Q.y };
			else if (t2 < 0.)	X2 = { (ld)A.y * -1. / d1 + A.x,0 };
			else	X2 = { (ld)Q.x,t2 };
			if (A.x > B.x)	swap(X1, X2);
		}

		if (d2 == INF) {
			Z1 = { B.x,Q.y };
			Z2 = { B.x,0 };
			if (B.y < C.y)	swap(Z1, Z2);
		}
		else {
			ld t1 = d2 * -B.x + B.y;
			if (t1 > (ld)Q.y)	Z1 = { ((ld)Q.y - B.y) / d2 + B.x, (ld)Q.y };
			else if (t1 < 0.)	Z1 = { (ld)B.y * -1. / d2 + B.x, 0. };
			else	Z1 = { 0,t1 };

			ld t2 = d2 * ((ld)Q.x - B.x) + B.y;
			if (t2 > (ld)Q.y)	Z2 = { ((ld)Q.y - B.y) / d2 + B.x,(ld)Q.y };
			else if (t2 < 0.)	Z2 = { (ld)B.y * -1. / d2 + B.x,0 };
			else	Z2 = { (ld)Q.x,t2 };
			if (B.x > C.x)	swap(Z1, Z2);
		}

		if (d3 == INF) {
			Y1 = { C.x,Q.y };
			Y2 = { C.x,0 };
			if (C.y < A.y)	swap(Y1, Y2);
		}
		else {
			ld t1 = d3 * -C.x + C.y;
			if (t1 > (ld)Q.y)	Y1 = { ((ld)Q.y - C.y) / d3 + C.x, (ld)Q.y };
			else if (t1 < 0.)	Y1 = { (ld)C.y * -1. / d3 + C.x, 0. };
			else	Y1 = { 0,t1 };

			ld t2 = d3 * ((ld)Q.x - C.x) + C.y;
			if (t2 > (ld)Q.y)	Y2 = { ((ld)Q.y - C.y) / d3 + C.x,(ld)Q.y };
			else if (t2 < 0.)	Y2 = { (ld)C.y * -1. / d3 + C.x,0 };
			else	Y2 = { (ld)Q.x,t2 };
			if (C.x > A.x)	swap(Y1, Y2);
		}

		ld S = 0;

		if (ccw(A, B, C) > 0) {
			// 반시계
			ld sa = solve(X1, { A }, Y2, P, Q);
			ld sb = solve(Z1, { B }, X2, P, Q);
			ld sc = solve(Y1, { C }, Z2, P, Q);
			S -= (sa + sb + sc);
		}
		else {
			// 시계
			ld sa = solve(Y2, { A, B }, Z1, P, Q);
			ld sb = solve(X2, { B, C }, Y1, P, Q);
			ld sc = solve(Z2, { C, A }, X1, P, Q);
			ld sd = area({ B,A,C });
			S += sa + sb + sc + sd;

		}
		cout.setf(ios::fixed);
		cout.precision(9);
		cout << S << '\n';
		cout.unsetf(ios::fixed);
	}
}