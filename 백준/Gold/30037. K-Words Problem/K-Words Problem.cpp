#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

vector<string> split(string a, char i) {
	vector<string> res;
	string temp = "";
	for (char now : a) {
		if (now == i) {
			if (temp != "") {
				res.push_back(temp);
				temp = "";
			}
			continue;
		}
		temp += now;
	}
	res.push_back(temp);
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin>>N;
	cin.ignore();
	for(int i=0;i<N;i++){
		string line;
		getline(cin, line);
		vector<string> words = split(line, ' ');
		string temp = "", temp2 = "", temp3 = "";
		vector<string> arr1;
		for(string i:words){
			if(temp == "of" && temp2 != "" && temp2.back() != ',' && temp2.back() != '!' && temp2.back() != '?'){
				if(i == "Korea"){
					if(temp2.front() >= 97)	temp2.front() -= 32;
					temp = "K-" + temp2;
					temp2 = temp3;
					temp3 = "";
					arr1.pop_back();
					arr1.pop_back();
					arr1.push_back(temp);
				}
				else if(i == "Korea!" || i == "Korea?" || i == "Korea," || i == "Korea."){
					if(temp2.front() >= 97)	temp2.front() -= 32;
					temp = "K-" + temp2 + i.back();
					temp2 = temp3;
					temp3 = "";
					arr1.pop_back();
					arr1.pop_back();
					arr1.push_back(temp);
				}
				else{
					temp3 = temp2;
					temp2 = temp;
					temp = i;
					arr1.push_back(i);
				}
			}
			else{
				temp3 = temp2;
				temp2 = temp;
				temp = i;
				arr1.push_back(i);
			}
		}
		line = "";
		for(string i:arr1)	line += (i + " ");
		line.pop_back();

		words = split(line, ' ');
		stack<string> arr2;
		for(int i=words.size()-1;i>=0;i--){
			string now = words[i];
			if(now == "Korea"){
				temp = arr2.top();
				arr2.pop();
				if(temp.front() >= 97)	temp.front() -= 32;
				temp = "K-" + temp;
				arr2.push(temp);
			}
			else 	arr2.push(now);
		}
		string ans = "";
		while(!arr2.empty()){
			ans += (arr2.top() + " ");
			arr2.pop();
		}
		ans.pop_back();
		cout<<ans<<'\n';
	}

} 