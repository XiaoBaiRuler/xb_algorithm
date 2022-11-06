#include "../common/common.h"
/**
 * @brief 684. 冗余连接
 * https://leetcode.cn/problems/redundant-connection/
 * 
 * 并查集
 * 当一条边的两个端点的根节点一直时，那么就是存在环
 */
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        for (auto& edge: edges) {
            int node1 = edge[0], node2 = edge[1];
            int root1 = find(parent, node1);
            int root2 = find(parent, node2);
            if (root1 != root2) {
                parent[root1] = root2;
            } else {
                return edge;
            }
        }
        return vector<int>{};
    }
private:
    int find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = find(parent, parent[index]);
        }
        return parent[index];
    }
};
int main(){
    vector<vector<int>> nums = {
        {1,2}, {1,3}, {2,3}
    };
    vector<int> res = Solution().findRedundantConnection(nums);
    cout << res << endl;
    return EXIT_SUCCESS;
}