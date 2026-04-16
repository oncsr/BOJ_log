#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int N, T, M, S, E;
vector<int> dist;

int main(){
	cin.tie(0)->sync_with_stdio(0);

    cin>>N>>T>>M>>S>>E;
    dist = vector<int>(N, INF);
    dist[S] = 0;
    for(int t=1;t<=T;t++) {
        vector<int> nDist = dist;
        for(int j=1,s,e,w;j<=M;j++) {
            cin>>s>>e>>w;
            nDist[e] = min(nDist[e], dist[s] + w);
            nDist[s] = min(nDist[s], dist[e] + w);
        }
        for(int i=0;i<N;i++) dist[i] = min(dist[i], nDist[i]);
    }

    cout<<(dist[E] == INF ? -1 : dist[E]);

}