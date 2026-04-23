#include <vector>
#include <random>
int kth(std::vector<int> &a, int k){
    double limit = ((double)a.size() * 3) / 4;
    // random index setting
    std::random_device rdd;
    std::mt19937 gen(rdd());
    std::uniform_int_distribution<int> dis(0, a.size() - 1);
    while(1){
        // generate random index
        int pivot = a[dis(gen)];

        std::vector<int> a1, a2;
        for(int i:a){
            if(i < pivot)   a1.push_back(i);
            else if(i > pivot)   a2.push_back(i);
        }
        if(a1.size() > limit || a2.size() > limit)  continue;
        if(k <= a1.size())  return kth(a1, k);
        else if(k <= a.size() - a2.size())  return pivot;
        else    return kth(a2, k - (a.size() - a2.size()));
    }
}