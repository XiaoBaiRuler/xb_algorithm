#include "../common/common.h"
/**
 * @brief 111. 二叉树的最小深度
 * https://leetcode.cn/problems/minimum-depth-of-binary-tree/
 * 
 * 递归实现深度优先搜素
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr){
            return 0;
        }
        select(root, 1);
        return res;
    }
private:
    void select(TreeNode* root, int i){
        bool f1 = root -> left != nullptr;
        bool f2 = root -> right != nullptr; 
        if (f1){
            select(root -> left, i + 1);
        }
        if (!f1 && !f2){
            res = min(res, i);
        }
        if (f2){
            select(root -> right, i + 1);
        }
    }
    int res = INT_MAX;
};
int main(){
    cout << Solution().minDepth(nullptr) << endl;
    return EXIT_SUCCESS;
}