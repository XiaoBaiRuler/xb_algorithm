#include "../common/common.h"
/**
 * @brief 1302. 层数最深叶子节点的和
 * https://leetcode.cn/problems/deepest-leaves-sum/
 */
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        deque<TreeNode*> dq;
        dq.push_back(root);
        int ans;
        while (!dq.empty()){
            ans = 0;
            int n = dq.size();
            for (int i = 0; i < n; ++ i){
                TreeNode* now = dq.front();
                ans += now -> val;
                dq.pop_front();
                if (now -> left != nullptr){
                    dq.push_back(now -> left);
                }
                if (now -> right != nullptr){
                    dq.push_back(now -> right);
                }
            }
        }
        return ans;
    }
};
int main(){
    TreeNode root(1);
    cout << Solution().deepestLeavesSum(&root) << endl;
    return EXIT_SUCCESS;
}