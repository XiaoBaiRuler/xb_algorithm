#include "../common/common.h"
<<<<<<< HEAD
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
=======
/**
 * @brief 4. 寻找两个正序数组的中位数
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/
 * 
 * => 寻找最中间的数mid = ((n + m) >> 1)
 *  1. 总和为奇数，那么就是求[mid + 1]
 *  2. 总和为偶数，那么就是求([mid] + [mid + 1]) / 2
 * 
 * => 求最中间的数
 *  假设最中间数在A和B之间，那么先处理其中一个数组的d = mid / 2 + 1
 *  1. 那么A的边界就是t1 = [k1 = l + d > n - 1 ? n - 1 : l + d]
 *  2. 那么B的边界就是t2 = [k2 = r + d > m - 1 ? m - 1 : r + d]
 *      - t1 > t2, 那么B可以排除[r, k1 - r]的元素
 *      - 否则，A可以排除[l, k2 - l]的元素
 * 
 * 注意边界条件:
 *  1. 当两边分剩余一个元素时，取最小那个
 *  2. 当A到达数组边界时，剩下元素都取B
 *  2. 当B到达数组边界时，剩下元素都取A
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size(); 
        m = nums2.size();
        int mid = (n + m) >> 1;
        double two = find(nums1, nums2, mid + 1);
        if ((m + n) != (mid << 1)){
            return two;
        }
        double one = find(nums1, nums2, mid);
        return (two + one) / 2;
    }
    double find(vector<int>& nums1, vector<int>& nums2, int d){
        int l = 0, r = 0;
        while (true){
            if (l == n){
                return nums2[r + d - 1];
            }
            if (r == m){
                return nums1[l + d - 1];
            }
            if (d == 1){
                return nums1[l] < nums2[r] ? nums1[l] : nums2[r]; 
            }
            int mid = d / 2 - 1;
            int ll = l + mid > n - 1 ? n - 1 : l + mid;
            int rr = r + mid > m - 1 ? m - 1 : r + mid;
            if (nums1[ll] > nums2[rr]){
                d -= (rr - r + 1);
                r = rr + 1;
            }
            else{
                d -= (ll - l + 1);
                l = ll + 1;
            }
        }
    }
private:
    int n, m;
};
int main(){
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
>>>>>>> 79441e913cf5ce67acb46d08a83432bcb65faa1e
    return EXIT_SUCCESS;
}