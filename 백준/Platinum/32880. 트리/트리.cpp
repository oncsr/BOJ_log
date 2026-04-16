#include <bits/stdc++.h>
#include "tree.h"

using namespace std;
using ll = long long;

vector<vector<int>> V;
vector<int> A, P;
vector<ll> D, U, X, Y;
ll g = -1e18;

void dfs1(int n, int p){
    P[n] = p;
    D[n] = A[n];
    int leaves = 0;
    for(int i:V[n]){
        if(i == p)  continue;
        dfs1(i,n);
        leaves++;
        D[n] += max(0LL, D[i]);
        X[n] = max(X[n], X[i]);
    }
    if(leaves)  X[n] = max(X[n], D[n]);
    else    X[n] = D[n];
    if(n == 0){
        priority_queue<ll> Q;
        for(int i:V[n]) Q.push(X[i]);
        if(Q.size() < 2)    return;
        g = 0;
        g += Q.top();
        Q.pop();
        g += Q.top();
    }

}

void dfs2(int n, int p){
    U[n] = n > 0 ? D[p] - max(0LL, D[n]) + max(0LL, U[p]) : 0;
    Y[n] = n > 0 ? max(Y[p], U[n]) : -1e18;
    for(int i:V[n]){
        if(i == p)  continue;
        dfs2(i,n);
    }
}

ll findSum(int N, vector<int> C, vector<int> Node1, vector<int> Node2){
    V = vector<vector<int>>(N);
    A = C;
    P = vector<int>(N);
    D = vector<ll>(N);
    U = vector<ll>(N);
    X = vector<ll>(N, -1e18);
    Y = vector<ll>(N);

    for(int i=0;i<N-1;i++)  V[Node1[i]].push_back(Node2[i]), V[Node2[i]].push_back(Node1[i]);
    dfs1(0,-1);
    dfs2(0,-1);
    ll ans = g;
    for(int i=1;i<N;i++){
        priority_queue<ll> Q;
        Q.push(Y[i]);
        for(int j:V[i]){
            if(j == P[i])   continue;
            Q.push(X[j]);
        }
        if(Q.size() < 2)    continue;
        ll res = 0;
        res += Q.top();
        Q.pop();
        res += Q.top();
        ans = max(ans, res);
    }
    return ans;
}
