#include "../common/common.h"
/**
 * @brief 剑指 Offer II 045. 二叉树最底层最左边的值
 * https://leetcode.cn/problems/LwUNpT/
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        deque<TreeNode*> dq;
        dq.push_back(root);
        TreeNode* res;
        while (!dq.empty()){
            int n = dq.size();
            res = dq.front();
            for (int i = 0; i < n; ++ i){
                TreeNode* now = dq.front();
                dq.pop_front();
                if (now -> left != nullptr){
                    dq.push_back(now -> left);
                }
                if (now -> right != nullptr){
                    dq.push_back(now -> right);
                }
            }
        }
        return res -> val;
    }
};
int main(){
    TreeNode root(1);
    cout << Solution().findBottomLeftValue(&root) << endl;
    return EXIT_SUCCESS;
}