#include "../common/common.h"
/**
 * @brief 987. 二叉树的垂序遍历
 * https://leetcode.cn/problems/vertical-order-traversal-of-a-binary-tree/
 * 
 * 层序遍历 + 标记从左到右的正确位置 + 排序对应列的元素(升序)
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        index[root] = 0;
        while (!q.empty()){
            int n = q.size();
            unordered_map<int, vector<int>*> in;
            for (int i = 0; i < n; ++ i){
                TreeNode* now = q.front();
                int j = index[now];
                if (in.find(j) == in.end()){
                    in[j] = new vector<int>();
                }
                in[j] -> push_back(now -> val);
                if (now -> left != nullptr){
                    q.push(now -> left);
                    index[now -> left] = j - 1;
                }
                if (now -> right != nullptr){
                    q.push(now -> right);
                    index[now -> right] = j + 1;
                }
                q.pop();
            }
            for (auto &m : in){
                sort(m.second->begin(), m.second->end());
                if (ma.find(m.first) == ma.end()){
                    ma[m.first] = m.second;
                }
                else{
                    for (int i : (*m.second)){
                        ma[m.first] -> push_back(i);
                    }
                }
            }
        }
        for (auto& m : ma){
            res.push_back(vector<int>(m.second->begin(), m.second->end()));
        }
        return res;
    }
private:
    map<int, vector<int>*> ma;
    map<TreeNode*, int> index;
};
int main(){
    TreeNode b(2), c(3), root(1, &b, &c);
    vector<vector<int>> res = Solution().verticalTraversal(&root);
    cout << res << endl;
    return EXIT_SUCCESS;
}