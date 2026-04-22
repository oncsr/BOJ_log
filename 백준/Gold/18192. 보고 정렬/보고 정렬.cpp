#include "bogoSort.h"

void sort_array(int N) {
	int s = 0;
    while(s<N){
        std::vector<int> now=copy_array();
        while(s<N&&s==now[s])s++;
        if(s==N)break;
        int e=s;
        for(;e<N&&now[e]!=s;e++);
        shuffle_array(s,e);
        
    }
}