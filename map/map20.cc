#include "../common/common.h"
/**
 * @brief 40. 组合总和 II
 * https://leetcode.cn/problems/combination-sum-ii/
 * 
 * 1. candidates 中的每个数字在每个组合中只能使用 一次
 * 2. 中所有可以使数字和为 target 的组合
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        t = target;
        m = candidates.size();
        used = vector<bool>(m, false);
        sort(candidates.begin(), candidates.end());
        deque<int> dq;
        dfs(0, dq, candidates);
        return res;
    }
protected:
    void dfs(int now, deque<int>& dq, vector<int>& candidates){
        if (now > t){
            return;
        }
        if (now == t){
            vector<int> ans;
            for (int c : dq){
                ans.push_back(candidates[c]);
            }
            res.push_back(ans);
            return;
        }
        if (dq.size() == m){
            return;
        }
        for (int i = dq.empty() ? 0 : dq.back(); i < m; ++ i){
            if (used[i]){
                continue;
            }
            if (i > 0 && candidates[i] == candidates[i - 1] && !used[i - 1]){
                continue;
            }
            used[i] = true;
            dq.push_back(i);
            dfs(now + candidates[i], dq, candidates);
            dq.pop_back();
            used[i] = false;    
        }
    }
private:
    int m, t;
    vector<bool> used;
    vector<vector<int>> res;
};
int main(){
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> res = Solution().combinationSum2(nums, 8);
    for (auto& r : res){
        cout << r << endl;
    }
    return EXIT_SUCCESS;
}