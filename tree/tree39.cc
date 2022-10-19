#include "../common/common.h"
/**
 * @brief 865. 具有所有最深节点的最小子树
 * https://leetcode.cn/problems/smallest-subtree-with-all-the-deepest-nodes/
 * 
 * 层序遍历 + 前缀树
 * @param root 
 * @return TreeNode* 
 */
TreeNode* subtreeWithAllDeepest(TreeNode* root);
int main(){
    TreeNode root(1);
    TreeNode* res = subtreeWithAllDeepest(&root);
    cout << (res == (&root)) << endl;
    return EXIT_SUCCESS;
}
TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    unordered_map<TreeNode*, TreeNode*> pre;
    pre[root] = nullptr;
    int m = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        ++ m;
        int n = q.size();
        for (int i = 0; i < n; ++ i){
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
    q.push(root);
    int j = 0;
    TreeNode* res;
    vector<TreeNode*> ans(m + 1, nullptr);
    while (!q.empty()){
        ++ j;
        int n = q.size(), f = 1;
        for (int i = 0; i < n; ++ i){
            TreeNode* now = q.front();
            if (j == m){
                TreeNode* head = now;
                int l = 0;
                res = head;
                while (head != nullptr){
                    if (head == ans[l]){
                        res = head;
                        break;
                    }
                    else if (f){
                        ans[l] = head;
                    }
                    ++ l;
                    head = pre[head];
                }
                f = 0;
            }
            if (now -> left != nullptr){
                q.push(now -> left);
            }
            if (now -> right != nullptr){
                q.push(now -> right);
            }
            q.pop();
        }
    }
    return res;
}