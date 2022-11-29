#include "../common/common.h"
/**
 * @brief 549. 二叉树中最长的连续序列
 * https://leetcode.cn/problems/binary-tree-longest-consecutive-sequence-ii/
 * 
 * 当前节点(增序, 降序)
 */
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return res;
    }
protected:
    vector<int> dfs(TreeNode* root){
        vector<int> rv = {1, 1};
        if (root -> left != nullptr){
            int fl = root -> left -> val - root -> val;
            vector<int> ll = dfs(root -> left);
            if (fl == -1){
                rv[0] = max(rv[0], ll[0] + 1);
            }
            else if (fl == 1){
                rv[1] = max(rv[1], ll[1] + 1);
            }
        }
        if (root -> right != nullptr){
            int fr = root -> right -> val - root -> val;
            vector<int> rr = dfs(root -> right);
            if (fr == -1){
                rv[0] = max(rv[0], rr[0] + 1);
            }
            else if (fr == 1){
                rv[1] = max(rv[1], rr[1] + 1);
            }
        }
        res = max(rv[0] + rv[1] - 1, res);
        return rv;
    }
private:
    int res = 0;
};
int main(){
    TreeNode root(1);
    cout << Solution().longestConsecutive(&root) << endl;
    return EXIT_SUCCESS;
}