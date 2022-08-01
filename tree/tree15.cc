#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**
 * @brief 235. 二叉搜索树的最近公共祖先
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * 
 * 二叉搜素树特性的使用
 * @param root 
 * @param p 
 * @param q 
 * @return TreeNode* 
 */
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
int main(){
    TreeNode a(1), b(4), c(3, &a, &b);
    TreeNode* res = lowestCommonAncestor(&c, &a, &b);
    cout << res -> val << endl;
    return EXIT_SUCCESS;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* now = root;
    vector<int> res;
    while (now != nullptr){
        res.push_back(now -> val);
        if (now -> val == p -> val){
            break;
        }
        else if (now -> val > p -> val){
            now = now -> left;
        }
        else{
            now = now -> right;
        }
    }
    now = root;
    int i = 0, n = res.size();
    while (root != nullptr){
        if (i < n && root -> val == res[i]){
            ++ i;
        }
        else{
            return now;
        }
        if (root -> val == q -> val){
            break;
        }
        else if (root -> val > q -> val){
            now = root;
            root = root -> left;
        }
        else{
            now = root;
            root = root -> right;
        }
    }
    return root;
}