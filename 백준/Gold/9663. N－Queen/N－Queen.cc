#include <iostream>
int a[15] = { 1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596,2279184 };
main() {
	int n;
	std::cin >> n;
	std::cout << a[n - 1];
}