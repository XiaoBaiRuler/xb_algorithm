#include "../common/common.h"
/**
 * @brief 1008. 前序遍历构造二叉搜索树
 * https://leetcode.cn/problems/construct-binary-search-tree-from-preorder-traversal/
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return create(preorder, 0, preorder.size() - 1);
    }
    TreeNode* create(vector<int>& preorder, int l, int r){
        if (l > r){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[l]);
        int i = l + 1;
        for (; i <= r; ++ i){
            if (preorder[i] > preorder[l]){
                break;
            }
        }
        root -> left = create(preorder, l + 1, i - 1);
        root -> right = create(preorder, i, r);
        return root;
    }
};
int main(){
    vector<int> nums = {8,5,1,7,10,12};
    cout << Solution().bstFromPreorder(nums) -> val << endl;
    return EXIT_SUCCESS;
}