#include "../common/common.h"
/**
 * @brief 133. 克隆图
 * https://leetcode.cn/problems/clone-graph/
 */
class Solution {
public:
    AdjacencyNode* cloneGraph(AdjacencyNode* node) {
        if (node == nullptr){
            return node;
        }
        res = new AdjacencyNode(node -> val);
        dfs(node, res);
        return res;
    }
protected:
    void dfs(AdjacencyNode* node, AdjacencyNode* now){
        map[now -> val] = now;
        for (AdjacencyNode *n : node -> neighbors){
            if (map.find(n -> val) == map.end()){
                AdjacencyNode* temp = new AdjacencyNode(n -> val);
                now -> neighbors.push_back(temp);
                dfs(n, temp);
            }
            else{
                now -> neighbors.push_back(map[n -> val]);
            }
        }
    }
private:
    unordered_map<int, AdjacencyNode*> map;
    AdjacencyNode *res;
};
int main(){
    AdjacencyNode *a = new AdjacencyNode(1);
    AdjacencyNode *b = Solution().cloneGraph(a);
    cout << b -> val << endl;
    return EXIT_SUCCESS;
}