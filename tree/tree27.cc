#include "../common/common.h"
/**
 * @brief 979. 在二叉树中分配硬币
 * https://leetcode.cn/problems/distribute-coins-in-binary-tree/
 * 
 * 自底向上遍历
 */
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        distribute(root);
        return res;
    }
    int distribute(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        int left = distribute(root -> left);    
        int right = distribute(root -> right);
        res += abs(left) + abs(right);
        return root -> val + left + right - 1;
    }
private:
    int res = 0;
};
int main(){
    TreeNode root(1);
    cout << Solution().distributeCoins(&root) << endl;
    return EXIT_SUCCESS;
}