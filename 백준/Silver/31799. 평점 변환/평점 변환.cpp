#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int to_num(string s){
	if(s == "")	return 9;
	int res = (s[0] - 'A') * 3;
	if(s.size() == 1)	return res+1;
	if(s[1] == '+')	return res;
	res++;
	if(s[1] == '0')	return res;
	return res+1;
}

char change(string pr, string now){
	int _pr = to_num(pr), _now = to_num(now);
	if(_now >= 6)	return 'B';
	if(_now >= 4){
		if(_pr >= 6)	return 'D';
		return 'B';
	}
	if(_now >= 2){
		if(_pr >= 4)	return 'P';
		return 'D';
	}
	if(_now == 1){
		if(_pr >= 2)	return 'E';
		return 'P';
	}
	return 'E';
}

vector<string> parse(string line){
	vector<string> res = {""};
	for(int i=0;i<line.size();i++){
		string temp = "";
		temp += line[i];
		if(i+1 < line.size()){
			if(line[i+1] == '+' || line[i+1] == '0' || line[i+1] == '-')	temp += line[++i];
		}
		res.push_back(temp);
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin>>N;
	string line;
	cin>>line;
	vector<string> res = parse(line);
	for(int i=1;i<res.size();i++){
		cout<<change(res[i-1], res[i]);
	}

}