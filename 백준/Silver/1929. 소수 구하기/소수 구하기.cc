#include <iostream>
using namespace std;

int sqrt(int n)
{
	int i = 1;
	for (; i * i <= n; i++)
		;
	return i - 1;
}

bool e[1000001] = { false };

bool sosu(int n)
{
	int i = 1;
	for (int j = 2; j < n; j++)
		if (n % j == 0)
			i++;

	if (i == 1)
		return true;
	else
		return false;
}

void eratos(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (sosu(i))
			for (int j = i * 2; j <= n; j += i)
				e[j] = true;
	}
}

void print(int m, int n)
{
	for (int i = m; i <= n; i++)
		if (!e[i])
			cout << i << '\n';
}

int main()
{
	int m, n;	cin >> m >> n;
	e[1] = true;
	eratos(n);
	print(m, n);
}