#include "../common/common.h"
/**
 * @brief 129. 求根节点到叶节点数字之和
 * https://leetcode.cn/problems/sum-root-to-leaf-numbers/
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        preOrder(root, 0);
        return res;
    }
private:
    void preOrder(TreeNode* root, int now){
        bool f1 = root -> left == nullptr;
        bool f2 = root -> right == nullptr;
        now = now * 10 + root -> val;
        if (f1 && f2){
            res += now;
        }
        if (!f1){
            preOrder(root -> left, now);
        }
        if (!f2){
            preOrder(root -> right, now);
        }
    }
    int res = 0;
};
int main(){
    TreeNode root(1);
    cout << Solution().sumNumbers(&root) << endl;
    return EXIT_SUCCESS;
}