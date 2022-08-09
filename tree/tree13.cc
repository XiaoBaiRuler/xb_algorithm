#include "..//common//common.h"
/**
 * @brief 919. 完全二叉树插入器
 * https://leetcode.cn/problems/complete-binary-tree-inserter/submissions/
 * 
 * 层序遍历
 */
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        if (root != nullptr){
            q.push(root);
            res = root;
        }
        while (true){
            int n = q.size();
            for (int i = 0; i < n; ++ i){
                TreeNode *now = q.front();
                if (now -> left != nullptr){
                    q.push(now -> left);
                }
                else{
                    return;
                }
                if (now -> right != nullptr){
                    q.push(now -> right);
                    q.pop();
                }
                else{
                    return;
                }
            }
        }
    }
    
    int insert(int val) {
        TreeNode* in = new TreeNode(val);
        if (q.empty()){
            q.push(in);
            res = in;
            return -1;
        }
        TreeNode* now = q.front();
        int r = now -> val;
        if (now -> left == nullptr){
            now -> left = in;
            q.push(in);
        }
        else{
            now -> right = in;
            q.push(in);
            q.pop();
        }
        return r;
    }
    
    TreeNode* get_root() {
        return res;
    }
private:
    queue<TreeNode *> q;
    TreeNode* res;
};
int main(){
    TreeNode root(1);
    CBTInserter cb(&root);
    cout << cb.insert(2) << endl;
    cout << cb.insert(3) << endl;
    cout << cb.get_root() -> val << endl;
    return EXIT_SUCCESS;
}