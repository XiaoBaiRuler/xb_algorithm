#include "../common/common.h"
/**
 * @brief 1631. 最小体力消耗路径
 * https://leetcode.cn/problems/path-with-minimum-effort/
 */
vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        int r = 0;
        for (auto& h : heights){
            for (auto& i : h){
                r = max(i, r);
            }
        }
        int l = 0;
        while (l <= r){
            int mid = l + ((r - l) >> 1);
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            if (dfs(heights, vis, 0, 0, mid)){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
protected:
    bool dfs(vector<vector<int>>& heights, vector<vector<bool>> &vis, int i, int j, int t){
        if (i == n - 1 && j == m - 1){
            return true;
        }
        vis[i][j] = true;
        for (auto& d : dir){
            int x = i + d[0];
            int y = j + d[1];
            if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && t >= abs(heights[i][j] - heights[x][y])){
                if (dfs(heights, vis, x, y, t)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    int n, m;
};
int main(){
    vector<vector<int>> nums = {{1, 2}};
    cout << Solution().minimumEffortPath(nums) << endl;
    return EXIT_SUCCESS;
}