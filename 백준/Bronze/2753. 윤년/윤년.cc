#include <iostream>
using namespace std;

int main()
{
	int n;	cin >> n;
	bool result1, result2;
	if((n%4 == 0) && !(n%100 == 0))	result1 = true;
	else	result1 = false;
	if(n%400 == 0)	result2 = true;
	else	result2 = false;
	if(result1 || result2)	cout << '1' << endl;
	else	cout << '0' << endl;
}