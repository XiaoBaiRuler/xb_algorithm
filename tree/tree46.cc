#include "../common/common.h"
/**
 * @brief 337. 打家劫舍 III
 * https://leetcode.cn/problems/house-robber-iii/
 * 
 * 树型动态规划
 */
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = select(root);
        return max(res[0], res[1]);
    }
private:
    vector<int> select(TreeNode* root){
        vector<int> res(2);
        if (root == nullptr){
            res[0] = 0;
            res[1] = 0;
            return res;
        }
        vector<int> l = select(root -> left);
        vector<int> r = select(root -> right);
        // 1. 当前不取
        // 1.1. 前一个都取或都不取
        int a = max(l[1] + r[1], l[0] + r[0]);
        // 1.2. 前一个单个取
        int b = max(l[0] + r[1], l[1] + r[0]);
        res[0] = max(a, b);
        // 2. 当前取, 之前肯定不给取了
        res[1] = root -> val + l[0] + r[0];
        return res;
    }
};
int main(){
    TreeNode a(1), b(4), root(3, &a, &b);
    cout << Solution().rob(&root) << endl;
    return EXIT_SUCCESS;
}