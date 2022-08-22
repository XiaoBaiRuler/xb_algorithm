#include "../common/common.h"
int MAX = 1000000007;
/**
 * @brief 1444. 切披萨的方案数
 * https://leetcode.cn/problems/number-of-ways-of-cutting-a-pizza/
 * 
 * 设(i, j, k)为切了k刀得到剩余左上角坐标为(i, j)的方案数
 * 
 * - 当(i, j) - (i - 1, m) 不为0，i [1, i)，上一次是横切
 * - 当(i, j) - (n, j - 1) 不为0，j [1, j), 上一次是竖切
 * 
 * 最后切了k - 1刀的方案书数
 * 
 */
class Solution {
private:
    vector<vector<int>> pre;
public:
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size(), m = pizza[0].size(), tmp = 0;
        pre = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                if (pizza[i][j] == 'A'){
                    pre[i + 1][j + 1] = 1;
                }
                pre[i + 1][j + 1] += pre[i][j + 1] + pre[i + 1][j] - pre[i][j];
            }
        }
        // 定义为切了k刀得到剩余左上角坐标为(i, j)的方案数
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k)));
        dp[1][1][0] = 1;
        for (int c = 1; c < k; ++ c){
            for (int i = 1; i <= n; ++ i){
                for (int j = 1; j <= m; ++ j){
                    // 过滤
                    if (getSum(i, j, n, m) == 0){
                        continue;
                    }
                    // 横切
                    for (int p = 1; p < i; ++ p){
                        if (getSum(p, j, i - 1, m) != 0){
                            dp[i][j][c] = (dp[i][j][c] + dp[p][j][c - 1]) %  MAX;
                        }
                    }
                    // 竖切
                    for (int p = 1; p < j; ++ p){
                        if (getSum(i, p, n, j - 1) != 0){
                            dp[i][j][c] = (dp[i][j][c] + dp[i][p][c - 1]) % MAX;
                        }
                    }
                }
            }
        }
        tmp = 0;
        for (int i = 1; i <= n; ++ i){
            for (int j = 1; j <= m; ++ j){
                tmp = (tmp + dp[i][j][k - 1]) % MAX;
            }
        }
        return tmp;
    }
    int getSum(int i, int j, int x, int y){
        return pre[x][y] + pre[i - 1][j - 1] - pre[x][j - 1] - pre[i - 1][y];
    }
};
int main(){
    vector<string> pizza = {
        "A..",
        "AAA",
        "..."
    };
    Solution s;
    cout << s.ways(pizza, 3) << endl;
    return EXIT_SUCCESS;
}