#include <stdio.h>
#include <math.h>
using namespace std;

int main() {
	int n;
	double a, s = 0;
	for (scanf("%d", &n); n--;) {
		scanf("%lf", &a);
		s += a * a * a;
	}
	printf("%.6f", cbrt(s));
}