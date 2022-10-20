#include "../common/common.h"
/**
 * @brief 1339. 分裂二叉树的最大乘积
 * https://leetcode.cn/problems/maximum-product-of-splitted-binary-tree/
 * 
 * 自底部向上遍历
 */
class Solution {
public:
    int maxProduct(TreeNode* root) {
        int MAX = count(root);
        long long ma = 0;
        for (auto& m : map){
            long long other = map[m.first];
            long long one = MAX - other;
            ma = max(other * one, ma);
        }
        return static_cast<int>(ma % 1000000007);
    }
private:
    int count(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        int l = count(root -> left);
        int r = count(root -> right);
        map[root] = l + r + root -> val;
        return map[root];
    }
    unordered_map<TreeNode*, int> map;
};
int main(){
    TreeNode a(1), b(2, nullptr, &a);
    cout << Solution().maxProduct(&b) << endl;
    return EXIT_SUCCESS;
}