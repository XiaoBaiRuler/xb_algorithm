#include "..//common//common.h"
/**
 * @brief 325. 和等于 k 的最长子数组长度
 * https://leetcode.cn/problems/maximum-size-subarray-sum-equals-k/
 * 
 * 利用Hash来构造前缀和
 * @param nums 
 * @param k 
 * @return int 
 */
int maxSubArrayLen(vector<int>& nums, int k);
int main(){
    vector<int> nums = {0, 0, 0};
    cout << maxSubArrayLen(nums, 0) << endl;
    return EXIT_SUCCESS;
}
int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<long long, int> map;
    int n = nums.size(), ma = 0;
    long long presum = 0;
    for (int i = 0; i < n; ++ i){
        presum += nums[i];
        if (presum == k){
            ma = i + 1;
        }
        else if (map.find(presum - k) != map.end() && i - map[presum - k] > ma){
            ma = i - map[presum - k];
        }
        if (map.find(presum) == map.end()){
            map[presum] = i;
        }
    }
    return ma;
}