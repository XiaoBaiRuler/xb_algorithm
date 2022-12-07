#include "../common/common.h"
/**
 * @brief 934. 最短的桥
 * https://leetcode.cn/problems/shortest-bridge/submissions/
 */
vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        bool flag = true;
        // 第一个小岛变2，并且边界变3
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                if (flag && grid[i][j] == 1){
                    dfsOne(grid, i,j);
                    return bfs(grid);
                }
            }
        }
        return 0;
    }
protected:
    void dfsOne(vector<vector<int>>& grid, int i, int j){
        grid[i][j] = 2;
        for (auto& d : dir){
            int x = i + d[0];
            int y = j + d[1];
            if (x < 0 || y < 0 || x >= n || y >= m){
                continue;
            }
            if (grid[x][y] == 1){
                dfsOne(grid, x, y);
            }
            else if (grid[x][y] == 0){
                grid[i][j] = 3;
                dq.emplace_back(i, j);
            }
        }
    }
    int bfs(vector<vector<int>>& grid){
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;
        while (!dq.empty()){
            int a = dq.size();
            for (int k = 0; k < a; ++ k){
                int i = dq.front().first;
                int j = dq.front().second;
                vis[i][j] = true;
                dq.pop_front();
                for (auto& d : dir){
                    int x = i + d[0];
                    int y = j + d[1];
                    if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y]){
                        continue;
                    }
                    if (grid[x][y] == 0){
                        vis[x][y] = true;
                        dq.emplace_back(x, y);
                    }
                    else if (grid[x][y] == 1){
                        return ans;                   
                    }
                }
            }
            ++ ans;
        }
        return ans;
    }
private:
    int n, m;
    deque<pair<int, int>> dq;
};
int main(){
    vector<vector<int>> grid = {{0, 1}, {1, 0}};
    cout << Solution().shortestBridge(grid) << endl;
    return EXIT_SUCCESS;
}