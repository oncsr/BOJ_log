#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using pp = pair<ll, ll>;
#define x first
#define y second

ll ccw(pp a, pp b, pp c) {
	//	vec1 = a -> b
	pp vec1 = { b.x - a.x,b.y - a.y };

	//	vec2 = b -> c
	pp vec2 = { c.x - b.x,c.y - b.y };

	//	outer product of vec1, vec2
	// ccw > 0  : counter-clockwise
	// ccw == 0 : a line
	// ccw < 0  : clockwise
	ll C = (ll)vec1.x * vec2.y - (ll)vec1.y * vec2.x;
	
	if (C > 0)	return 1;
	else if (C < 0)	return -1;
	else	return 0;
}

struct vegi {
	pp s, e;
	ll w;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	vegi arr[2500]{};
	ll inter[2500]{};	// i와 겹치는 베기들의 가중치 합
	ll inter_point[2500]{};	// i와 겹치는 베기의 개수
	bool isinter[2500][2500]{};	// i와 j가 겹치는지?
	bool disabled[2500]{};
	for (int i = 0; i < N; i++) {
		ll a, b, c, d, f;
		cin >> a >> b >> c >> d >> f;
		arr[i].s = { a,b };
		arr[i].e = { c,d };
		arr[i].w = f;
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			// 베기 i, j가 겹치는 지 확인
			vegi A = arr[i], B = arr[j];
			// 겹침
			if (ccw(A.s, A.e, B.s) * ccw(A.s, A.e, B.e) < 0 && ccw(B.s, B.e, A.s) * ccw(B.s, B.e, A.e) < 0) {
				inter[i] += arr[j].w;
				inter[j] += arr[i].w;
				inter_point[i]++, inter_point[j]++;
				isinter[i][j] = isinter[j][i] = 1;
			}
		}
	}
	ll s = 0;
	for (int i = 0; i < N; i++) {
		// 베기를 했을 때 가장 낮은 점수를 얻는 걸 선택
		ll mn = 9e18, ans = 0, c = 0;
		for (int j = 0; j < N; j++) {
			if (disabled[j])	continue;
			ll G = arr[j].w;
			if (G < mn)	mn = G, ans = j, c = inter_point[j];
			else if (G == mn && inter_point[j] > c) {
				mn = G, ans = j, c = inter_point[j];
			}
		}
		s += arr[ans].w * (inter_point[ans] + 1);
		for (int j = 0; j < N; j++) {
			if (j == ans)	continue;
			if (disabled[j])	continue;
			if (!isinter[ans][j])	continue;
			inter[j] -= arr[ans].w;
			inter_point[j]--;
			isinter[ans][j] = isinter[j][ans] = 0;
		}
		disabled[ans] = 1;
	}
	cout << s;
}