#include <bits/stdc++.h>
using namespace std;

int main(){
    string x;
    cin>>x;
    vector<int> ord(x.size());
    iota(ord.begin(), ord.end(), 0);
    int mn = 1e9;
    do{
        string t = "";
        for(int i:ord) t += x[i];
        if(stoi(t) > stoi(x)) mn = min(mn, stoi(t));
    }while(next_permutation(ord.begin(), ord.end()));
    cout<<(mn==1e9 ? 0 : mn);
}