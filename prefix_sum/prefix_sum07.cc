#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 523. 连续的子数组和
 * https://leetcode.cn/problems/continuous-subarray-sum/
 * 
 * % 如果出现重复，那么必有符合
 * @param nums 
 * @param k 
 * @return true 
 * @return false 
 */
bool checkSubarraySum(vector<int>& nums, int k);
int main(){
    vector<int> nums = {23, 2, 4, 6, 7};
    cout << checkSubarraySum(nums, 6) << endl;
    return EXIT_SUCCESS;
}
bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size(), now = 0, temp;
    unordered_map<int, int> map;
    map[0] = -1;
    for (int i = 0; i < n; ++ i){
        now += nums[i];
        temp = now % k;
        if (map.find(temp) != map.end()){
            if (i - map[temp] > 1){
                return true;
            }
        }
        else{
            map[temp] = i;
        }
    }
    return false;
}