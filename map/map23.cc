#include "../common/common.h"
/**
 * @brief 1079. 活字印刷
 * https://leetcode.cn/problems/letter-tile-possibilities/
 */
class Solution {
public:
    int numTilePossibilities(string tiles) {
        n = tiles.size();
        s = vector<char>(tiles.begin(), tiles.end());
        sort(s.begin(), s.end());
        vis = vector<bool>(n, false);
        dfs(0);
        return res - 1;
    }
protected:
    void dfs(int c){
        if (c == n){
            ++ res;
            return;
        }
        ++ res;
        for (int i = 0; i < n; ++ i){
            if (vis[i]){
                continue;
            }
            if (i > 0 && s[i] == s[i - 1] && !vis[i - 1]){
                continue;
            }
            vis[i] = true;
            dfs(c + 1);
            vis[i] = false;
        }
    }
private:
    vector<bool> vis;
    int res = 0, n;
    vector<char> s;
};
int main(){
    cout << Solution().numTilePossibilities("AAB") << endl;
    return EXIT_SUCCESS;
}