#include "../common/common.h"
/**
 * @brief 100. 相同的树
 * https://leetcode.cn/problems/same-tree/
 * 
 * 递归查询
 * @param p 
 * @param q 
 * @return true 
 * @return false 
 */
bool isSameTree(TreeNode* p, TreeNode* q);
int main(){
    TreeNode *p = new TreeNode(1);
    cout << isSameTree(p, nullptr) << endl;
    return EXIT_SUCCESS;
}
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr || q == nullptr){
        return p == q;
    }
    if (p -> val != q -> val){
        return false;
    }
    if (!isSameTree(p -> left, q -> left)){
        return false;
    }
    return isSameTree(p -> right, q -> right);
}