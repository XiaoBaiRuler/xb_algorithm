#include "../common/common.h"
/**
 * @brief 687. 最长同值路径
 * https://leetcode.cn/problems/longest-univalue-path/
 */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        dfs(root);
        return res - 1;
    }
protected:
    int dfs(TreeNode* root){
        int l = 1, r = 1;
        if (root -> left != nullptr){
            l = dfs(root -> left);
            l = root -> left -> val == root -> val ? l + 1 : 1;
        }
        if (root -> right != nullptr){
            r = dfs(root -> right);
            r = root -> right -> val == root -> val ? r + 1 : 1;
        }
        res = max(l + r - 1, res);
        return max(l, r);
    }
private:
    int res = 1;
};
int main(){
    TreeNode root(1);
    cout << Solution().longestUnivaluePath(&root) << endl;
    return EXIT_SUCCESS;
}