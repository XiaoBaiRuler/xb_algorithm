#include "../common/common.h"
/**
 * @brief 105. 从前序与中序遍历序列构造二叉树
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * 
 * 递归构建 找到某个树的根节点进行分治
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir){
        TreeNode *root = new TreeNode(preorder[pl]);
        for (int i = il; i <= ir; ++ i){
            if (inorder[i] == preorder[pl]){
                // 左子树
                int next = pl + i - il;
                if (i > il){
                    root -> left = build(preorder, pl + 1, next, inorder, il, i - 1);
                }
                // 右子树
                if (ir > i){
                    root -> right = build(preorder, next + 1, pr, inorder, i + 1, ir);
                }
                return root;
            }

        }
        return nullptr;
    }
};
int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = Solution().buildTree(preorder, inorder);
    cout << root -> val << endl;
    return EXIT_SUCCESS;
}