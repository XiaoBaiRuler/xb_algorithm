#include "../common/common.h"
/**
 * @brief 1102. 得分最高的路径
 * https://leetcode.cn/problems/path-with-maximum-minimum-value/
 * 
 * 二分 + dfs
 */
vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ma = min(grid[0][0], grid[n - 1][m - 1]);
        vector<int> nums;
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
               if (grid[i][j] <= ma){
                   nums.push_back(grid[i][j]);
               } 
            }         
        }
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        while (l <= r){
            vector<vector<bool>> vis(n, vector<bool>(m, false));
            int mid = l + (r - l) / 2;
            t = nums[mid];
            if (dfs(grid, vis, 0, 0)){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return nums[r];
    }
protected:
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j){
        if (i == n - 1 && j == m - 1){
            return true;
        }
        vis[i][j] = true;
        for (auto& d : dir){
            int x = i + d[0];
            int y = j + d[1];
            if (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && t <= grid[x][y]){
                if (dfs(grid, vis, x, y)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    int n, m, t;
};
int main(){
    vector<vector<int>> grid = {
        {5, 4, 5},
        {1, 2, 6},
        {7, 4, 6}
    };
    cout << Solution().maximumMinimumPath(grid) << endl;
    return EXIT_SUCCESS;
}