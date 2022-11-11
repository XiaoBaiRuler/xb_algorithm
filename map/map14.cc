#include "../common/common.h"
/**
 * @brief 886. 可能的二分法
 * https://leetcode.cn/problems/possible-bipartition/
 * 
 * 分两类颜色，同一条边不允许出现颜色相同
 */
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        pre = vector<vector<int>*>(n + 1, nullptr);
        for (auto& d : dislikes){
            if (pre[d[0]] == nullptr){
                pre[d[0]] = new vector<int>();
            }
            pre[d[0]] -> push_back(d[1]);
            if (pre[d[1]] == nullptr){
                pre[d[1]] = new vector<int>();
            }
            pre[d[1]] -> push_back(d[0]);
        }
        vector<bool> visit(n + 1, false);
        vector<bool> color(n + 1);
        for (int i = 1; i <= n; ++ i){
            if (!visit[i] && !dfs(visit, color, i, true)){
                return false;
            }
        }
        return true;
    }
protected:
    bool dfs(vector<bool>& visit, vector<bool>& color, int i, int f){
        visit[i] = true;
        color[i] = f;
        if (pre[i] == nullptr){
            return true;
        }
        auto b = pre[i] -> begin();
        auto e = pre[i] -> end();
        for (; b != e; ++ b){
            if (!visit[*b]){
                if (!dfs(visit, color, *b, !f)){
                    return false;
                }
            }
            else if (color[i] == color[*b]){
                return false;
            }
        }
        return true;
    }
private:
    vector<vector<int>*> pre;
};
int main(){
    vector<vector<int>> nums = {{1, 2}, {1, 3}, {2, 4}};
    cout << Solution().possibleBipartition(4, nums) << endl;
    return EXIT_SUCCESS;
}