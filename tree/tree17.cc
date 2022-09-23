#include "../common/common.h"
/**
 * @brief 654. 最大二叉树   
 * https://leetcode.cn/problems/maximum-binary-tree/
 * 
 * 递归构建二叉树
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size() - 1;
        return circle(nums, 0, n);
    }
    TreeNode* circle(vector<int>& nums, int l, int r){
        // 叶子节点
        if (l == r){
            return new TreeNode(nums[l]);
        }
        int j = l;
        for (int i = l + 1; i <= r; ++ i){
            if (nums[i] > nums[j]){
                j = i;
            }
        }
        TreeNode *now = new TreeNode(nums[j]);
        // 剩下右子树
        if (j == l){
            now -> right = circle(nums, j + 1, r);
            return now;
        }
        // 剩下左子树
        if (j == r){
            now -> left = circle(nums, l, j - 1);
            return now;
        }
        // 都有
        now -> left = circle(nums, l, j - 1);
        now -> right = circle(nums, j + 1, r);
        return now;
    }
};
int main(){
    vector<int> nums = {3,2,1,6,0,5};
    TreeNode* root = Solution().constructMaximumBinaryTree(nums);
    cout << root -> val << endl;
    return EXIT_SUCCESS;
}