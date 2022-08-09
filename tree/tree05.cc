#include "..//common//common.h"
class Solution {
public:
    /**
     * @brief 1022. 从根到叶的二进制数之和
     * https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/
     * 
     * 前序遍历
     * 
     * @param root 
     * @return int 
     */
    int sumRootToLeaf(TreeNode* root) {
        if (root == nullptr){
            return res;
        }
        sumRoot(root, 0);
        return res;
    }
    void sumRoot(TreeNode* root, int now){
        now = now * 2 + root -> val;
        if (root -> left == nullptr && root -> right == nullptr){
            res += now;
        }
        if (root -> left != nullptr){
            sumRoot(root -> left, now);
        }
        if (root -> right != nullptr){
            sumRoot(root -> right, now);
        }
    }
private:
    int res = 0;
};
int main(){
    Solution s;
    cout << s.sumRootToLeaf(nullptr) << endl;
    return EXIT_SUCCESS;
}