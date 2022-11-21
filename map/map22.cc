#include "../common/common.h"
/**
 * @brief 1593. 拆分字符串使唯一子字符串的数目最大
 * https://leetcode.cn/problems/split-a-string-into-the-max-number-of-unique-substrings/
 */
class Solution {
public:
    int maxUniqueSplit(string s) {
        ss = s;
        n = s.size();
        unordered_set<string> set;
        dfs(0, set);
        return res;
    }
protected:
    void dfs(int i, unordered_set<string>& set){
        if (i == n){
            res = max(res, static_cast<int>(set.size()));
            return;
        }
        for (int j = i; j < n; ++ j){
            string it = ss.substr(i, j - i + 1);
            if (set.count(it)){
                continue;
            }
            set.insert(it);
            dfs(j + 1, set);
            set.erase(it);
        }
    }
private:
    int res = 1, n;
    string ss;
};
int main(){
    string s = "ababcccc";
    cout << Solution().maxUniqueSplit(s) << endl;
    return EXIT_SUCCESS;
}