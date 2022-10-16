#include "../common/common.h"
/**
 * @brief 314. 二叉树的垂直遍历
 * https://leetcode.cn/problems/binary-tree-vertical-order-traversal/
 * 
 * 层序遍历 + 标记从左到右的正确位置
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        index[root] = 0;
        while (!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; ++ i){
                TreeNode* now = q.front();
                int j = index[now];
                if (ma.find(j) == ma.end()){
                    ma[j] = new vector<int>();
                }
                ma[j] -> push_back(now -> val);
                if (now -> left != nullptr){
                    q.push(now -> left);
                    index[now -> left] = j - 1;
                }
                if (now -> right != nullptr){
                    q.push(now -> right);
                    index[now -> right] = j + 1;
                }
                q.pop();
            }
        }
        for (auto& m : ma){
            res.push_back(vector<int>(m.second->begin(), m.second->end()));
        }
        return res;
    }
private:
    map<int, vector<int>*> ma;
    map<TreeNode*, int> index;
};
int main(){
    TreeNode root(1);
    vector<vector<int>> res = Solution().verticalOrder(&root);
    cout << res << endl;
    return EXIT_SUCCESS;
}