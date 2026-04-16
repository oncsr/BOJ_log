#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int M, N;
	cin>>M>>N;
	int a[5]{};
	string _;
	cin>>_;
	for(int i=0;i<M;i++){
		string arr[5]{};
		for(int j=0;j<5;j++)	cin>>arr[j];
		for(int j=1;j<5*N;j+=5){
			if(arr[3][j] == '*')	a[4]++;
			else if(arr[2][j] == '*')	a[3]++;
			else if(arr[1][j] == '*')	a[2]++;
			else if(arr[0][j] == '*')	a[1]++;
			else 	a[0]++;
		}
	}
	for(int i=0;i<5;i++)	cout<<a[i]<<' ';
	
}