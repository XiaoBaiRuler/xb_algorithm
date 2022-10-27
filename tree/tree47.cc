#include "../common/common.h"
/**
 * @brief 1519. 子树中标签相同的节点数
 * https://leetcode.cn/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
 */
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
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
        res = new vector<int>(labels.size(), 0);
        select(0, 0, labels);
        return *res;
    }
private:
    vector<int> select(int n, int p, const string& labels){
        vector<int> ms(26, 0);
        if (map.find(n) == map.end()){
            return ms;
        }
        int ans = 0;
        auto b = map[n] -> begin();
        auto e = map[n] -> end();
        for (; b != e; ++ b){
            if (*b == p){
                continue;
            }
            vector<int> ans = select(*b, n, labels);
            for (int i = 0; i < 26; ++ i){
                ms[i] += ans[i];
            }
        }
        ms[labels[n] - 'a'] += 1;
        (*res)[n] = ms[labels[n] - 'a'];
        return ms;
    }
    unordered_map<int, vector<int>*> map;
    vector<int>* res;
};
int main(){
    vector<vector<int>> nums = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
    string labels = "abaedcd";
    vector<int> res = Solution().countSubTrees(7, nums, labels);
    cout << res << endl;
    return EXIT_SUCCESS;
}