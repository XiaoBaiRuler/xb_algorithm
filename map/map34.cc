#include "../common/common.h"
/**
 * @brief 778. 水位上升的泳池中游泳
 * https://leetcode.cn/problems/swim-in-rising-water/
 */
vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int r = INT_MIN, l = grid[0][0];
        for (auto& g : grid){
            for (auto& i : g){
                r = max(r, i);
            }
        }
        while (l <= r){
            int mid = l + ((r - l) >> 1);
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if (dfs(grid, vis, 0, 0, mid)){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
protected:
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int t){
        if (i == n - 1 && j == n - 1){
            return true;
        }
        vis[i][j] = true;
        for (auto& d : dir){
            int x = i + d[0];
            int y = j + d[1];
            if (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y] && grid[x][y] <= t){
                if (dfs(grid, vis, x, y, t)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    int n;
};
int main(){
    vector<vector<int>> grid = {
        {0, 2},
        {1, 3}
    };
    cout << Solution().swimInWater(grid) << endl;
    return EXIT_SUCCESS;
}