#include "../common/common.h"
/**
 * @brief 33. 搜索旋转排序数组
 * https://leetcode.cn/problems/search-in-rotated-sorted-array/
 * 
 * 设旋转后转折点为m, l = 0, r = size - 1
 * 那么A[l, m], B[m + 1, r] 且 A > B
 * 取中间索引mid = l + ((r - l) >> 1)
 * 1. 当[0] > nums[mid], 那么mid落在B上
 * 1.1. 且t落在(mid, r], l = mid + 1
 * 1.2. 否则r = mid - 1
 * 2. 当[0] <= nums[mid], 那么mid落在A上
 * 2.1. 且t落在[l, mid), r = mid - 1
 * 2.2. 否则l = mid + 1
 * 
 * @param nums 
 * @param target 
 * @return int 
 */
int search(vector<int>& nums, int target);
int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << search(nums, 0) << endl;
    return EXIT_SUCCESS;
}
int search(vector<int>& nums, int target) {
    int n = nums.size(), l = 0, r = n - 1;
    while (l <= r){
        int mid = l + ((r - l) >> 1);
        if (nums[mid] == target){
            return mid;
        }
        if (nums[0] <= nums[mid]){
            if (nums[mid] > target && nums[l] <= target){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        else{
            if (nums[mid] < target && nums[r] >= target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
    }
    return -1;
}