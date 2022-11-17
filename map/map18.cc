#include "../common/common.h"
/**
 * @brief 47. 全排列 II
 * https://leetcode.cn/problems/permutations-ii/
 *
 * 1. 之前用过的，可以剪掉枝条 
 * 2. 之前没用过，但是跟上一个元素相同, 也可以剪掉枝条
 **/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        used = vector<bool>(n, false);
        sort(nums.begin(), nums.end());
        deque<int> dq;
        dfs(0, dq, nums);
        return res;
    }
protected:
    void dfs(int i, deque<int>& dq, vector<int>& nums){
        if (i == n){
            vector<int> it(dq.begin(), dq.end());
            res.push_back(it);
            return;
        }
        for (int j = 0; j < n; ++ j){
            if (used[j]){
                continue;
            }
            if (j > 0 && nums[j] == nums[j - 1] && !used[j - 1]){
                continue;
            }
            used[j] = true;
            dq.push_back(nums[j]);
            dfs(i + 1, dq, nums);
            used[j] = false;
            dq.pop_back();
        }
    }
private:
    vector<vector<int>> res;
    vector<bool> used;
    int n;
};
int main(){
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> res = Solution().permuteUnique(nums);
    for (auto& r : res){
        cout << r << endl;
    }
    return EXIT_SUCCESS;
}