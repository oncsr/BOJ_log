#include <iostream>
#include <set>
using namespace std;

set<string> colors;

struct Node{
    Node *next[26];
    bool last;
    Node(){
        this->last = false;
        for(int i=0;i<26;i++) next[i] = 0;
    }
};

struct Trie{
    Node *root;
    Trie(){
        root = new Node();
    }
    void insert(string s){
        Node *now = root;
        for(int i=s.size()-1;i>=0;i--){
            int idx = s[i] - 'a';
            bool isLast = i==0;
            if(!now->next[idx]) now->next[idx] = new Node();
            now = now->next[idx];
        }
        now->last = true;
    }
    bool find(string s){
        Node *now = root;
        while(s.size()>1){
            int idx = s.back() - 'a';
            if(!now->next[idx]) return false;
            s.pop_back();
            now = now->next[idx];
            if(now->last && colors.count(s)) return true;
        }
        return false;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    Trie *trie = new Trie();
    int N, M, Q;
    cin>>N>>M;
    for(int i=0;i<N;i++) {
        string s;
        cin>>s;
        colors.insert(s);
    }
    for(int i=0;i<M;i++){
        string s;
        cin>>s;
        trie->insert(s);
    }

    for(cin>>Q;Q--;){
        string s;
        cin>>s;
        cout<<(trie->find(s) ? "Yes\n" : "No\n");
    }

}