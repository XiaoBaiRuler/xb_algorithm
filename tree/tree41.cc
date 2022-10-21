#include "../common/common.h"
/**
 * @brief 863. 二叉树中所有距离为 K 的结点
 * https://leetcode.cn/problems/all-nodes-distance-k-in-binary-tree/
 * 
 * 前缀树 + dfs
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        select(root);
        vector<int> res;
        dfs(res, target, k);
        return res;
    }
    void dfs(vector<int>& res, TreeNode* root, int k){
        if (hash.count(root -> val)){
            return;
        }
        hash.insert(root -> val);
        if (k == 0){
            res.push_back(root -> val);
            return;
        }
        if (pre.find(root) != pre.end()){
            dfs(res, pre[root], k - 1);
        }
        if (root -> left != nullptr){
            dfs(res, root -> left, k - 1);
        }
        if (root -> right != nullptr){
            dfs(res, root -> right, k - 1);
        }
    }
private:
    void select(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* now = q.front();
            if (now -> left != nullptr){
                pre[now -> left] = now;
                q.push(now -> left);
            }
            if (now -> right != nullptr){
                pre[now -> right] = now;
                q.push(now -> right);
            }
            q.pop();
        }
    }
    unordered_map<TreeNode*, TreeNode*> pre;
    unordered_set<int> hash;
};
int main(){
    TreeNode root(1);
    vector<int> res = Solution().distanceK(&root, &root, 1);
    cout << res << endl;
    return EXIT_SUCCESS;
}