#include "../common/common.h"
/**
 * @brief 1028. 从先序遍历还原二叉树
 * https://leetcode.cn/problems/recover-a-tree-from-preorder-traversal/
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.size();
        int i = 0, c = 0;
        stack<TreeNode*> st;

        int now = toNumber(i, traversal);
        TreeNode* root = new TreeNode(now);
        map[root] = c;
        st.push(root);
        while (i < n){
            if (traversal[i] == '-'){
                ++ c;
                ++ i;
            }
            else{
                int next = toNumber(i, traversal);
                TreeNode *node = new TreeNode(next);
                map[node] = c;
                while (map[st.top()] != c - 1){
                    st.pop();
                }
                if (st.top() -> left == nullptr){
                    st.top() -> left = node;
                }
                else {
                    st.top() -> right = node;
                }
                c = 0;
                st.push(node);
            }
        }
        return root;
    }
protected:
    int toNumber(int& i, string& traversal){
        int ans = 0;
        for (; i < n && isdigit(traversal[i]); ++ i){
            ans = ans * 10 + (traversal[i] - '0');
        }
        return ans;
    }
private:
    unordered_map<TreeNode*, int> map;
    int n;
};
int main(){
    TreeNode* root = Solution().recoverFromPreorder("1-2--3--4-5--6--7");
    cout << root -> val << endl;
    return EXIT_FAILURE;
}