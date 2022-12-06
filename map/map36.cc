#include "../common/common.h"
/**
 * @brief 剑指 Offer 32 - III. 从上到下打印二叉树 III
 * https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr){
            return res;
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool f = false;
        while (!dq.empty()){
            int n = dq.size();
            vector<int> ans;
            for (int i = 0; i < n; ++ i){
                TreeNode* now = dq.front();
                ans.push_back(now -> val);
                dq.pop_front();
                if (now -> left != nullptr){
                    dq.push_back(now -> left);
                }
                if (now -> right != nullptr){
                    dq.push_back(now -> right);
                }
            }
            if (f){
                reverse(ans.begin(), ans.end());
            }
            res.push_back(ans);
            f = !f;
        }
        return res;
    }
};
int main(){
    TreeNode* root = new TreeNode(1);
    vector<vector<int>> res = Solution().levelOrder(root);
    for (auto& r : res){
        cout << r << endl;
    }
    return EXIT_SUCCESS;
}