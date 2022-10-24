#include "../common/common.h"
/**
 * @brief 543. 二叉树的直径
 * https://leetcode.cn/problems/diameter-of-binary-tree/
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        select(root); 
        return res;
    }
    int select(TreeNode* root){
        int l = root -> left == nullptr ? -1 : select(root -> left);
        int r = root -> right == nullptr ? -1 : select(root -> right);
        int n = max(l + 1, r + 1);
        res = max(l + r + 2, res);
        return n;
    }
private:
    int res = 0;
};
int main(){
    TreeNode a(1), b(2), root(0, &a, &b);
    cout << Solution().diameterOfBinaryTree(&root) << endl;
    return EXIT_SUCCESS;
}