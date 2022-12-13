#include <iostream>
#include <queue>
using namespace std;
struct node {
	int x, y, z, t;
};
int main() {
	int n, v[61][61][61]{}, a[3]{};
	int dir[6][3] = { {9,3,1},{9,1,3},{3,1,9},{3,9,1},{1,3,9},{1,9,3} };
	cin >> n;
	node s;
	for (int i = 0; i < n; i++)	cin >> a[i];
	s.x = a[0], s.t = 0;
	if (n > 1)	s.y = a[1];
	if (n > 2)	s.z = a[2];
	queue<node> Q;
	Q.push(s);
	v[a[0]][a[1]][a[2]]++;
	while (!Q.empty()) {
		node now = Q.front();
		Q.pop();
		int xx = now.x, yy = now.y, zz = now.z;
		if (!xx && !yy && !zz) {
			cout << now.t;
			break;
		}
		for (int i = 0; i < 6; i++) {
			int x = max(xx - dir[i][0], 0);
			int y = max(yy - dir[i][1], 0);
			int z = max(zz - dir[i][2], 0);
			if (!v[x][y][z]) {
				v[x][y][z]++;
				Q.push({ x,y,z,now.t + 1 });
			}
		}
	}
}