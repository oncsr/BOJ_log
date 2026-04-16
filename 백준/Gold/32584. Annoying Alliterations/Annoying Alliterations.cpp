#include <bits/stdc++.h>
using namespace std;

struct node{
	int E = 0;
	node *go[26];
};

node *R;

int ans = 0;

node *make(){
	node *temp = (node *)malloc(sizeof(node));
	temp->E = 0;
	for(int i=0;i<26;i++)	temp->go[i] = NULL;
	return temp;
}

int dfs(node *n){
	int mx1 = 0, mx2 = 0;
	for(int i=0;i<26;i++){
		if(n->go[i] == NULL)	continue;
		int g = dfs(n->go[i]);
		if(g > mx1)	mx2 = mx1, mx1 = g;
		else if(g > mx2)	mx2 = g;
	}
	if(n->E || mx2)	ans = max(ans, mx1 + mx2);
	return mx1+1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	R = make();

	int N;
	for(cin>>N;N--;){
		string s;
		cin>>s;
		node *r = R;
		for(int j=0;j<s.size();j++){
			char i = s[j];
			if(r->go[i-'a'] == NULL)	r->go[i-'a'] = make();
			r = r->go[i-'a'];
			if(j == s.size()-1)	r->E = 1;
		}
	}
	dfs(R);

	cout<<ans;

}