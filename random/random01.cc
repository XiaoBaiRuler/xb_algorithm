#include "G:\algorithm\xb_algorithm\common\common.h"
/**
 * @brief 398. 随机数索引
 * https://leetcode-cn.com/problems/random-pick-index/
 * 
 * 水塘抽样 待证明
 * 
 * @param nums 
 * @param target 
 * @return int 
 */
int pick(vector<int>& nums, int target); 
int pick(vector<int>& nums, int target){
    int res, n= nums.size();
    for (int i = 0, c = 0; i < n; ++i) {
        if (nums[i] == target) {
            ++ c; 
            if (rand() % c == 0) {
                res = i;
            }
        }
    }
    return res;
} 