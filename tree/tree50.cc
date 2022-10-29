#include "../common/common.h"
/**
 * @brief 1123. 最深叶节点的最近公共祖先
 * https://leetcode.cn/problems/lowest-common-ancestor-of-deepest-leaves/
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        list<TreeNode*> q;
        q.push_back(root);
        int n = 0;
        while (true){
            n = q.size();
            auto b = q.begin();
            for (int i = 0; i < n; ++ i, ++ b){
                TreeNode* now = *b;
                if (now -> left != nullptr){
                    q.push_back(now -> left);
                }
                if (now -> right != nullptr){
                    q.push_back(now -> right);
                }
            }
            if (n == q.size()){
                break;
            }
            while (n > 0){
                q.pop_front();
                -- n;
            }
        }
        select(root);
        int c = 1;
        unordered_map<TreeNode*, int> top;
        TreeNode* now = *(q.begin()), *res = now;
        while (pre.find(now) != pre.end()){
            top[now] = c ++; 
            now = pre[now];
        }
        top[now] = c;
        q.pop_front();
        int ans = 1;
        for (auto e = q.end(), b = q.begin(); b != e; ++ b){
            now = *b;
            while (top.find(now) == top.end()){
                now = pre[now];
            }   
            if (top[now] > ans){
                ans = top[now];
                res = now;
            }
        }
        return res;
    }
private:
    void select(TreeNode* root){
        if (root -> left != nullptr){
            pre[root -> left] = root;
            select(root -> left);
        }
        if (root -> right != nullptr){
            pre[root -> right] = root;
            select(root -> right);
        }
    }
    unordered_map<TreeNode*, TreeNode*> pre;
};
int main(){
    TreeNode now(1);
    cout << Solution().lcaDeepestLeaves(&now) -> val << endl;
    return EXIT_SUCCESS;
}