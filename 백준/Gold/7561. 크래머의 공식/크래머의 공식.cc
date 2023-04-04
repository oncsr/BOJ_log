#include <stdio.h>
typedef long long ll;

int main() {
	int t;
	scanf("%d", &t);
	while (t != 0) {
		int a11, a12, a13, b1, a21, a22, a23, b2, a31, a32, a33, b3;
		scanf("%d %d %d %d", &a11, &a12, &a13, &b1);
		scanf("%d %d %d %d", &a21, &a22, &a23, &b2);
		scanf("%d %d %d %d", &a31, &a32, &a33, &b3);
		ll det_A = (ll)(a11 * (a22 * a33 - a23 * a32)) - (ll)(a12 * (a21 * a33 - a23 * a31)) + (ll)(a13 * (a21 * a32 - a22 * a31));
		ll det_A1 = (ll)(b1 * (a22 * a33 - a23 * a32)) - (ll)(a12 * (b2 * a33 - a23 * b3)) + (ll)(a13 * (b2 * a32 - a22 * b3));
		ll det_A2 = (ll)(a11 * (b2 * a33 - a23 * b3)) - (ll)(b1 * (a21 * a33 - a23 * a31)) + (ll)(a13 * (a21 * b3 - b2 * a31));
		ll det_A3 = (ll)(a11 * (a22 * b3 - b2 * a32)) - (ll)(a12 * (a21 * b3 - b2 * a31)) + (ll)(b1 * (a21 * a32 - a22 * a31));
		printf("%lld %lld %lld %lld\n", det_A1, det_A2, det_A3, det_A);
		if (det_A == 0)
			printf("No unique solution\n");
		else {
			double x1, x2, x3;
			x1 = (double)det_A1 / (double)det_A;
			x2 = (double)det_A2 / (double)det_A;
			x3 = (double)det_A3 / (double)det_A;
			if (x1 > -0.0005 && x1 < 0.0005)
				x1 = 0;
			if (x2 > -0.0005 && x2 < 0.0005)
				x2 = 0;
			if (x3 > -0.0005 && x3 < 0.0005)
				x3 = 0;
			printf("Unique solution: %.3lf %.3lf %.3lf\n", x1, x2, x3);
		}
		if (t != 1)
			printf("\n");
		t--;
	}
}