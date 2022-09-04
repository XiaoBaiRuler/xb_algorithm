#include "../common/common.h"
/**
 * @brief 153. 寻找旋转排序数组中的最小值
 * https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/
 * 
 * 设旋转后转折点为m, l = 0, r = size - 1
 * 那么A[l, m], B[m + 1, r] 且 A > B
 * 
 * 取中间索引mid = l + ((r - l) >> 1)
 * 1. 当[0] > nums[mid], 那么mid落在B上
 * 1.1. 且nums[mid] < nums[mid - 1], return mid
 * 1.2. 否则r = mid - 1
 * 2. 当[0] <= nums[mid], 那么mid落在A上
 * 2.1. 否则l = mid + 1
 * @param nums 
 * @return int 
 */
int findMin(vector<int>& nums);
int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << findMin(nums) << endl;
    return EXIT_SUCCESS;
}
int findMin(vector<int>& nums) {
    int n = nums.size(), l = 0, r = n - 1;
    while (l <= r){
        int mid = l + ((r - l) >> 1);
        if (nums[0] > nums[mid]){
            if (nums[mid] < nums[mid - 1]){
                return nums[mid];
            }
            else{
                r = mid - 1;
            }
        }
        else{
            l = mid + 1;
        }
    }
    return nums[0];
}