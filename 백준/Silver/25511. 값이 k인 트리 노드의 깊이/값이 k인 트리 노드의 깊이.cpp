#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<vector<int> > T(100001);
vector<int> val(100001);

void dfs(int n, int p, int dest, int dep)
{
    if(val[n] == dest)
    {
        cout<<dep;
        return;
    }
    for(int i:T[n])
    {
        if(i != p)
        {
            dfs(i,n,dest,dep+1);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;

    for(int i=1;i<N;i++)
    {
        int a, b;
        cin>>a>>b;
        T[a].push_back(b);
        T[b].push_back(a);
    }

    for(int i=0;i<N;i++)
    {
        int a;
        cin>>a;
        val[i] = a;
    }

    dfs(0,-1,K,0);

}