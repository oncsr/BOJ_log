#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a;
	vector<int> pa, ma, pb, mb;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a > 0)	pa.push_back(a);
		else	ma.push_back(-a);
	}
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a > 0)	pb.push_back(a);
		else	mb.push_back(-a);
	}
	sort(pa.begin(), pa.end());
	sort(pb.begin(), pb.end());
	sort(ma.begin(), ma.end());
	sort(mb.begin(), mb.end());
	int ans = 0;
	int p1 = 0, p2 = 0;
	while (p1 < pa.size() && p2 < mb.size()) {
		if (pa[p1] < mb[p2])	ans++, p1++;
		p2++;
	}
	p1 = 0, p2 = 0;
	while (p1 < pb.size() && p2 < ma.size()) {
		if (pb[p1] < ma[p2])	ans++, p1++;
		p2++;
	}
	cout << ans;
}