#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	int result = 0;
	int c = 5;
	while (n >= c) {
		result += (n / c);
		c *= 5;
	}
	std::cout << result << '\n';
}