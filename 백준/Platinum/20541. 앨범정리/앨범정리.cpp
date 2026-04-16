#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<int, int> operator+(pair<int, int> a, pair<int, int> b){
	return {a.first + b.first, a.second + b.second};
}

int delete_photo(vector<string> &cur, string S);
pair<int, int> rmalb(vector<string> &cur, string S);

map<vector<string>, pair<set<string>, set<string>>> M;

bool mkalb(vector<string> &cur, string S){
	if(M[cur].first.count(S))	return 0;
	M[cur].first.insert(S);
	return 1;
}

void rm(vector<string> &cur, string S, pair<int, int> &a){
	cur.push_back(S);
	a = a + rmalb(cur,"0");
	a.second += delete_photo(cur,"0");
	M.erase(cur);
	cur.pop_back();
}

pair<int, int> rmalb(vector<string> &cur, string S){
	pair<int, int> res = {0,0};
	set<string> &P = M[cur].first;
	if(S == "0"){
		res.first += P.size();
		for(string i:P)	rm(cur, i, res);
		P = set<string>();
	}
	else{
		if(!P.empty()){
			if(S == "-1")	S = *P.begin();
			if(S == "1")	S = *P.rbegin();
			if(P.count(S)){
				res.first++;
				rm(cur, S, res);
				P.erase(S);
			}
		}
	}
	return res;
}

bool insert_photo(vector<string> &cur, string S){
	if(M[cur].second.count(S))	return 0;
	M[cur].second.insert(S);
	return 1;
}

int delete_photo(vector<string> &cur, string S){
	set<string> &P = M[cur].second;
	int prev = P.size();
	if(S == "0")	P = set<string>();
	else{
		if(!P.empty()){
			if(S == "-1")	S = *P.begin();
			if(S == "1")	S = *P.rbegin();
			P.erase(S);
		}
	}
	return prev - P.size();
}

string ca(vector<string> &cur, string S){
	if(S == ".."){
		if(cur.size() != 1)	cur.pop_back();
	}
	else if(S == "/"){
		cur = {"album"};
	}
	else{
		if(M[cur].first.count(S))	cur.push_back(S);
	}
	return cur.back();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	vector<string> current = {"album"};
	M[current] = make_pair(set<string>(), set<string>());

	int N;
	for(cin>>N;N--;){
		string op, S;
		cin>>op>>S;
		if(op == "rmalb"){
			auto [a,b] = rmalb(current,S);
			cout<<a<<' '<<b<<'\n';
		}
		if(op == "mkalb" && !mkalb(current,S))	cout<<"duplicated album name\n";
		if(op == "insert" && !insert_photo(current,S))	cout<<"duplicated photo name\n";
		if(op == "delete")	cout<<delete_photo(current,S)<<'\n';
		if(op == "ca")	cout<<ca(current,S)<<'\n';
	}

}