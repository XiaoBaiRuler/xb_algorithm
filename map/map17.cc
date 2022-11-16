#include "../common/common.h"
/**
 * @brief 51. N 皇后
 * https://leetcode.cn/problems/n-queens/
 * 
 * 正斜线: row - col + (n - 1) 在[0, 2 * n - 1]
 * 反斜线: row + col 在[0, 2 * n - 1]
 */
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        m = n;
        col = vector<bool>(n, false);
        mai = vector<bool>(2 * n - 1, false);
        sub = vector<bool>(2 * n - 1, false);
        deque<int> ans;
        dfs(ans, 0);
        return res;
    }
protected:
    void dfs(deque<int> ans, int i){
        if (i == m){
            vector<string> item;
            for (int j : ans){
                item.push_back(string(j, '.') + 'Q' + string(m - j - 1, '.'));
                ans.pop_front();
            }
            res.push_back(item);
            return;
        }
        for (int j = 0; j < m; ++ j){
            int a = i - j + m - 1, b = i + j;
            if (!col[j] && !mai[a] && !sub[b]){
                ans.push_back(j);
                col[j] = true;
                mai[a] = true;
                sub[b] = true;
                dfs(ans, i + 1);
                col[j] = false;
                mai[a] = false;
                sub[b] = false;
                ans.pop_back();
            }
        }
    }
private:
    int m;
    vector<bool> col, mai, sub;
    vector<vector<string>> res;
};
int main(){
    vector<vector<string>> res = Solution().solveNQueens(4);
    for (auto& r : res){
        cout << r << endl;
    }
    return EXIT_SUCCESS;
}