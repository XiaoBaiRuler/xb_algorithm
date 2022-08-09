#include "..//common//common.h"
/**
 * @brief 1248. 统计「优美子数组」
 * https://leetcode.cn/problems/count-number-of-nice-subarrays/
 * @param nums 
 * @param k 
 * @return int 
 */
int numberOfSubarrays(vector<int>& nums, int k);
int main(){
    vector<int> nums = {1, 1, 2, 1, 1};
    cout << numberOfSubarrays(nums, 2) << endl;
    return EXIT_SUCCESS;
}
int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size(), res = 0, now = 0, temp = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < n; ++i){
        if (nums[i] & 1){
            map[now] = temp + 1;
            ++ now;
            temp = 0;
        }
        else{
            ++ temp;
        }
        if (map.find(now - k) != map.end()){
            res += map[now - k];
        }
    }
    return res;
}