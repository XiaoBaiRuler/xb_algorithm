#include "../common/common.h"
class Solution {
public:
    /**
     * @brief 719. 找出第 K 小的数对距离
     * https://leetcode.cn/problems/find-k-th-smallest-pair-distance/
     * 
     * max :log(10^8) * 10^4 * log(10^4)
     * 当<= res的个数>= k, 并且<= res - 1的个数<k时，那么结果就是res
     * @param nums 
     * @param k 
     * @return int 
     */
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        n = nums.size() - 1;
        if (findTimes(nums, 0) >= k){
            return 0;
        }
        int l = 0, r = nums[n] - nums[0];
        while (l <= r){
            int mid = l + ((r - l) >> 1);
            int now = findTimes(nums, mid);
            if (now >= k && findTimes(nums, mid - 1) < k){
                return mid;
            }
            else if (now < k){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return r;
    }
    /**
     * @brief 
     * 设x为左边界，rr为右边界(从右往左遍历) 两者都对应一个集合
     * => [rr] - x <= m
     * => x >= [rr] - m = tmp
     * 1. 当x中的次最大值比tmp小，那么不可能有符合的结果
     * 2. 当x中的最小值比tmp大或等于时，那么rr剩余的集合都应该有结果
     *  那么符合的结果: 1 + ... + rr = (rr + 1) * rr / 2
     * 3. 其他利用二分法找出刚好比tmp大或等于的值mid
     *  那么符合的结果: rr - mid
     * @param nums 
     * @param m 
     * @return int 
     */
    int findTimes(vector<int>& nums, int m){
        int res = 0;
        for (int rr = n; rr > 0; -- rr){
            int tmp = nums[rr] - m;
            if (nums[rr - 1] < tmp){
                continue;
            }
            if (nums[0] >= tmp){
                res += (rr + 1) * rr / 2;
                return res;
            }
            int l = 0, r = rr - 1;
            while (l <= r){
                int mid = l + ((r - l) >> 1);
                if (nums[mid] >= tmp && nums[mid - 1] < tmp){
                    res += rr - mid;
                    break;
                }
                else if (nums[mid] < tmp){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        return res;
    }
private:
    int n;
};
int main(){
    Solution t;
    vector<int> nums = {1, 1, 3};
    cout << t.smallestDistancePair(nums, 1) << endl;
    return EXIT_SUCCESS;
}