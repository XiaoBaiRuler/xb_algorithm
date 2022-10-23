#include "../common/common.h"
/**
 * @brief 834. 树中距离之和
 * https://leetcode.cn/problems/sum-of-distances-in-tree/
 * 
 * 自底部向上求每个节点的下属节点个数 +  树形动态规划(父节点对应所有节点的距离之和 + (除开当前子节点所属的节点个数 - 当前节点所有的节点个数))
 */
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        m = n;
        for (auto& e : edges){
            if (map.find(e[0]) == map.end()){
                map[e[0]] = new vector<int>();
            }
            map[e[0]] -> push_back(e[1]);
            if (map.find(e[1]) == map.end()){
                map[e[1]] = new vector<int>();
            }
            map[e[1]] -> push_back(e[0]);
        }
        vector<int> res(n), count(n);
        unordered_set<int> h1;
        countDfs(count, h1, 0);
        unordered_set<int> h2;
        res[0] = ans;
        resDfs(count, h2, res, 0);
        return res;
    }
private:
    int countDfs(vector<int>& count, unordered_set<int>& h1, int i){
        if (map.find(i) == map.end()){
            return 0;
        }
        int c = 0;
        h1.insert(i);
        auto e = map[i] -> end();
        for (auto b = map[i] -> begin(); b != e; ++ b){
            if (h1.count(*b)){
                continue;
            }
            c += countDfs(count, h1, *b);
        }
        ans += c;
        count[i] = c + 1;
        return count[i];
    }
    void resDfs(vector<int>& count, unordered_set<int>& h2, vector<int>& res, int i){
        if (map.find(i) == map.end()){
            return;
        }
        h2.insert(i);
        auto e = map[i] -> end();
        for (auto b = map[i] -> begin(); b != e; ++ b){
            if (h2.count(*b)){
                continue;
            }
            res[*b] = res[i] + (m - count[*b]) - count[*b];
            resDfs(count, h2, res, *b); 
        }
    }
    unordered_map<int, vector<int>*> map;
    int m, ans = 0;
};
int main(){
    vector<vector<int>> nums = {
        {0,1},{0,2},{2,3},{2,4},{2,5}
    };
    vector<int> res = Solution().sumOfDistancesInTree(6, nums);
    cout << res << endl;
    return EXIT_SUCCESS;
}