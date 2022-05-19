#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 462. 最少移动次数使数组元素相等 II
 * https://leetcode.cn/problems/minimum-moves-to-equal-array-elements-ii/
 * 
 * 中位数是最优基准
 * 
 * @param nums 
 * @return int 
 */
int minMoves2(vector<int>& nums);
int main(){

    vector<vector<int>> nums = {
        {1, 2, 3},
        {1, 10, 2, 9}
    };
    for (int i = 0, n = nums.size(); i < n; ++ i){
        cout << minMoves2(nums[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}

int minMoves2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int l = 0, res = 0, r = nums.size() - 1;
    while (l < r){
        res += (nums[r --] - nums[l ++]);
    }
    return res;
}