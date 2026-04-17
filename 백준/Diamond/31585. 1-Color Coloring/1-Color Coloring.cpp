#include "coloring.h"
#include <bits/stdc++.h>
using namespace std;

void ColoringSame(int N){
	Color(1);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> R(2, N);
    for(int i=0;i<98;i++){
        int vis[101]{};
        for(int j=0;j<min(N-1,74);j++){
            int g = R(gen);
            while(vis[g])    g = R(gen);
            vis[g]++;
        }
        for(int j=2;j<=N;j++){
            if(vis[j])    Color(j);
        }
    }
}
