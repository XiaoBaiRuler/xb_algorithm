#include "../common/common.h"
/**
 * @brief 785. 判断二分图
 * https://leetcode.cn/problems/is-graph-bipartite/
 * 
 * 判断是不是可以将节点分成两类，并且两类之间的节点都不相连
 */
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        visit = vector<bool>(n, false);
        sort = vector<bool>(n);
        for (int i = 0; i < n; ++ i){
            if (!visit[i]){
                if (!dfs(graph, i, true)){
                    return false;
                }
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph, int i, bool s){
        visit[i] = true;
        sort[i] = s;
        for (int j : graph[i]){
            if (!visit[j]){
                // 分不同于前一种的类
                if (!dfs(graph, j, !s)){
                    return false;
                }
            }
            // 两个链接节点分类不能一样
            else if (sort[j] == sort[i]){
                return false;
            }
        }
        return true;
    }
private:
    vector<bool> visit;
    vector<bool> sort;
};
int main(){
    vector<vector<int>> nums = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    cout << Solution().isBipartite(nums) << endl;
    return EXIT_SUCCESS;
}