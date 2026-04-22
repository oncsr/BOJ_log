#include <iostream>
using namespace std;

int main(){
	int n, x;
	cin>>n>>x;
	if(x > n*26 || x < n){
		cout<<'!';
		return 0;
	}
	string ans = "";
	int g= 0;
	for(int i=1;i<=n;i++){
		if((n-i)*26 >= (x-1))	ans += 'A', x-=1;
		else{
			ans += 'A' + (x-(n-i)*26) - 1;
			g = n-i;
			break;
		}
	}
	while(g > 0)	ans += 'Z', g-=1;
	cout<<ans;
}