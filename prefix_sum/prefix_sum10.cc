#include "..//common//common.h"
/**
 * @brief 724. 寻找数组的中心下标
 * https://leetcode.cn/problems/find-pivot-index/submissions/
 * 
 * 前缀和 + 后缀和
 * @param nums 
 * @return int 
 */
int pivotIndex(vector<int>& nums);
int main(){
    vector<int> nums = {-1, -1, 0, 0, -1, -1};
    cout << pivotIndex(nums) << endl;
    return EXIT_SUCCESS;
}
int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    res[n - 1] = nums[n - 1];
    for (int i = n - 2; i > -1; -- i){
        res[i] = res[i + 1] + nums[i];
    }
    int temp = 0;
    for (int i = 0; i < n - 1; ++ i){
        if (temp == res[i + 1]){
            return i;
        }
        temp += nums[i];
    }
    return temp == 0 ? n - 1 : -1;
}