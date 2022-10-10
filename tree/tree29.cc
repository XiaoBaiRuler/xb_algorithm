#include "../common/common.h"
/**
 * @brief 652. 寻找重复的子树
 * https://leetcode.cn/problems/find-duplicate-subtrees/
 * 
 * 自底部向上构造每个节点的序列
 */
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        getStr(root);
        vector<TreeNode*> res;
        for (auto& m : map){
            if (m.second != nullptr){
                res.push_back(m.second);
            }
        }
        return res;
    }
    string getStr(TreeNode* root){
        if (root == nullptr){
            return "#";
        }
        string l = getStr(root -> left);
        string r = getStr(root -> right);
        string res = l + "," + r  + "," + to_string(root -> val);
        if (map.find(res) != map.end()){
            map[res] = root;
        }
        else{
            map[res] = nullptr;
        }
        return res;
    }
private:
    unordered_map<string, TreeNode*> map;
};
int main(){
    TreeNode root(1);
    vector<TreeNode*> res = Solution().findDuplicateSubtrees(&root);
    cout << res << endl; 
    return EXIT_SUCCESS;
}