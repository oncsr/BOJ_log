#include <bits/stdc++.h>
using namespace std;

int N, K, Q, sq;
int arr[100001]{}, ans[100001]{}, cnt[200001]{}, ccnt[1001]{};
vector<deque<int>> D(100001);
vector<tuple<int, int, int>> queries;

int main(){
	cin.tie(0)->sync_with_stdio(0);

    cin>>N>>K;
    sq = sqrt(N);
    for(int i=1;i<=N;i++) cin>>arr[i];

    cin>>Q;
    for(int i=0,a,b;i<Q;i++) {
        cin>>a>>b;
        queries.emplace_back(a,b,i);
    }

    sort(queries.begin(), queries.end(), [](auto a, auto b) -> bool {
        auto [as, ae, _a] = a;
        auto [bs, be, _b] = b;
        if(as / sq == bs / sq) return ae < be;
        return as / sq < bs / sq;
    });

    int pl = 1, pr = 0;
    cnt[0]++;
    ccnt[0]++;
    for(auto [l,r,x] : queries) {
        while(r > pr) {
            int val = arr[++pr];
            if(!D[val].empty()) {
                int prev = D[val].back() - D[val].front();
                cnt[prev]--;
                ccnt[prev/sq]--;
            }
            D[val].push_back(pr);
            int res = D[val].back() - D[val].front();
            cnt[res]++;
            ccnt[res/sq]++;
        }
        while(pr > r) {
            int val = arr[pr];
            int res = D[val].back() - D[val].front();
            D[val].pop_back();
            cnt[res]--;
            ccnt[res/sq]--;
            if(!D[val].empty()) {
                int nxt = D[val].back() - D[val].front();
                cnt[nxt]++;
                ccnt[nxt/sq]++;
            }
            pr--;
        }
        while(l > pl) {
            int val = arr[pl];
            int res = D[val].back() - D[val].front();
            D[val].pop_front();
            cnt[res]--;
            ccnt[res/sq]--;
            if(!D[val].empty()) {
                int nxt = D[val].back() - D[val].front();
                cnt[nxt]++;
                ccnt[nxt/sq]++;
            }
            pl++;
        }
        while(pl > l) {
            int val = arr[--pl];
            if(!D[val].empty()) {
                int prev = D[val].back() - D[val].front();
                cnt[prev]--;
                ccnt[prev/sq]--;
            }
            D[val].push_front(pl);
            int res = D[val].back() - D[val].front();
            cnt[res]++;
            ccnt[res/sq]++;
        }

        for(int i=1000;i>=0;i--) if(ccnt[i]) {
            for(int j=(i+1)*sq-1;j>=i*sq;j--) if(cnt[j]) {
                ans[x] = j;
                break;
            }
            break;
        }
    }

    for(int i=0;i<Q;i++) cout<<ans[i]<<'\n';

}