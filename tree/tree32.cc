#include "../common/common.h"
/**
 * @brief 968. 监控二叉树
 * https://leetcode.cn/problems/binary-tree-cameras/submissions/
 * 
 * 0: 不用管我
 * 1: 我有人管了
 * 2: 我需要人管
 */
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int i = make(root);
        return i == 2 ? res + 1 : res;
    }
    int make(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        int l = make(root -> left);
        int r = make(root -> right);
        if (l == 0 && r == 0){
            return 2;
        }
        if (l == 2 || r == 2){
            res += 1;
            return 1;
        }
        return 0;
    }
private:
    int res = 0;
};
int main(){
    TreeNode root(0);
    cout << Solution().minCameraCover(&root) << endl;
    return EXIT_SUCCESS;
}