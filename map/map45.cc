#include "../common/common.h"
/**
 * @brief 剑指 Offer II 046. 二叉树的右侧视图
 * https://leetcode.cn/problems/WNC0Lk/
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr){
            return res;
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        while (!dq.empty()){
            int n = dq.size();
            TreeNode* now;
            for (int i = 0; i < n; ++ i){
                now = dq.front();
                dq.pop_front();
                if (now -> left != nullptr){
                    dq.push_back(now -> left);
                }
                if (now -> right != nullptr){
                    dq.push_back(now -> right);
                }
            }
            res.push_back(now -> val);
        }
        return res;
    }
};
int main(){
    TreeNode root(1);
    vector<int> res = Solution().rightSideView(&root);
    cout << res << endl;
    return EXIT_SUCCESS;
}