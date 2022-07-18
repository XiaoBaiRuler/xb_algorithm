#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 525. 连续数组
 * https://leetcode.cn/problems/contiguous-array/
 * 
 * 关键: 把0变-1，那么就是求和为0的最长数组了
 * @param nums 
 * @return int 
 */
int findMaxLength(vector<int>& nums);
int main(){
    vector<int> nums = {0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1};
    cout << findMaxLength(nums) << endl;
    return EXIT_SUCCESS;
}
int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> map;
    array<int, 2> it = {-1, 1};
    int z = 0, n = nums.size(), ma = 0;
    for (int i = 0; i < n; ++ i){
        z += it[nums[i]];
        if (z == 0){
            ma = i + 1;
        }
        if (map.find(z) != map.end()){
            ma = max(ma, i - map[z]);
        }
        else{
            map[z] = i;
        }
    }
    return ma;
}