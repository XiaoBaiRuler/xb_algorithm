#include "..//common//common.h"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 * @brief 面试题 04.06. 后继者
 * https://leetcode.cn/problems/successor-lcci/
 * 
 * 二叉搜索树的查找，类似二分(logN)
 * 
 * @param root 
 * @param p 
 * @return TreeNode* 
 */
TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p);

int main(){
    TreeNode a(1), b(2), c(3);
    b.left = &a;
    b.right = &b;
    cout << inorderSuccessor(&b, &a) -> val << endl;
    return EXIT_SUCCESS;
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* res = NULL;
    while (root != NULL){
        if (root -> val > p -> val){
            if (res == NULL){
                res = root;
            }
            else if (root -> val < res -> val){
                res = root;
            }
            root = root -> left;
        }
        else{
            root = root -> right;
        }
    }
    return res;
}