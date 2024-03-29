#include "..//common//common.h"
/**
 * @brief 513. 找树左下角的值
 * https://leetcode.cn/problems/find-bottom-left-tree-value/
 * 
 * 层序遍历
 * @param root 
 * @return int 
 */
int findBottomLeftValue(TreeNode* root);
int main(){
    TreeNode a(2), b(3), root(1, &a, &b);
    cout << findBottomLeftValue(&root) << endl;
    return EXIT_SUCCESS;
}
int findBottomLeftValue(TreeNode* root) {
    TreeNode *pre;
    deque<TreeNode *> dq;
    dq.push_back(root);
    while (!dq.empty()){
        int size = dq.size();
        pre = dq.front();
        for (int i = 0; i < size; ++ i){
            TreeNode *now = dq.front();
            dq.pop_front();
            if (now -> left != nullptr){
                dq.push_back(now -> left);
            }
            if (now -> right != nullptr){
                dq.push_back(now -> right);
            }
        }
    }
    return pre -> val;
}