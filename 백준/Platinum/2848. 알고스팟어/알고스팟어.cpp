#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int edge[26][26]{}, N;
    int deg[26]{};
    cin>>N;
    if(N == 1){
        string a;
        cin>>a;
        set<char> S;
        for(char i:a)   S.insert(i);
        if(S.size() > 1)    cout<<"?";
        else    cout<<a[0];
        return 0;
    }
    string arr[100]{};
    int cnt[26]{};
    for(int i=0;i<N;i++){
        cin>>arr[i];
        if(!i)  continue;
        for(char j:arr[i])  cnt[j-'a'] = 1;

        for(int j=0;j<i;j++){
            int id = 0;
            while(id < min(arr[j].size(), arr[i].size())){
                if(arr[j][id] != arr[i][id])  break;
                id++;
            }
            if(id == min(arr[j].size(), arr[i].size())){
                if(arr[j].size() > arr[i].size()) return cout<<"!", 0;
                continue;
            }
            int x = arr[j][id] - 'a', y = arr[i][id] - 'a';
            if(!edge[x][y]) deg[y]++, edge[x][y] = 1;
        }
    }

    queue<int> Q;
    int c = 0, g = 0;
    for(int i=0;i<26;i++){
        if(cnt[i]){
            c++;
            if(!deg[i])   Q.push(i), g++;
        }
    }
    if(g > 1)   return cout<<"?", 0;

    vector<char> ans;
    while(!Q.empty()){
        int n = Q.front();
        Q.pop();
        ans.push_back('a'+n);
        c--;
        g = 0;
        for(int i=0;i<26;i++){
            if(edge[n][i]){
                if(!--deg[i])   Q.push(i), g++;
            }
        }
        if(g > 1)   return cout<<"?", 0;
    }

    if(c)   cout<<"!";
    else    for(char i:ans) cout<<i;

}