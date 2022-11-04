#include "../common/common.h"
/**
 * @brief 323. 无向图中连通分量的数目
 * https://leetcode.cn/problems/number-of-connected-components-in-an-undirected-graph/
 */
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
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
        vector<bool> hash(n, false);
        int res = 0;
        for (int i = 0; i < n; ++ i){
            if (map.find(i) == map.end()){
                ++ res;
            }
            else if (!hash[i]){
                select(hash, i);
                ++ res;
            }
        }
        return res;
    }
private:
    void select(vector<bool>& hash, int i){
        stack<int> st;
        st.push(i);
        while(!st.empty()){
            int now = st.top();
            hash[now] = true;
            st.pop();
            auto b = map[now] -> begin();
            auto e = map[now] -> end();
            for (; b != e; ++ b){
                if (hash[*b]){
                    continue;
                }
                st.push(*b);
            }
        }
    }
    unordered_map<int, vector<int>*> map;
};
int main(){
    vector<vector<int>> nums = {{0, 1}, {1, 2}, {3, 4}};
    cout << Solution().countComponents(5, nums) << endl;
    return EXIT_SUCCESS;
}