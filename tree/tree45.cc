#include "../common/common.h"
/**
 * @brief 333. 最大 BST 子树
 * https://leetcode.cn/problems/largest-bst-subtree/
 * 
 */
class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        sum(root);
        return res;
    }
private:
    vector<int> sum(TreeNode* root){
        vector<int> ves(4);
        if (root == nullptr){
            ves[0] = INT_MAX;
            // 最大值(left)
            ves[1] = INT_MIN;
            // 最小值(right)
            ves[2] = INT_MAX;
            ves[3] = 0;
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
        int ans = l[3] + r[3] + 1;
        res = max(ans, res);
        ves[0] = ans;
        ves[1] = max(r[1], root -> val);
        ves[2] = min(l[2], root -> val);
        ves[3] = ans;
        return ves;
    }
    int res = 0;
};
int main(){
    TreeNode a(1), b(3), root(2, &a, &b);
    cout << Solution().largestBSTSubtree(&root) << endl;
    return EXIT_SUCCESS;
}