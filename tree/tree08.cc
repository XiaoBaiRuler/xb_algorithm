#define PATH 1
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
int getAll(unordered_map<int, int>& se, TreeNode* root);
/**
 * @brief 508. 出现次数最多的子树元素和
 * https://leetcode.cn/problems/most-frequent-subtree-sum/
 * 
 * 后续遍历
 * 
 * @param root 
 * @return vector<int> 
 */
vector<int> findFrequentTreeSum(TreeNode* root);
int main(){
    TreeNode left(2);
    TreeNode right(3);
    TreeNode root(1, &left, &right);
    vector<int> res = findFrequentTreeSum(&root);
    for (int i : res){
        cout << i << " ";
    } 
    cout << endl;
    return EXIT_SUCCESS;
}
vector<int> findFrequentTreeSum(TreeNode* root) {
    unordered_map<int, int> se;
    getAll(se, root);
    int max = INT_MIN;
    for (auto b = se.begin(), e = se.end(); b != e; ++ b){
        if (b -> second > max){
            max = b -> second;
        }
    }
    vector<int> res;
    for (auto b = se.begin(), e = se.end(); b != e; ++ b){
        if (b -> second == max){
            res.push_back(b -> first);
        }
    }
    return res;
}
int getAll(unordered_map<int, int>& se, TreeNode* root){
    if (root -> left == nullptr && root -> right == nullptr){
        se[root -> val] ++;
        return root -> val;
    }
    else if (root -> left == nullptr){
        int now = getAll(se, root -> right) + root -> val;
        se[now] ++;
        return now;
    }
    else if (root -> right == nullptr){
        int now = getAll(se, root -> left) + root -> val;
        se[now] ++;
        return now;
    }
    else{
        int now = getAll(se, root -> right) + getAll(se, root -> left) + root -> val;
        se[now] ++;
        return now;
    }
}