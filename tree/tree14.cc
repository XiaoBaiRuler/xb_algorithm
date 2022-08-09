#include "..//common//common.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**
 * @brief 1161. 最大层内元素和
 * https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/
 * 
 * 层序遍历
 * @param root 
 * @return int 
 */
int maxLevelSum(TreeNode* root);
int main(){
    TreeNode a(1), b(2), c(3, &a, &b);
    cout << maxLevelSum(&c) << endl; 
    return EXIT_SUCCESS;
}
int maxLevelSum(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int res = INT_MIN, j = 1, index = 1;
    while (!q.empty()){
        int n = q.size(), now = 0;
        for (int i = 0; i < n; ++ i){
            TreeNode *next = q.front();
            if (next -> left != nullptr){
                q.push(next -> left);
            }
            if (next -> right != nullptr){
                q.push(next -> right);
            }
            now += next -> val;
            q.pop();
        }
        if (now > res){
            index = j;
            res = now;
        }
        ++ j;
    }
    return index;
}