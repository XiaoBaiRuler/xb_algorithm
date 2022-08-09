#include "..//common//common.h"
/**
 * @brief 560. 和为 K 的子数组
 * https://leetcode.cn/problems/subarray-sum-equals-k/
 * 
 * 记录前缀和个数
 * @param nums 
 * @param k 
 * @return int 
 */
int subarraySum(vector<int>& nums, int k);
int main(){
    vector<int> nums = {1,1,1};
    cout << subarraySum(nums, 2) << endl;
    return EXIT_SUCCESS;
}
int subarraySum(vector<int>& nums, int k) {
    int now = 0, n = nums.size(), res = 0;
    unordered_map<int, int> pre;
    pre[0] = 1;
    for (int i = 0; i < n; ++ i){
        now += nums[i];
        if (pre.find(now - k) != pre.end()){
            res += pre[now - k];
        }
        pre[now] += 1;
    }
    return res;
}