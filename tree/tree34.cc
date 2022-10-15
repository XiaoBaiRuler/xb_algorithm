#include "../common/common.h"
/**
 * @brief 993. 二叉树的堂兄弟节点
 * https://leetcode.cn/problems/cousins-in-binary-tree/
 * 层序遍历
 * @param root 
 * @param x 
 * @param y 
 * @return true 
 * @return false 
 */
bool isCousins(TreeNode* root, int x, int y);
int main(){
    TreeNode a(1), b(2), c(3, &a, &b);
    cout << isCousins(&c, 1, 2) << endl;
    return EXIT_SUCCESS;
}
bool isCousins(TreeNode* root, int x, int y) {
    array<int, 101> map = {0};
    array<int, 101> pre = {0};
    queue<TreeNode*> q;
    q.push(root);
    int c = 0;
    while (!q.empty()){
        int n = q.size();
        for (int i = 0; i < n; ++ i){
            TreeNode* now = q.front();
            q.pop();
            if (now -> left != nullptr){
                q.push(now -> left);
                pre[now -> left -> val] = now -> val;
            }
            if (now -> right != nullptr){
                q.push(now -> right);
                pre[now -> right -> val] = now -> val;
            }
            map[now -> val] = c;
        }
        ++ c;
    }
    return map[x] == map[y] && pre[x] != pre[y];
}