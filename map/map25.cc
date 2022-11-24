#include "../common/common.h"
/**
 * @brief 1254. 统计封闭岛屿的数目
 * https://leetcode.cn/problems/number-of-closed-islands/
 */
vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        n = grid.size();
        m = grid[0].size();
        for (int i = 1; i < n - 1; ++ i){
            for (int j = 1; j < m - 1; ++ j){
                if (grid[i][j] == 0){
                    flag = true;
                    dfs(i, j, grid);
                    if (flag){
                        ++ res;
                    }
                }
            }
        }
        return res;
    }
protected:
    void dfs(int i, int j, vector<vector<int>>& grid) {
        grid[i][j] = 2;
        if (i == n - 1 || i == 0 || j == m - 1 || j == 0){
            flag = false;
        }
        for (auto& d : dir){
            int x = i + d[0];
            int y = j + d[1];
            if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] > 0){
                continue;
            }
            dfs(x, y, grid);
        }
    }
private:
    int n, m;
    bool flag;
};
int main(){
    vector<vector<int>> nums = {
        {1,1,1,1,1,1,1,0},
        {1,0,0,0,0,1,1,0},
        {1,0,1,0,1,1,1,0},
        {1,0,0,0,0,1,0,1},
        {1,1,1,1,1,1,1,0}
    };
    cout << Solution().closedIsland(nums) << endl;
    return EXIT_SUCCESS;
}