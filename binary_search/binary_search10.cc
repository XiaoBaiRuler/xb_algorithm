#include "../common/common.h"
class Solution {
    vector<double> res;
public:
    /**
     * @brief 270. 最接近的二叉搜索树值
     * https://leetcode.cn/problems/closest-binary-search-tree-value/
     * 
     * 1. 中序遍历 - 获取排序的列表
     * 2. 二分法找出刚好大于它的值，答案就在附近
     * 
     * O(n) + log(n)
     * @param root 
     * @param target 
     * @return int 
     */
    int closestValue(TreeNode* root, double target) {
        mid_search(root);
        int i = findBig(target);
        int l = i == 0 ? res[i] : res[i - 1];
        int r = res[i];
        return r - target > target - l ? l : r;   
    }
    void mid_search(TreeNode* root){
        if (root -> left != nullptr){
            mid_search(root -> left);
        }
        res.push_back(root -> val);
        if (root -> right != nullptr){
            mid_search(root -> right);
        }
    }
    int findBig(double target){
        if (res[0] >= target){
            return 0;
        }
        int n = res.size(), l = 0, r = n - 1;
        while (l <= r){
            int mid = l + ((r - l) >> 1);
            if (res[mid] >= target && res[mid - 1] < target){
                return mid;
            }
            else if (res[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return r;
    }
};
int main(){
    TreeNode root(1);
    Solution s;
    cout << s.closestValue(&root, 1) << endl;
    return EXIT_SUCCESS;
}