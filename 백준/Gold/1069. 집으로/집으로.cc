#include <stdio.h>
#include <math.h>

double min(double a, double b) {
	if (a < b)
		return a;
	else
		return b;
}

int main() {
	int x, y, d, t;
	scanf("%d %d %d %d", &x, &y, &d, &t);
	double r = sqrt(x * x + y * y);
	double total = r;
	double jump = 0;
	int jump_trial;
	if (d > r) {
		total = min(2 * t, r);
		total = min(t + d - r, total);
	}
	else {
		for (jump_trial = 0; jump < r; jump_trial++) {
			jump += d;
		}
		total = min(jump_trial * t, r);
		total = min((jump_trial - 1) * t + r - (jump_trial - 1) * d, total);
	}
	printf("%.9f\n", total);
}