#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 801. 使序列递增的最小交换次数
 * https://leetcode.cn/problems/minimum-swaps-to-make-sequences-increasing/
 * 
 * 1. 当两个数组都是正序时，
 * 1.1. 一个数组的当前值，比另一个数组的前一个值大时，当前交不交换，也上一个状态无关
 *      nswap = min(pnswap, pswap);
 *      swap = nswap + 1;
 * 1.2. 否则，当前如果要交换，那么上一个也要交换，反之，亦然
 *      swap = pswap + 1;
 *      nswap = pnswap;
 * 2. 当两个数组可能有非正序的，那么当前交换，上一个就不能交换，当前不交换，上一个就要交换
 *  swap = pnswap + 1;
 *  nswap = pswap;
 *      
 * @param nums1 
 * @param nums2 
 * @return int 
 */
int minSwap(vector<int>& nums1, vector<int>& nums2);
int main(){
    vector<vector<int>> nums1 = {
        {1, 3, 5, 4},
        {0, 3, 5, 8, 9}
    };
    vector<vector<int>> nums2 = {
        {1, 2, 3, 7},
        {2, 1, 4, 6, 9}
    };
    int n = nums1.size();
    for (int i = 0; i < n; ++ i){
        cout << minSwap(nums1[i], nums2[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
int minSwap(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), pnswap = 0, pswap = 1;
    for (int i = 1; i < n; ++ i){
        int swap, nswap;
        if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]){
            if (nums2[i] > nums1[i - 1] && nums1[i] > nums2[i - 1]){
                nswap = min(pnswap, pswap);
                swap = nswap + 1;
            }
            else{
                swap = pswap + 1;
                nswap = pnswap;
            }
        }
        else{
            swap = pnswap + 1;
            nswap = pswap;
        }
        pswap = swap;
        pnswap = nswap;
    }
    return min(pswap, pnswap);
}