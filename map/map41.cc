#include "../common/common.h"
/**
 * @brief 1448. 统计二叉树中好节点的数目
 * https://leetcode.cn/problems/count-good-nodes-in-binary-tree/
 * 
 * dfs
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        dfs(root, root -> val);
        return res;
    }
protected:
    void dfs(TreeNode* root, int now){
        if (root -> val >= now){
            ++ res;
        }
        int next = root -> val > now ? root -> val : now;
        if (root -> left != nullptr){
            dfs(root -> left, next);
        }
        if (root -> right != nullptr){
            dfs(root -> right, next);
        }
    }
private:
    int res = 0;
};
int main(){
    TreeNode root(1);
    cout << Solution().goodNodes(&root) << endl;
    return EXIT_SUCCESS;
}