#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 324. 摆动排序 II
 * https://leetcode.cn/problems/wiggle-sort-ii/
 * 
 * 桶排序
 * @param nums 
 */
void wiggleSort(vector<int>& nums);
int main(){
    vector<vector<int>> nums = {
        {1,5,1,1,6,4},
        {1,3,2,2,3,1}
    };
    int n = nums.size();
    for (int i = 0; i < n; ++ i){
        wiggleSort(nums[i]);
        for (int c : nums[i]){
            cout << c << " ";
        }
        cout << endl;
    }
}
void wiggleSort(vector<int>& nums) {
    int max = 0;
    for (int i : nums){
        if (max < i){
            max = i;
        }
    }
    vector<int> hash(max + 1, 0);
    for (int i : nums){
        hash[i] += 1;
    }
    int l = 0, i = 0, n = nums.size();
    while (i < n){
        while(l <= max && hash[l] == 0){
            ++ l;
        }
        hash[l] --;
        nums[i ++] = l;
    }
    l = (n - 1) >> 1;
    int r = n - 1;
    i = 0;
    vector<int> res;
    while (i < n){
        if (l >= 0){
            res.push_back(nums[l]);
            -- l;
            ++ i;
        }
        if (i < n){
            res.push_back(nums[r]);
            -- r;
            ++ i;
        }
    }
    nums = res;
}