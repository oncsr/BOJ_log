#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	string a, b, ans = "";
	cin>>a>>b;
	int sa = a.size(), sb = b.size();
	for(char i:a){
		ans += i;
		if(ans.size() < sb)	continue;
		string ch = ans.substr(ans.size() - b.size(), b.size());
		if(ch == b){
			for(int j=0;j<sb;j++)	ans.pop_back();
		}
	}
	cout<<(ans.empty()?"FRULA":ans);
}