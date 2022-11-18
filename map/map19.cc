#include "../common/common.h"
/**
 * @brief 77. 组合
 * https://leetcode.cn/problems/combinations/
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        m = n + 1;
        a = k;
        used = vector<bool>(m, false);
        deque<int> dq;
        dfs(0, dq);
        return res;
    }
protected:
    void dfs(int i, deque<int>& dq){
        if (i == a){
            res.emplace_back(dq.begin(), dq.end());
            return;
        }
        for (int j = (i == 0) ? 1 : dq[i - 1] + 1; j < m; ++ j){
            if (!used[j]){
                dq.push_back(j);
                used[j] = true;
                dfs(i + 1, dq);
                used[j] = false;
                dq.pop_back();
            }
        }
    }
private:
    int m, a;
    vector<bool> used;
    vector<vector<int>> res;
};
int main(){
    vector<vector<int>> res = Solution().combine(4, 2);
    for (auto& r : res){
        cout << r << endl;
    }
    return EXIT_SUCCESS;
}