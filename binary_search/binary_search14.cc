#include "../common/common.h"
/**
 * @brief 154. 寻找旋转排序数组中的最小值 II
 * https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/
 * 
 * 设旋转后转折点为m, l = 0, r = size - 1
 * 那么A[l, m], B[m + 1, r] 且 A > B, 两个区间都是递增
 * 
 * 取中间索引mid = l + ((r - l) >> 1)
 * 1. 当[r] > nums[mid]
 * 1.1. mid可能落在A区间，r必须落在A区间，那么(mid - 1, r)就不可能出现最小值
 * 1.2. mid可能落在B区间，r必须落在B区间，那么(mid - 1, r)就不可能出现最小值
 * 2. 当[r] < nums[mid]
 * 2.1. mid可能落在A区间，r必须落在B区间，那么[l, mid + 1]就不可能出现最小值
 * 2.2. mid不可能落在B区间
 * 3. 当[r] == nums[mid]，r无论是不是最小值，都可以排除: 会收敛为O(N)的查询
 * 3.1 mid在A区间时，r可以在A,B区间
 * 3.2 mid在B区间时，r可以B区间
 * 
 * 不断夹逼最小值的范围[l, r), 当范围内只有一个值时，那么l这边就是最小值
 * 
 * 疑惑1: 可不可以以l为基准点呢?
 * 如果[l] < nums[mid]
 * - 当mid在A区间，那么l也必须在A区间，但是不能分开两个区域，其中一个区域不存在最小值
 * 
 * @param nums 
 * @return int 
 */
int findMin(vector<int>& nums);
int main(){
    vector<int> nums = {10, 1, 10, 10};
    cout << findMin(nums) << endl;
    return EXIT_SUCCESS;
}
int findMin(vector<int>& nums) {
    int n = nums.size(), l = 0, r = n - 1;
    while (l < r){
        int mid = l + ((r - l) >> 1);
        if (nums[r] > nums[mid]){
            r = mid;
        }
        else if (nums[r] == nums[mid]){
            -- r;
        }
        else{
            l = mid + 1;
        }
    }
    return nums[l];
}