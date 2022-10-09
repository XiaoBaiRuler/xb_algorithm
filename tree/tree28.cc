#include "../common/common.h"
/**
 * @brief 1325. 删除给定值的叶子节点
 * https://leetcode.cn/problems/delete-leaves-with-a-given-value/
 * 
 * 从底部向上整合结果
 */
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        t = target;
        return remove(root);
    }
    TreeNode* remove(TreeNode* root){
        if (root == nullptr){
            return nullptr;
        }
        root -> left = remove(root -> left);
        root -> right = remove(root -> right);
        if (root -> left == nullptr && root -> right == nullptr && root -> val == t){
            return nullptr;
        }
        return root;
    }
private:
    int t = 0;
};
int main(){
    TreeNode root(1);
    cout << Solution().removeLeafNodes(&root, 1) << endl;
    return EXIT_SUCCESS;
}