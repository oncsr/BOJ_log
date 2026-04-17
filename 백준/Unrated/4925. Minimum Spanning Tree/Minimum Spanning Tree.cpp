#include <bits/stdc++.h>
using namespace std;

vector<int> root;
int find(int x){
	if(x == root[x])	return x;
	return root[x] = find(root[x]);
}

vector<string> split(string a) {
	vector<string> res;
	string temp = "";
	for (char now : a) {
		if (now == ' ') {
			if (temp != "") {
				res.push_back(temp);
				temp = "";
			}
			continue;
		}
		temp += now;
	}
	if(temp != "")	res.push_back(temp);
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 1;
	string n;
	for(getline(cin, n);n != "0";){
		int N = stoi(split(n)[0]);
		root = vector<int>(N+1);
		iota(root.begin()+1, root.end(), 1);
		vector<tuple<int, int, int>> E;
		map<pair<int, int>, int> M;
		for(int i=1;i<N;i++){
			string  a;
			getline(cin, a);
			vector<string> temp = split(a);
			int j = i+1;
			for(auto k:temp){
				int g = stoi(k);
				if(g){
					E.emplace_back(g,i,j);
					M[{i,j}] = M[{j,i}] = g;
				}
				j++;
			}
		}
		sort(E.begin(), E.end());
		int S = 0, cnt = 0;
		for(auto [c, a, b] : E){
			int x = find(a), y = find(b);
			if(x==y)	continue;
			root[x] = y;
			S += c;
			cnt++;
		}
		bool no = 0;
		if(cnt != N-1)	no = 1;
		
		string q;
		getline(cin, q);
		int Q = stoi(split(q)[0]), t = 1;
		for(;Q--;){
			string line;
			getline(cin, line);
			vector<string> V = split(line);
			stack<int> st;
			int edge = 0, sum = 0;
			vector<bool> vis(N+1);
			for(string i:V){
				if(i[0] == '('){
					string temp = i.substr(1, i.size()-1);
					int now = stoi(temp);
					vis[now] = 1;
					st.emplace(now);
				}
				else{
					int j = 0;
					for(;j<i.size() && i[j]>='0' && i[j] <= '9';j++);
					string temp = i.substr(0,j);
					int now = stoi(temp);
					vis[now] = 1;
					if(M.find({now, st.top()}) != M.end()){
						edge++;
						sum += M[{now, st.top()}];
					}
					if(j == i.size())	continue;

					for(;j<i.size();j++){
						now = st.top();
						st.pop();
						if(st.empty())	break;
						int next = st.top();
						if(M.find({now, next}) != M.end()){
							edge++;
							sum += M[{now, next}];
						}
					}
				}
			}
			bool yes = edge == N-1 && sum == S;
			for(int i=1;i<=N;i++)	yes &= vis[i];
			cout<<T<<'.'<<t++<<' '<<(!no && yes?"YES":"NO");
			if(Q)	cout<<' '<<endl;
		}
		getline(cin, n);
		if(n != "0")	cout<<' '<<endl;
		T++;
	}

}