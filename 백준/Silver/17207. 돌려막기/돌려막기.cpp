#include <bits/stdc++.h>
using namespace std;

struct cmp{
    bool operator()(pair<int, int> b, pair<int, int> a){
        if(a.first == b.first)  return a.second > b.second;
        return a.first < b.first;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int A[5][5]{}, B[5][5]{}, W[5][5]{};
    for(int i=0;i<5;i++)    for(int j=0;j<5;j++)    cin>>A[i][j];
    for(int i=0;i<5;i++)    for(int j=0;j<5;j++)    cin>>B[i][j];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++)    W[i][j] += A[i][k] * B[k][j];
        }
    }
    string name[5] = {"Inseo","Junsuk","Jungwoo","Jinwoo","Youngki"};
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> Q;
    for(int i=0;i<5;i++){
        int s = 0;
        for(int j=0;j<5;j++)    s += W[i][j];
        Q.emplace(s, i);
    }
    cout<<name[Q.top().second];
}