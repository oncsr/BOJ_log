#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
	int n, p;
	cin >> n >> p;
	vector<int> a(p);
	int num = n;
	a[0] = num;
	int i = 1;
	int brkch = 0;
	while (1)
	{
		a[i] = (a[i - 1] * n) % p;
		for(int j = i - 1 ; j > 0 ; j--)
			if (a[i] == a[j])
			{
				cout << i - j << '\n';
				brkch++;
				break;
			}
		if (brkch != 0)
			break;
		else
			i++;
	}
	return 0;
}