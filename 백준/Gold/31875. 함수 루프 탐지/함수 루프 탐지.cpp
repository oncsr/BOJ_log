#include <bits/stdc++.h>
using namespace std;

map<string, int> pre;
map<vector<string>, vector<int>> pos;

string arr[100001]{};

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin>>N;
    
    for(int i=1;i<=N;i++) cin>>arr[i];

    for(int i=1;i<=N;i++) {
        string a = arr[i];

        if(pre.find(a) != pre.end()) {
            int j = pre[a];
            int dest = i, len = j-i;
            set<string> s;
            vector<string> v;
            while(j<dest && i<=N && arr[i] == arr[j]) {
                v.push_back(arr[i]);
                if(s.count(arr[i])) {
                    break;
                }
                s.insert(arr[i]);
                i++, j++;
            }
            
            i--;
            if(j == dest) {
                pos[v].push_back(dest-len);
            }
            for(int k=dest;k<=i;k++) pre[arr[k]] = k;

        }
        else pre[a] = i;

    }

    int max_repeat = 0, first_idx = -1;
    vector<string> ans;
    for(auto [v, vv]:pos) {

        int len = v.size();
        int max_cnt = 1, that_idx = vv[0];
        int cnt = 1, idx = vv[0];
        for(int i=1;i<vv.size();i++) {
            if(vv[i]-vv[i-1] == len) {
                cnt++;
                if(cnt > max_cnt) max_cnt = cnt, that_idx = idx;
            }
            else cnt = 1, idx = vv[i];
        }

        if(max_cnt > max_repeat || (max_cnt == max_repeat && that_idx < first_idx)){
            max_repeat = max_cnt;
            first_idx = that_idx;
            ans = v;
        }
        
    }

    if(max_repeat == 0) cout<<"-1";
    else{
        cout<<ans.size()<<' '<<max_repeat+1<<'\n';
        for(string i:ans) cout<<i<<' ';
    }

}