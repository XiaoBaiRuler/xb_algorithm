#include "../common/common.h"
/**
 * @brief 1136. 并行课程
 * https://leetcode.cn/problems/parallel-courses/
 * 
 * 最长深度? (应该为图，而非树)
 */
class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        pre = vector<vector<int>*>(n + 1, nullptr);
        for (auto& r : relations){
            if (pre[r[0]] == nullptr){
                pre[r[0]] = new vector<int>();
            }
            pre[r[0]] -> push_back(r[1]);
        }
        vector<int> hash(n + 1, 0);
        res = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; ++ i){
            if (dfs(hash, i)){
                return -1;
            }
        }
        int ans = 0;
        for (int j : res){
            ans = max(j, ans);
        }
        return ans;
    }
protected:
    bool dfs(vector<int>& hash, int i){
        if (hash[i] == 1){
            return true;
        }
        if (hash[i] == 2){
            return false;
        }
        if (pre[i] == nullptr){
            res[i] = 1;
            hash[i] = 2;
            return false;
        }
        hash[i] = 1;
        auto b = pre[i] -> begin();
        auto e = pre[i] -> end();
        int d = 1;
        for (; b != e; ++ b){
            if (dfs(hash, *b)){
                return true;
            }
            d = max(d, res[*b] + 1);
        }
        res[i] = d; 
        hash[i] = 2;
        return false;
    }
private:
    vector<vector<int>*> pre;
    vector<int> res;
};
int main(){
    vector<vector<int>> nums = {{1, 3}, {2, 3}};
    cout << Solution().minimumSemesters(3, nums) << endl;
    return EXIT_SUCCESS;
}