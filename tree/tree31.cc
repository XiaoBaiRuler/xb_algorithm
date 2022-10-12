#include "../common/common.h"
/**
 * @brief 1373. 二叉搜索子树的最大键值和
 * https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/
 * 
 * 统计每个节点下属的节点(最小值和最大值)
 * - 当前节点比左节点的最大值还大
 * - 当前节点比右节点的最小值还小
 */
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        sum(root);
        return res;
    }
    vector<int> sum(TreeNode* root){
        vector<int> ves(3);
        if (root == nullptr){
            ves[0] = INT_MAX;
            // 最大值(left)
            ves[1] = INT_MIN;
            // 最小值(right)
            ves[2] = INT_MAX;
            return ves;
        }
        vector<int> l = sum(root -> left);
        vector<int> r = sum(root -> right);
        if (l[0] == INT_MIN || r[0] == INT_MIN){
            ves[0] = INT_MIN;
            return ves;
        }
        if (l[0] != INT_MAX && root -> val <= l[1]){
            ves[0] = INT_MIN;
            return ves;
        }
        if (r[0] != INT_MAX && root -> val >= r[2]){
            ves[0] = INT_MIN;
            return ves;
        }
        int ll = l[0] == INT_MAX ? 0 : l[0];
        int rr = r[0] == INT_MAX ? 0 : r[0];
        int ans = ll + rr + root -> val;
        res = max(ans, res);
        ves[0] = ans;
        ves[1] = max(r[1], root -> val);
        ves[2] = min(l[2], root -> val);
        return ves;
    }
private:
    int res = 0;
};
int main(){
    TreeNode root(1);
    cout << Solution().maxSumBST(&root) << endl;
    return EXIT_SUCCESS;
}