#include "..//common//common.h"
/**
 * @brief 623. 在二叉树中增加一行
 * https://leetcode.cn/problems/add-one-row-to-tree/
 * 
 * 层序遍历
 * @param root 
 * @param val 
 * @param depth 
 * @return TreeNode* 
 */
TreeNode* addOneRow(TreeNode* root, int val, int depth);
int main(){
    TreeNode root(1);
    cout << addOneRow(&root, 3, 1) -> left -> val << endl;
    return EXIT_SUCCESS;
}
TreeNode* addOneRow(TreeNode* root, int val, int depth) {
    if (depth == 1){
        TreeNode* now = new TreeNode(val);
        now -> left = root;
        return now;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty() && depth > 2){
        int n = q.size();
        for (int i = 0; i < n; ++ i){
            TreeNode *pre = q.front();
            q.pop();
            if (pre -> left != nullptr){
                q.push(pre -> left);
            }
            if (pre -> right != nullptr){
                q.push(pre -> right);
            }
        }
        depth -= 1;
    }
    int n = q.size();
    for (int i = 0; i < n; ++ i){
        TreeNode *now = q.front();
        TreeNode *l = now -> left;
        TreeNode *r = now -> right;
        now -> left = new TreeNode(val);
        now -> right = new TreeNode(val);
        now -> left -> left = l;
        now -> right -> right = r;
        q.pop();
    }
    return root;
}