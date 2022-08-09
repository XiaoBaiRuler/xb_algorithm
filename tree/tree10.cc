#include "..//common//common.h"
/**
 * @brief 515. 在每个树行中找最大值
 * https://leetcode.cn/problems/find-largest-value-in-each-tree-row/
 * 
 * 层序遍历
 * @param root 
 * @return vector<int> 
 */
vector<int> largestValues(TreeNode* root);
int main(){
    TreeNode a(2), b(3), root(1, &a, &b);
    vector<int> res = largestValues(&root);
    for (int c : res){
        cout << c << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
vector<int> largestValues(TreeNode* root) {
    vector<int> res;
    if (root == nullptr){
        return res;
    }
    deque<TreeNode *> de;
    de.push_back(root);
    while (!de.empty()){
        int n = de.size(), max = INT_MIN;
        for (int i = 0; i < n; ++ i){
            TreeNode *now = de.front();
            de.pop_front();
            if (now -> val > max){
                max = now -> val;
            }
            if (now -> left != nullptr){
                de.push_back(now -> left);
            }
            if (now -> right != nullptr){
                de.push_back(now -> right);
            }
        }
        res.push_back(max);
    }
    return res;
}