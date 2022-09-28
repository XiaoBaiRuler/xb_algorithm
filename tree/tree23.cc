#include "../common/common.h"
/**
 * @brief 1367. 二叉树中的列表
 * https://leetcode.cn/problems/linked-list-in-binary-tree/
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()){
            TreeNode *now = st.top();
            st.pop();
            if (now -> val == head -> val && check(now, head)){
                return true;
            }
            if (now -> left != nullptr){
                st.push(now -> left);
            }
            if (now -> right != nullptr){
                st.push(now -> right);
            }
        }
        return false;
    }
    bool check(TreeNode *now, ListNode* head){
        if (head == nullptr){
            return true;
        }
        if (now == nullptr){
            return false;
        }
        if (now -> val != head -> val){
            return false;
        }
        head = head -> next;
        if (check(now -> left, head)){
            return true;
        } 
        if (check(now -> right, head)){
            return true;
        }
        return false;  
    }
};
int main(){
    TreeNode *root = new TreeNode(1);
    ListNode *head = new ListNode(1);
    cout << Solution().isSubPath(head, root) << endl;
    return EXIT_SUCCESS;
}