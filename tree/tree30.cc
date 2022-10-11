#include "../common/common.h"
/**
 * @brief 1372. 二叉树中的最长交错路径
 * https://leetcode.cn/problems/longest-zigzag-path-in-a-binary-tree/
 * 
 * 自底部向上整合结果, 统计符合的最长节点个数 - 1
 */
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        get(root -> left, true);
        get(root -> right, false);
        return res;
    }
    int get(TreeNode* root, bool f){
        if (root == nullptr){
            return 0;
        }
        int l = get(root -> left, true);
        int r = get(root -> right, false);
        int ans = f ? r + 1 : l + 1;
        res = max(ans, res);
        return ans;
    }
private:
    int res = 0;
};
int main(){
    TreeNode root(1);
    cout << Solution().longestZigZag(&root) << endl;
    return EXIT_SUCCESS;
}