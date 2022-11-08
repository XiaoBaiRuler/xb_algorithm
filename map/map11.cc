#include "../common/common.h"
/**
 * @brief 210. 课程表 II
 * https://leetcode.cn/problems/course-schedule-ii/
 * 1. 构建前缀树
 * 2. 深度优先搜索判断是否有环 + 后序遍历得到先导顺序
 */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        pre = vector<unordered_set<int>*>(numCourses, nullptr);
        for (auto& p : prerequisites){
            if (pre[p[0]] == nullptr){
                pre[p[0]] = new unordered_set<int>();
            }
            pre[p[0]] -> insert(p[1]);
        }
        vector<int> res;
        vector<int> hash(numCourses, 0);
        for (int i = 0; i < numCourses; ++ i){
            if (dfs(res, hash, i)){
                return vector<int>();
            }
        }
        return res;
    }
private:
    vector<unordered_set<int>*> pre;
    bool dfs(vector<int>& res, vector<int>& hash, int i){
        if (hash[i] == 1){
            return true;
        }
        if (hash[i] == 2){
            return false;
        }
        if (pre[i] == nullptr){
            res.push_back(i);
            hash[i] = 2;
            return false;
        }
        hash[i] = 1;
        auto b = pre[i] -> begin();
        auto e = pre[i] -> end();
        for (; b != e; ++ b){
            if (dfs(res, hash, *b)){
                return true;
            }
        } 
        res.push_back(i);
        hash[i] = 2;
        return false;
    }
};
int main(){
    vector<vector<int>> nums = {{1, 0}};
    vector<int> res = Solution().findOrder(2, nums);
    cout << res << endl;
    return EXIT_SUCCESS;
}