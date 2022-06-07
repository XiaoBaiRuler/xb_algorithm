#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 875. 爱吃香蕉的珂珂
 * https://leetcode.cn/problems/koko-eating-bananas/
 * 
 * 二分法猜数
 * @param piles 
 * @param h 
 * @return int 
 */
bool check(vector<int>& piles, int mid, int h);
int minEatingSpeed(vector<int>& piles, int h);
int main(){
    vector<vector<int>> piles = {
        {3,6,7,11},
        {30,11,23,4,20},
        {30,11,23,4,20}
    };
    vector<int> h = {8, 5, 6};
    int n = h.size();
    for (int i = 0; i < n; ++ i){
        cout << minEatingSpeed(piles[i], h[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}


int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1, r = piles[0], mid;
    for (int p : piles){
        if (p > r){
            r = p;
        }
    }
    while (l < r){
        mid = (l + r) >> 1;
        if (check(piles, mid, h)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return r;
}
bool check(vector<int>& piles, int mid, int h){
    int c = 0;
    for (int p : piles){
        if (p % mid != 0){
            ++ c;
        }
        c += p / mid;
    }
    return c <= h;
}