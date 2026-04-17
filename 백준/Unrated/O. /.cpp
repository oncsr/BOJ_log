#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	random_device rd;
	mt19937 gen(rd());
	vector<int> A(10000), B(10000);
	bool fa = 0, fb = 0;
	int a = 0, b = 0;
	iota(A.begin(), A.end(), 1);
	iota(B.begin(), B.end(), 1);
	shuffle(A.begin(), A.end(), gen);
	shuffle(B.begin(), B.end(), gen);
	int c = 0, i = 0;
	while(!fa){
		cout<<"? A "<<A[i]<<endl;
		cin>>fa;
		a = A[i];
		c++;
		i++;
	}
	i = 0;
	while(c <= 19997 && !fb){
		cout<<"? B "<<B[i]<<endl;
		cin>>fb;
		b = B[i];
		c++;
		i++;
	}
	cout<<"! "<<a+b<<endl;


}