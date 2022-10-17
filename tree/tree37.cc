#include "../common/common.h"
/**
 * @brief 199. 二叉树的右视图
 * https://leetcode.cn/problems/binary-tree-right-side-view/
 * 
 * 层序遍历
 * @param root 
 * @return vector<int> 
 */
vector<int> rightSideView(TreeNode* root);
int main(){
    TreeNode root(1);
    vector<int> res = rightSideView(&root);
    cout << res << endl;
    return EXIT_SUCCESS;
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (root == nullptr){
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        int n = q.size();
        TreeNode* now = nullptr;
        for (int i = 0; i < n; ++ i){
            now = q.front();
            if (now -> left != nullptr){
                q.push(now -> left);
            }
            if (now -> right != nullptr){
                q.push(now -> right);
            }
            q.pop();
        }
        res.push_back(now -> val);
    }
    return res;
}