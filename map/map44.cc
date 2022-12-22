#include "../common/common.h"
/**
 * @brief 547. 省份数量
 * https://leetcode.cn/problems/number-of-provinces/
 */
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        int res = 0;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; ++ i){
            if (!vis[i]){
                vis[i] = true;
                bfs(i, isConnected, vis);
                ++ res;
            }
        }
        return res;
    }
protected:
    void bfs(int i, vector<vector<int>>& isConnected, vector<bool>& vis){
        deque<int> dq;
        dq.push_back(i);
        while (!dq.empty()){
            int m = dq.size();
            for (int j = 0; j < m; ++ j){
                int k = dq.front();
                dq.pop_front();
                for (int l = 0; l < n; ++ l){
                    if (isConnected[k][l] && !vis[l]){
                        dq.push_back(l);
                        vis[l] = true;
                    }
                }
            }
        }
    }
private:
    int n;
};
int main(){
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout << Solution().findCircleNum(isConnected) << endl;
    return EXIT_SUCCESS;
}