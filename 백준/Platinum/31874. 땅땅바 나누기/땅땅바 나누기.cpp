#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	int N;
	cin >> N;
	// x,y축에 걸쳐있는 보물들의 가치 합
	ll neg_x = 0, pos_x = 0, neg_y = 0, pos_y = 0, base = 0;
	ll __1 = 0, __2 = 0, __3 = 0, __4 = 0;
	// _13 = 1,3사분면 점들 | _24 = 2,4사분면 점들
	vector<tuple<int, int, ll>> _13, _24;
	for (int i = 0; i < N; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0)    base += c;
		else if (a == 0) neg_y += (b < 0 ? 1 : 0) * c, pos_y += (b > 0 ? 1 : 0) * c;
		else if (b == 0) neg_x += (a < 0 ? 1 : 0) * c, pos_x += (a > 0 ? 1 : 0) * c;
		else {
			if (a * b > 0){
				_13.emplace_back(a, b, c);
				if(a > 0)	__1 += c;
				else 	__3 += c;
			}
			else{
				_24.emplace_back(a, b, c);
				if(a > 0)	__4 += c;
				else 	__2 += c;
			}
		}
	}
 
	// y축이 답인 경우
	ll A = neg_x + __2 + __3, B = pos_x + __1 + __4;
 
	ll mx = min(A, B);
	pair<int, int> ans = { 1,0 };
 
 
	// 1사분면 스위핑
	sort(_13.begin(), _13.end(), [&](tuple<int, int, ll> a, tuple<int, int, ll> b) -> bool {
		auto [px, py, pv] = a;
		auto [qx, qy, qv] = b;
		if (py < 0)  px *= -1, py *= -1;
		if (qy < 0)  qx *= -1, qy *= -1;
		return (ll)px * qy > (ll)qx * py;
	});
 
	// 초기 : A 영역엔 1,2사분면 점들, B 영역엔 3,4사분면 점들
	A = pos_y + __1 + __2, B = neg_y + __3 + __4;
	
	if (min(A, B) > mx)   mx = min(A, B), ans = { 0,1 };
	A += neg_x, B += pos_x;
	if (min(A, B) > mx)   mx = min(A, B), ans = { 1,1'000'000'001 };
 
 
	int idx = 0;
	while (idx < _13.size()) {
		ll _1 = 0, _3 = 0;
		auto [px, py, pv] = _13[idx];
		while (idx < _13.size() - 1 && (ll)py * get<0>(_13[idx+1]) == (ll)px * get<1>(_13[idx+1])) {
			int gy = get<1>(_13[idx]);
			ll gv = get<2>(_13[idx]);
			if (gy > 0)  _1 += gv;
			else    _3 += gv;
			idx++;
		}
		px = get<0>(_13[idx]);
		py = get<1>(_13[idx]);
		pv = get<2>(_13[idx]);
		if (py > 0)  _1 += pv;
		else    _3 += pv;
		// _1 : A -> B, _3 : B -> A
		A -= _1, B -= _3;
		A += _3, B += _1;
 
		if (min(A, B) > mx) {
			mx = min(A, B);
 
			int qx, qy;
			if (py < 0)	px *= -1, py *= -1;
			if (idx == _13.size() - 1)	qx = 0, qy = 1'000'000'000;
			else {
				qx = get<0>(_13[idx + 1]), qy = get<1>(_13[idx + 1]);
				if (qy < 0)	qx *= -1, qy *= -1;
			}
			int mid_x = px + qx, mid_y = py + qy;
			ans = { mid_y, mid_x };
		}
		idx++;
	}
 
	// 2사분면 스위핑
	sort(_24.begin(), _24.end(), [&](tuple<int, int, ll> a, tuple<int, int, ll> b) -> bool {
		auto [px, py, pv] = a;
		auto [qx, qy, qv] = b;
		if (py < 0)  px *= -1, py *= -1;
		if (qy < 0)  qx *= -1, qy *= -1;
		return (ll)px * qy < (ll)qx * py;
	});
 
	A = pos_y + __1 + __2, B = neg_y + __3 + __4;
	
	A += pos_x, B += neg_x;
	if (min(A, B) > mx)   mx = min(A, B), ans = { 1,-1'000'000'001 };
 
	idx = 0;
	while (idx < _24.size()) {
		ll _2 = 0, _4 = 0;
		auto [px, py, pv] = _24[idx];
		while (idx < _24.size() - 1 && (ll)py * get<0>(_24[idx+1]) == (ll)px * get<1>(_24[idx+1])) {
			int gy = get<1>(_24[idx]);
			ll gv = get<2>(_24[idx]);
			if (gy > 0)  _2 += gv;
			else    _4 += gv;
			idx++;
		}
		px = get<0>(_24[idx]);
		py = get<1>(_24[idx]);
		pv = get<2>(_24[idx]);
		if (py > 0)  _2 += pv;
		else    _4 += pv;
		// _2 : A -> B, _4 : B -> A
		A -= _2, B -= _4;
		A += _4, B += _2;
		if (min(A, B) > mx) {
			mx = min(A, B);
 
			int qx, qy;
			if (py < 0)	px *= -1, py *= -1;
			if (idx == _24.size() - 1)	qx = 0, qy = 1'000'000'000;
			else {
				qx = get<0>(_24[idx + 1]), qy = get<1>(_24[idx + 1]);
				if (qy < 0)	qx *= -1, qy *= -1;
			}
			int mid_x = px + qx, mid_y = py + qy;
			ans = { mid_y, mid_x };
		}
		idx++;
	}
 
	cout << ans.first << ' ' << ans.second;
 
}
