#include "../common/common.h"
/**
 * @brief 162. 寻找峰值
 * https://leetcode.cn/problems/find-peak-element/
 * 
 * 范围[0, n]
 * mid: l + ((r - l) >> 1)
 * 注意边界: 0 / n
 * 
 * 设f1为mid - 1到mid是否递增;
 * 设f2为mid到mid + 1是否递减
 * 根据前后元素的比较值来区分两半
 * 1. f1 && f2: mid
 * 2. !f1: 那么左边会出现峰值
 * 3. 其他: 那么右边会出现峰值 
 * 
 * @param nums 
 * @return int 
 */
int findPeakElement(vector<int>& nums);
int main(){
    vector<int> nums = {1,2,1,3,5,6,4};
    cout << findPeakElement(nums) << endl;
    return EXIT_SUCCESS;
}
int findPeakElement(vector<int>& nums) {
    int n = nums.size() - 1;
    if (n == 0){
        return 0;
    }
    if (nums[0] > nums[1]){
        return 0;
    }
    if (nums[n] > nums[n - 1]){
        return n;
    }
    int l = 1, r = n - 1;
    while (l <= r){
        int mid = l + ((r - l) >> 1);
        bool f1 = nums[mid - 1] < nums[mid];
        bool f2 = nums[mid + 1] < nums[mid];
        if (f1 && f2){
            return mid;
        }
        else if (!f1){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return r;
}