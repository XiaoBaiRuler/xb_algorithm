#include "..//common//common.h"
/**
 * @brief 450. 删除二叉搜索树中的节点
 * https://leetcode.cn/problems/delete-node-in-a-bst/
 * 
 * 分类讨论
 * 1. 根节点 == key
 * 1.1 是否当前节点有左右子节点
 * 1.2 是否仅有左子节点
 * 1.3 是否仅有右子节点
 * 2. 根节点 != key
 * 2.1. 那么要记录前一个结点的指针，以及前一个结点到右节点是左还是右
 * 2.2. 能够找到节点
 * 2.2.1. 是否当前节点有左右子节点
 * 2.2.2. 是否仅有左子节点
 * 2.2.3. 是否仅有右子节点
 *  
 * @param root 
 * @param key 
 * @return TreeNode* 
 */
TreeNode* deleteNode(TreeNode* root, int key);
int main(){
    TreeNode root(10);
    cout << deleteNode(&root, 10) << endl;
    return EXIT_SUCCESS;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr){
        return nullptr;
    }
    if (root -> val == key){
        if (root -> left != nullptr && root -> right != nullptr){
            TreeNode *now = root -> right, *right = now;
            root = root -> left;
            while (now -> left != nullptr){
                now = now -> left;
            }
            now -> left = root -> right;
            root -> right = right;
            return root;
        }
        else if (root -> left != nullptr){
            return root -> left;
        }
        else if (root -> right != nullptr){
            return root -> right;
        }
        return nullptr;
    }
    TreeNode* pre, *res = root;
    bool flag = true;
    while (root != nullptr){
        if (root -> val == key){
            if (root -> left != nullptr && root -> right != nullptr){
                TreeNode *now = root -> right, *right = now;
                root = root -> left;
                while (now -> left != nullptr){
                    now = now -> left;
                }
                now -> left = root -> right;
                root -> right = right;
            }
            else if (root -> left != nullptr){
                root = root -> left;
            }
            else if (root -> right != nullptr){
                root = root -> right;
            }
            else{
                root = nullptr;
            }
            if (flag){
                pre -> left = root;
            }
            else{
                pre -> right = root;
            }
            return res;
        }
        else if (root -> val > key){
            pre = root;
            flag = true;
            root = root -> left;
        }
        else{
            pre = root;
            flag = false;
            root = root -> right;
        }
    }
    return res;
}