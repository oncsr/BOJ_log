#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct trie{
    map<string, trie> words;
};

void dfs(trie a, string pre){
    for(auto it = a.words.begin();it != a.words.end(); it++){
        cout<<pre<<it->first<<'\n';
        dfs(it->second, pre + "--");
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    trie root;
    int N;
    for(cin>>N;N--;){
        int k;
        trie *temp = &root;
        for(cin>>k;k--;){
            string a;
            cin>>a;
            temp = &(temp->words[a]);
        }
    }

    dfs(root, "");

}