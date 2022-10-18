#include "../common/common.h"
/**
 * @brief 655. 输出二叉树
 * https://leetcode.cn/problems/print-binary-tree/
 * 层序遍历
 */
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int m = count(root), j = 0, c = int(pow(2, m)) - 1;    
        vector<vector<string>> res(m, vector<string>(c));
        queue<TreeNode*> q;
        q.push(root);
        map[root] = c / 2;
        while (!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; ++ i){
                TreeNode* now = q.front();
                res[j][map[now]] = to_string(now -> val);
                int k = pow(2, m - 1 - j - 1);
                if (now -> left != nullptr){
                    q.push(now -> left);
                    map[now -> left] = map[now] - k;
                }
                if (now -> right != nullptr){
                    q.push(now -> right);
                    map[now -> right] = map[now] + k;
                }
                q.pop();
            }
            ++ j;
        }
        return res;
    }
    int count(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; ++ i){
                TreeNode* now = q.front();
                if (now -> left != nullptr){
                    q.push(now -> left);
                }
                if (now -> right != nullptr){
                    q.push(now -> right);
                }
                q.pop();
            } 
            ++ res;
        }
        return res;
    }
private:
    unordered_map<TreeNode*, int> map;
};
int main(){
    TreeNode root(1);
    vector<vector<string>> res = Solution().printTree(&root);
    cout << res << endl;
    return EXIT_SUCCESS;
}