#include "../common/common.h"
/**
 * @brief 998. 最大二叉树 II
 * https://leetcode.cn/problems/maximum-binary-tree-ii/
 * 
 * 就是最大二叉树I的，再从数组后面添加一个数，来重新构建最大二叉树
 * @param root 
 * @param val 
 * @return TreeNode* 
 */
TreeNode* insertIntoMaxTree(TreeNode* root, int val);
int main(){
    TreeNode *root = new TreeNode(6);
    root = insertIntoMaxTree(root, 8);
    cout << root -> val << endl;
    return EXIT_SUCCESS;
}
TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if (root == nullptr){
        return new TreeNode(val);
    }
    if (root -> val < val){
        TreeNode *now = new TreeNode(val, root, nullptr);
        return now;
    }
    else{
        root -> right = insertIntoMaxTree(root -> right, val);
        return root;
    }
}
