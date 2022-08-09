#include "..//common//common.h"
/**
 * @brief 442. 数组中重复的数据
 * https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/
 * 
 * 1. 数据在[1,n]之内, 可以利用本身数组作为hash
 * 2. 每个数据最多重复2次，那么可以使用负数，作为已经访问过一次对应位置 + 1的数
 * 3. 当出现下一次跳转访问时为负数，即为重复两次的数
 * 
 * @param nums 
 * @return vector<int> 
 */
vector<int> findDuplicates(vector<int>& nums);
const int m = 1000000;
int main(){
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6};
    vector<int> res = findDuplicates(nums);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res;
    int i = 0, n = nums.size();
    for (int i = 0; i < n; ++i) {
        int tmp = abs(nums[i]) - 1;
        if (nums[tmp] > 0) {
            nums[tmp] = -nums[tmp];
        }
        else {
            res.push_back(tmp + 1);
        }
    }
    return res;
}