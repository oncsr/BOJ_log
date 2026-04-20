#include <iostream>
using namespace std;

int main(){
	
	int cnt[26]{};
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char a;
		cin>>a;
		if((n&1) && i==(n+1)>>1) continue;
		cnt[a-'a']++;
	}
	for(int i=0;i<26;i++){
		if(cnt[i]&1) {cout<<"No";return 0;}
	}
	cout<<"Yes";
}