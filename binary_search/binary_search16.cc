#include "../common/common.h"
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
    return EXIT_SUCCESS;
}