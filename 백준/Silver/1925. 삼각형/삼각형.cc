#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main() {
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;
	string tri1 = "", tri2 = "";
	
	int a = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	int b = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
	int c = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
	int d[3] = { a,b,c };
	sort(d, d + 3);
	double r1 = sqrt(a);
	double r2 = sqrt(b);
	double r3 = sqrt(c);
	double e[3] = { r1,r2,r3 };
	sort(e, e + 3);

	if (e[0] + e[1] == e[2])
		tri1 = "X";
	else if (e[0] == e[1] && e[1] == e[2])
		tri1 = "JungTriangle";
	else {
		if (e[0] == e[1])
			tri2 = "2Triangle";
		else if (e[1] == e[2])
			tri2 = "2Triangle";
		else
			tri2 = "Triangle";
		
		if (d[0]+d[1] > d[2])
			tri1 = "Yeahkak";
		else if (d[0]+d[1] < d[2])
			tri1 = "Dunkak";
		else
			tri1 = "Jikkak";
	}
	cout << tri1 + tri2 << '\n';
}