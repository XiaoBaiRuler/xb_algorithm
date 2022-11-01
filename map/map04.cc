#include "../common/common.h"
/**
 * @brief 226. 翻转二叉树
 * https://leetcode.cn/problems/invert-binary-tree/
 * 
 * 深度优先搜索
 * @param root 
 * @return TreeNode* 
 */
TreeNode* invertTree(TreeNode* root);
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) 
        return nullptr;
    TreeNode* rightTree = root -> right;
    root -> right = invertTree(root -> left);
    root -> left = invertTree(rightTree);
    return root;
}
int main(){
    cout << invertTree(nullptr) << endl;
    return EXIT_SUCCESS;
}