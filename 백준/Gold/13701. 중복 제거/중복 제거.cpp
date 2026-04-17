#include <iostream>
#include <bitset>
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);

	bitset<33554432> B;
	int a;
	while(cin>>a){
		if(!B[a])	cout<<a<<' ';
        B[a]=1;
	}
}