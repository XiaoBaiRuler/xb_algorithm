#include "../common/common.h"
/**
 * @brief 90. 子集 II
 * https://leetcode.cn/problems/subsets-ii/
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        m = nums.size();
        used = vector<bool>(m, false);
        sort(nums.begin(), nums.end());
        deque<int> dq;
        dfs(dq, nums);
        return res;
    }
protected:
    void dfs(deque<int>& dq, vector<int>& nums){
        if (dq.size() == m){
            vector<int> ans;
            for (int c : dq){
                ans.push_back(nums[c]);
            }
            res.push_back(ans);
            return;
        }
        vector<int> ans;
        for (int c : dq){
            ans.push_back(nums[c]);
        }
        res.push_back(ans);
        for (int i = dq.empty() ? 0 : dq.back(); i < m; ++ i){
            if (used[i]){
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]){
                continue;
            }
            dq.push_back(i);
            used[i] = true;
            dfs(dq, nums);
            used[i] = false;
            dq.pop_back();
        }
    }
private:
    int m;
    vector<bool> used;
    vector<vector<int>> res;
};
int main(){
    vector<int> nums = {1,2,2};
    vector<vector<int>> res = Solution().subsetsWithDup(nums);
    for (auto& r : res){
        cout << r << endl;
    }
    return EXIT_SUCCESS;
}