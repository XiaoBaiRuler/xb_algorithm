#include "../common/common.h"
/**
 * @brief 106. 从中序与后序遍历序列构造二叉树
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * 
 * 递归构建 找到某个树的根节点进行分治
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode* build(vector<int>& postorder, int pl, int pr, vector<int>& inorder, int il, int ir){
        TreeNode *root = new TreeNode(postorder[pr]);
        for (int i = il; i <= ir; ++ i){
            if (inorder[i] == postorder[pr]){
                // 左子树
                int next = pl + i - il - 1;
                if (i > il){
                    root -> left = build(postorder, pl, next, inorder, il, i - 1);
                }
                // 右子树
                if (ir > i){
                    root -> right = build(postorder, next + 1, pr - 1, inorder, i + 1, ir);
                }
                return root;
            }

        }
        return nullptr;
    }
};
int main(){
    vector<int> postorder = {9,15,7,20,3};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = Solution().buildTree(inorder, postorder);
    cout << root -> val << endl;
    return EXIT_SUCCESS;
}