#include "..//common//common.h"
/**
 * @brief 1305. 两棵二叉搜索树中的所有元素
 * https://leetcode-cn.com/problems/all-elements-in-two-binary-search-trees/
 * 
 * 中序遍历和归并排序
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        queue<int> res1;
        queue<int> res2;
        mid(root1, res1);
        mid(root2, res2);
        vector<int> res;
        while (!res1.empty() && !res2.empty()){
            if (res1.front() > res2.front()){
                res.push_back(res2.front());
                res2.pop();
            }
            else{
                res.push_back(res1.front());
                res1.pop();
            }
        }
        while (!res1.empty()){
            res.push_back(res1.front());
            res1.pop();
        }
        while (!res2.empty()){
            res.push_back(res2.front());
            res2.pop();
        }
        return res;
    }
    /**
     * @brief 借助栈来模拟中序遍历
     * 
     * @param root 
     * @param res 
     */
    void mid(TreeNode* root, queue<int>& res){
        stack<TreeNode*> st;
        if (root != nullptr){
           st.push(root);
        }
        while (!st.empty()){
            while (root != nullptr && root -> left != nullptr){
                st.push(root -> left);
                root = root -> left;
            }
            res.push(st.top() -> val);
            root = st.top();
            st.pop();
            if (root -> right != nullptr){
                st.push(root -> right);
                root = root -> right;
            }
            else{
                root = nullptr;
            }
        }
    }
};
int main(){
    Solution s;
    return EXIT_SUCCESS;
}