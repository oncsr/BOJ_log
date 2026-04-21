#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    for(cin>>N>>M;N||M;cin>>N>>M){
        int S, E;
        cin>>S>>E;
        vector<int> used(M);
        vector<vector<tuple<int, int, int>>> V(N);
        for(int i=0;i<M;i++){
            int a,b,c;
            cin>>a>>b>>c;
            V[a].push_back({b,c,i});
        }

        int mn = -1, val;
        bool no = 0;
        do{
            priority_queue<ii, vector<ii>, greater<>> Q;
            vector<int> D(N, -1);
            vector<set<int>> R(N);
            D[S] = 0;
            Q.push({0,S});
            while(!Q.empty()){
                int now = Q.top().second;
                int dist = Q.top().first;
                Q.pop();
                if(dist > D[now])   continue;
                for(auto e:V[now]){
                    int next = get<0>(e), cost = get<1>(e), num = get<2>(e);
                    if(used[num])   continue;
                    if(D[next] == -1 || (D[next] > dist+cost)){
                        D[next] = dist+cost;
                        Q.push({D[next], next});
                        R[next] = R[now];
                        R[next].insert(num);
                    }
                    else if(D[next] == dist+cost){
                        for(int i:R[now])   R[next].insert(i);
                        R[next].insert(num);
                    }
                }
            }
            if(D[E] == -1){no = 1;break;}

            for(int i:R[E]) used[i]++;
            if(mn == -1) mn = val = D[E];
            else    val = D[E];
        } while(val == mn);
        if(no)  cout<<-1<<'\n';
        else    cout<<val<<'\n';

        

    }

}