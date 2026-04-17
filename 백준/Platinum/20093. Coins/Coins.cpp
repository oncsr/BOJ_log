#include "coins.h"

std::vector<int> coin_flips(std::vector<int> b, int c) {
	int s = 0;
	for(int i=0;i<64;i++){
		if(b[i])	s ^= i;
	}
	return {s^c};
}

int find_coin(std::vector<int> b) {
	int s = 0;
	for(int i=0;i<64;i++){
		if(b[i])	s ^= i;
	}
	return s;
}
