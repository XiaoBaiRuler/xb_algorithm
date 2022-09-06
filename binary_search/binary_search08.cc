#include "../common/common.h"
int findRight(vector<int>& nums, int target);
int findLeft(vector<int>& nums, int target);
/**
 * @brief 34. 在排序数组中查找元素的第一个和最后一个位置
 * https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
 * 
 * 分别使用二分查询查找左右边界
 * @param nums 
 * @param target 
 * @return vector<int> 
 */
vector<int> searchRange(vector<int>& nums, int target);
int main(){
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> res = searchRange(nums, 8);
    cout << res[0] << " " << res[1] << endl;
    return EXIT_SUCCESS;
}
vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.size() == 0){
        return vector<int>(2, -1);
    }
    int l = findLeft(nums, target);
    if (l == -1){
        return vector<int>(2, -1);
    }
    vector<int> res = {l, findRight(nums, target)};
    return res;
}
int findLeft(vector<int>& nums, int target){
    if (nums[0] == target){
        return 0;
    }
    int l = 0, r = nums.size() - 1;
    while (l <= r){
        int mid = l + ((r - l) >> 1);
        if (nums[mid] == target && nums[mid - 1] != target){
            return mid;
        }
        else if (nums[mid] < target){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return -1;
}
int findRight(vector<int>& nums, int target){
    int r = nums.size() - 1, l = 0;
    if (nums[r] == target){
        return r;
    }
    while (l <= r){
        int mid = l + ((r - l) >> 1);
        if (nums[mid] == target && nums[mid + 1] != target){
            return mid;
        }
        else if (nums[mid] > target){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return -1;
}