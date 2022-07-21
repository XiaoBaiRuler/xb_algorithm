#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**
 * @brief 814. 二叉树剪枝
 * https://leetcode.cn/problems/binary-tree-pruning/
 * 
 * 
 * 后续遍历 逐渐缩小问题规模 再收敛
 * @param root 
 * @return TreeNode* 
 */
TreeNode* pruneTree(TreeNode* root);
int main(){
    TreeNode root(0);
    cout << pruneTree(&root) << endl;
    return EXIT_SUCCESS;
}
TreeNode* pruneTree(TreeNode* root) {
    if (root == nullptr){
        return root;
    }
    root -> left = pruneTree(root->left);
    root -> right = pruneTree(root -> right);
    if (root -> left == nullptr && root -> right == nullptr && root -> val == 0){
        return nullptr;
    }
    return root;
}