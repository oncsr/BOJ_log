#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	string a, b;
	cin>>a>>b;
	stack<int> S;
	string ans = "";
	int id = -1;
	for(char i:a){
		if(b[id+1] != i){
			if(b[0] == i){
				S.push(0);
				id = 0;
			}
			else{
				string temp = "";
				while(!S.empty()){
					temp += b[S.top()];
					S.pop();
				}
				reverse(temp.begin(), temp.end());
				ans += temp;
				ans += i;
				id = -1;
			}
			continue;
		}
		id++;
		S.push(id);
		if(id == b.size()-1){
			for(int j=0;j<b.size();j++)
				S.pop();
			if(S.empty())	id = -1;
			else 	id = S.top();
		}
	}
	string temp = "";
	while(!S.empty()){
		temp += b[S.top()];
		S.pop();
	}
	reverse(temp.begin(), temp.end());
	ans += temp;
	if(ans.empty())	cout<<"FRULA";
	else 	cout<<ans;
}