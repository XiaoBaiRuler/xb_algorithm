#define PATH 1
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 974. 和可被 K 整除的子数组
 * https://leetcode.cn/problems/subarray-sums-divisible-by-k/
 * 
 * 注意 C++ 取模的特殊性，当被除数为负数时取模结果为负数，需要纠正
 * 
 * @param nums 
 * @param k 
 * @return int 
 */
int subarraysDivByK(vector<int>& nums, int k);
int main(){
    vector<int> nums = {-1, 2, 9};
    cout << subarraysDivByK(nums, 2) << endl;
    return EXIT_SUCCESS;
}
int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size(), now = 0, res = 0, temp;
    unordered_map<int, int> map;
    map[0] = 1;
    for (int i = 0; i < n; ++ i){
        now += nums[i];
        temp = (now % k + k) % k;
        if (map.find(temp) != map.end()){
            res += map[temp];
        }
        ++ map[temp];
    }
    return res;
}