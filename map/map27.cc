#include "../common/common.h"
/**
 * @brief 面试题13. 机器人的运动范围
 * https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
 */
vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
class Solution {
public:
    int movingCount(int m, int n, int k) {
        w = m;
        h = n;
        t = k;
        visit = vector<vector<bool>>(w, vector<bool>(h, false));
        dfs(0, 0);
        return ans;
    }
protected:
    void dfs(int i, int j){
        if ((count(i) + count(j)) > t){
            return;
        }
        ans += 1;
        visit[i][j] = true;
        for (auto& d : dir){
            int x = i + d[0];
            int y = j + d[1];
            if (x < 0 || y < 0 || x >= w || y >= h || visit[x][y]){
                continue;
            }
            dfs(x, y);
        }
    }
    int count(int n){
        int res = 0;
        while (n != 0){
            res += n % 10;
            n /= 10;
        }
        return res;
    }
private:
    int w, h, t, ans = 0;
    vector<vector<bool>> visit;
};
int main(){
    cout << Solution().movingCount(3, 1, 0) << endl;
    return EXIT_SUCCESS;
}