#include "../common/common.h"
/**
 * @brief 637. 二叉树的层平均值
 * https://leetcode.cn/problems/average-of-levels-in-binary-tree/
 * 层序遍历
 * @param root 
 * @return vector<double> 
 */
vector<double> averageOfLevels(TreeNode* root);
int main(){
    TreeNode root(1);
    vector<double> res = averageOfLevels(&root);
    cout << res << endl;
    return EXIT_SUCCESS;
}
vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()){
        int n = q.size();
        double ans = 0;
        for (int i = 0; i < n; ++ i){
            TreeNode *now = q.front();
            ans += now -> val;
            q.pop();
            if (now -> left != nullptr){
                q.push(now -> left);
            }
            if (now -> right != nullptr){
                q.push(now -> right);
            }
        }
        res.push_back(ans / n);
    }
    return res;
}