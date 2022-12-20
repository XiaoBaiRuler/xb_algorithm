#include "../common/common.h"
/**
 * @brief 1740. 找到二叉树中的距离
 * https://leetcode.cn/problems/find-distance-in-a-binary-tree/
 */
class Solution {
public:
    int findDistance(TreeNode* root, int p, int q) {
        pp = p;
        unordered_map<TreeNode*, TreeNode*> pre;
        dfs(root, pre);
        deque<TreeNode*> dq;
        dq.push_back(pn);
        unordered_set<int> set;
        set.insert(p);
        int res = 0;
        while (!dq.empty()){
            int n = dq.size();
            for (int i = 0; i < n; ++ i){
                TreeNode* now = dq.front();
                dq.pop_front();
                if (now -> val == q){
                    return res;
                }
                if (now -> left != nullptr && !set.count(now -> left -> val)){
                    dq.push_back(now -> left);
                    set.insert(now -> left -> val);
                }
                if (now -> right != nullptr && !set.count(now -> right -> val)){
                    dq.push_back(now -> right);
                    set.insert(now -> right -> val);
                }
                if (pre.find(now) != pre.end() && !set.count(pre[now] -> val)){
                    dq.push_back(pre[now]);
                    set.insert(pre[now] -> val);
                }
            }
            ++ res;
        }
        return res;
    }
private:
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &pre){
        if (pp == root -> val){
            pn = root;
        }
        if (root -> left != nullptr){
            pre[root -> left] = root;
            dfs(root -> left, pre);
        }
        if (root -> right != nullptr){
            pre[root -> right] = root;
            dfs(root -> right, pre);
        }
    }
private:
    TreeNode *pn = nullptr;
    int pp;
};
int main(){
    TreeNode root(1);
    cout << Solution().findDistance(&root, 1, 1) << endl;
    return EXIT_SUCCESS;
}