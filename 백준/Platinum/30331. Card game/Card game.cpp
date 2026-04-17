#include "kortos.h"

int atversti(int a, int b) {
    if (a >= 70) {
        if (b >= a)  return 0;
        return 1;
    }
    return 1;
}