#include "..//common//common.h"
/**
 * @brief 417. 太平洋大西洋水流问题
 * https://leetcode-cn.com/problems/pacific-atlantic-water-flow/
 * 
 * 从边界进行深度优先查找，分别使用hash存储：右上边界、左下边界
 * 重复的元素，即是答案
 * 
 * 时间复杂度: dfs(less m * n) * (2m + 2n) => O(m * n)
 * 空间复杂度: O(m * n)  
 * 
 */
class Solution;
vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>> res;
        unordered_set<int> a, p;
        for (int i = 0; i < m; ++ i){
            isAP(heights, 0, i, p);
            isAP(heights, n - 1, i, a);
        }
        for (int i = 0; i < n; ++ i){
            isAP(heights, i, 0, p);
            isAP(heights, i, m - 1, a);
        }
        for (auto &i : p){
            if (a.count(i)){
                res.emplace_back(vector<int>{i / m, i % m});
            }
        }
        return res;
    }
    void isAP(vector<vector<int>>& heights, int a, int b, unordered_set<int>& set){
        int tmp = a * m + b;
        stack<int> st;
        st.push(tmp);
        set.insert(tmp);
        while (!st.empty()){
            int x = st.top() / m;
            int y = st.top() % m;
            st.pop();
            for (auto& d : dir){
                int i = x + d[0];
                int j = y + d[1];
                tmp = i * m + j;
                if (i < 0 || j < 0 || i >= n || j >= m || heights[x][y] > heights[i][j] || set.count(tmp)){
                    continue;
                }
                set.insert(tmp);
                st.push(tmp);
            }
        }
    }
private:
    int n;
    int m;
};
int main(){

    Solution s;
    vector<vector<vector<int>>> heights = {
        {
            {1, 2, 2, 3, 5},
            {3, 2, 3, 4, 4},
            {2, 4, 5, 3, 1},
            {6, 7, 1, 4, 5},
            {5, 1, 1, 2, 4}
        },
        {
            {2, 1},
            {1, 2}
        }
    };
    int n = heights.size();
    for (int i = 0; i < n; ++ i){
        vector<vector<int>> item = s.pacificAtlantic(heights[i]);
        for (vector<int> &it : item){
            for (int i : it){
                cout << i << " ";
            }
            cout << endl;
        }
        cout << "############" << endl;
    }

    return 0;
}