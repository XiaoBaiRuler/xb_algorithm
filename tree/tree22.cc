#include "../common/common.h"
/**
 * @brief 572. 另一棵树的子树
 * https://leetcode.cn/problems/subtree-of-another-tree/submissions/
 */
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()){
            TreeNode* now = st.top();
            if (now -> val == subRoot -> val && isSameTree(now, subRoot)){
                return true;
            }
            st.pop();
            if (now -> right != nullptr){
                st.push(now -> right);
            }
            if (now -> left != nullptr){
                st.push(now -> left);
            }
        }
        return false;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr){
            return p == q;
        }
        if (p -> val != q -> val){
            return false;
        }
        if (!isSameTree(p -> left, q -> left)){
            return false;
        }
        return isSameTree(p -> right, q -> right);
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* subRoot = new TreeNode(1);
    cout << Solution().isSubtree(root, subRoot) << endl;
    return EXIT_SUCCESS;
}