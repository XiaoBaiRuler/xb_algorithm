#include "../common/common.h"
/**
 * @brief 802. 找到最终的安全状态
 * https://leetcode.cn/problems/find-eventual-safe-states/
 * 
 */
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();
        vector<int> hash(n, 0);
        for (int i = 0; i < n; ++ i){
            if (check(i, graph, hash)){
                continue;
            }
            res.push_back(i);
        }
        return res;
    }
private:
    bool check(int i, vector<vector<int>>& graph, vector<int>& hash){
        if (hash[i] != 0){
            return hash[i] == 1;
        }
        hash[i] = 1;
        for (int j : graph[i]){
            if (check(j, graph, hash)){
                return true;
            }
        }
        hash[i] = 2;
        return false;
    }
};
int main(){
    vector<vector<int>> graph = {
        {1,2},{2,3},{5},{0},{5},{},{}
    };
    vector<int> res = Solution().eventualSafeNodes(graph);
    cout << res << endl;
    return EXIT_SUCCESS;
}