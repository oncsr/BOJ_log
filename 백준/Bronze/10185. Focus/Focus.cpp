#include <stdio.h>
using namespace std;

int main() {
	int t;
	for (scanf("%d", &t); t--;) {
		double a, b;
		scanf("%lf %lf", &a, &b);
		printf("f = %.1f\n", a * b / (a + b));
	}
}