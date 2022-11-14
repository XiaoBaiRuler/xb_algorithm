#include "../common/common.h"
/**
 * @brief 784. 字母大小写全排列
 * https://leetcode.cn/problems/letter-case-permutation/
 * 
 * 
 */
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        ss = s;
        n = s.size();
        dfs(0, "");
        return res;
    }
protected:
    void dfs(int i, string it){
        if (i == n){
            res.push_back(it);
            return;
        }
        if (isalpha(ss[i])){
            string next(it);
            if (isupper(ss[i])){
                it.push_back(ss[i]);
                dfs(i + 1, it);
                next.push_back(tolower(ss[i]));
                dfs(i + 1, next);
            }
            else{
                it.push_back(ss[i]);
                dfs(i + 1, it);
                next.push_back(toupper(ss[i]));
                dfs(i + 1, next);
            }
        }
        else{
            it.push_back(ss[i]);
            dfs(i + 1, it);
        }
    }
private:
    vector<string> res;
    string ss;
    int n;
};
int main(){
    string s = "a1b2";
    vector<string> res = Solution().letterCasePermutation(s);
    cout << res << endl;
    return EXIT_SUCCESS;
}