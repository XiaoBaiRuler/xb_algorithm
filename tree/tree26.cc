#include "../common/common.h"
/**
 * @brief 124. 二叉树中的最大路径和
 * https://leetcode.cn/problems/binary-tree-maximum-path-sum/
 * 
 * 递归遍历子树 -> 每个子树的最大路径和 = 当前节点 + 左子树最大路径和 + 右子树最大路径和
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
    int dfs(TreeNode* now){
        if (now == nullptr){
            return 0;
        }
        int left = max(dfs(now -> left), 0);
        int right = max(dfs(now -> right), 0);
        // 当前子树下的总贡献值
        int ans = left + right + now -> val;
        res = max(res, ans);
        // 最大的路径
        return now -> val + max(left, right);
    }
private:
    int res = INT_MIN;
};
int main(){
    TreeNode left(2), right(3);
    TreeNode root(1, &left, &right);
    cout << Solution().maxPathSum(&root);
    return EXIT_SUCCESS;
}