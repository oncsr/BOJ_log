#include "game.h"

int d[1500]{}, g = 0, h, nn;

void initialize(int n) {
    h = n * (n - 1) / 2;
    nn = n;
    for (int i = 0; i < n; i++)    d[i] = n - 1;
}

int hasEdge(int u, int v) {
    if (d[u] == 1 || d[v] == 1)  return 1;
    if (g >= h - nn + 1)    return 1;
    d[u]--, d[v]--;
    g++;
    return 0;
}
