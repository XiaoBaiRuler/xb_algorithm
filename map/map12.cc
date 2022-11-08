#include "../common/common.h"
/**
 * @brief 207. 课程表
 * https://leetcode.cn/problems/course-schedule/
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        pre = vector<vector<int>*>(numCourses, nullptr);
        for (auto& p : prerequisites){
            if (pre[p[0]] == nullptr){
                pre[p[0]] = new vector<int>();
            }
            pre[p[0]] -> push_back(p[1]);
        }
        vector<int> hash(numCourses, 0);
        for (int i = 0; i < numCourses; ++ i){
            if (dfs(hash, i)){
                return false;
            }
        }
        return true;
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
            hash[i] = 2;
            return false;
        }
        hash[i] = 1;
        auto b = pre[i] -> begin();
        auto e = pre[i] -> end();
        for (; b != e; ++ b){
            if (dfs(hash, *b)){
                return true;
            }
        }
        hash[i] = 2;
        return false;
    }
private:
    vector<vector<int>*> pre;
};
int main(){
    vector<vector<int>> nums = {
        {1, 0}, {0, 1}
    };
    cout << Solution().canFinish(2, nums) << endl;
    return EXIT_SUCCESS;
}