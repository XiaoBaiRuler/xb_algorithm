#include "../common/common.h"
/**
 * @brief LCP 67. 装饰树
 * https://leetcode.cn/problems/KnLfVT/
 */
class Solution {
public:
    TreeNode* expandBinaryTree(TreeNode* root) {
        if (root == nullptr){
            return root;
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        while (!dq.empty()){
            int n = dq.size();
            for (int i = 0; i < n; ++ i){
                TreeNode* pre = dq.front();
                dq.pop_front();
                if (pre -> left != nullptr){
                    TreeNode* left = pre -> left;
                    pre -> left = new TreeNode(-1);
                    pre -> left -> left = left;
                    dq.push_back(left);
                }
                if (pre -> right != nullptr){
                    TreeNode* right = pre -> right;
                    pre -> right = new TreeNode(-1);
                    pre -> right -> right = right;
                    dq.push_back(right);
                }
            }
        }
        return root;
    }
};
int main(){
    TreeNode root(1);
    cout << Solution().expandBinaryTree(&root) -> val << endl;
    return EXIT_SUCCESS;
}