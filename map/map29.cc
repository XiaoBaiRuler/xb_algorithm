#include "../common/common.h"
/**
 * @brief 298. 二叉树最长连续序列
 * https://leetcode.cn/problems/binary-tree-longest-consecutive-sequence/
 */
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        return max(dfs(root), res);
    }
protected:
    int dfs(TreeNode* root){
        bool l = root -> left != nullptr;
        bool r = root -> right != nullptr;
        int ll = 0, rr = 0;
        if (l){
            ll = dfs(root -> left);
        }
        if (r){
            rr = dfs(root -> right);
        }
        int ans = 1;
        if (l && root -> left -> val - root -> val == 1){
            ans = max(ll + 1, ans);
        }
        if (r && root -> right -> val - root -> val == 1){
            ans = max(rr + 1, ans);
        }
        res = max(res, ans);
        return ans;
    }
private:
    int res = 1;
};
int main(){
    TreeNode root(1);
    cout << Solution().longestConsecutive(&root) << endl;
    return EXIT_SUCCESS;
}