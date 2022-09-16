#include <iostream>
#include <stack>
#include <string>

using namespace std;
stack<int> S;
int arr[50001];

bool exist(int n)
{
	for(int i = 0;arr[i] != '\0';i++)
		if (arr[i] == n)
			return true;
	return false;
}

int main()
{
	int n;	cin >> n;
	int result = 0;
	int i = 0;
	int a = 0;
	while (n--)
	{
		int x, y;
		cin >> x >> y;
		if (S.empty())
		{
			S.push(y);
			arr[i] = y;
			i++;
		}
		else
		{
			if (y > S.top())
			{
				S.push(y);
				arr[i] = y;
				i++;
			}
			else
			{
				int ex = 0;
				if (exist(y) && y != 0)
					ex++;
				while (S.top() > y)
				{
					S.pop();
					i--;
					arr[i] = 0;
					result++;
					if (S.empty())
						break;
				}
				if (!ex && y != 0)
				{
					S.push(y);
					arr[i] = y;
					i++;
				}
			}
		}
	}
	while (!S.empty())
	{
		if (S.top() != 0)
		{
			S.pop();
			result++;
		}
		else
			S.pop();
	}
	cout << result << endl;
	return 0;
}