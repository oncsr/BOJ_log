#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int F[1000001]{};
	for(int i=100;i<=1000000;i++){
		string s = to_string(i);
		int pos = max_element(s.begin(), s.end()) - s.begin();
		int res = 1 <= pos && pos <= s.size()-2;
		for(int j=1;j<=pos;j++){
			if(s[j-1] >= s[j])	{res = 0;break;}
		}
		for(int j=pos+1;j<s.size();j++){
			if(s[j-1] <= s[j])	{res = 0;break;}
		}
		F[i] = F[i-1] + res;
	}

	int T;
	for(cin>>T;T--;){
		int a,b;
		cin>>a>>b;
		cout<<F[b] - F[a-1]<<'\n';
	}

}