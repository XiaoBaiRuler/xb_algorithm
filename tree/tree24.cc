#include "../common/common.h"
/**
 * @brief 剑指 Offer 33. 二叉搜索树的后序遍历序列
 * https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
 * 
 * 二叉搜索树 + 后序遍历序列(递归)
 */
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verify(postorder, 0, postorder.size() - 1);
    }
    bool verify(vector<int>& nums, int l, int r){
        if (l >= r){
            return true;
        }
        int mid = nums[r], i = 0, j;
        for (; i < r && nums[i] < mid; ++ i){}
        j = i;
        for (; i < r && nums[i] > mid; ++ i){}
        if (i != r){
            return false;
        }
        if (j != 0 && !verify(nums, l, j - 1)){
            return false;
        }
        if (j != r && !verify(nums, j, r - 1)){
            return false;
        }
        return true;

    }
};
int main(){
    vector<int> nums = {1,3,2,6,5};
    cout << Solution().verifyPostorder(nums) << endl;
    return EXIT_SUCCESS;
}