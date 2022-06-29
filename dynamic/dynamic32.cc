#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 10. 正则表达式匹配
 * https://leetcode.cn/problems/regular-expression-matching/
 * 
 * 双串系列(i, j): i之前的字符串1，j之前的字符串2是否匹配
 * 1. 当(i) == (j) || (j) == .
 * 1.1. =(i - 1, j - 1)
 * 2. 当(j) == *
 * 2.1. 当(j - 1) == '.' || (j - 1) == (i), 就可以匹配0, 1, 多个
 * 2.1.1 (i)(j - 2)
 * 2.1.2 (i - 1)(j - 2)
 * 2.1.3 (i - 1)(j)
 * 2.2. 其他情况下，匹配0个
 * 2.2.1. (i)(j - 2)
 * 3. 其他 不可能匹配
 * @param s 
 * @param p 
 * @return true 
 * @return false 
 */
bool isMatch(string s, string p);
int main(){
    string s = "a", p = "aa*";
    cout << isMatch(s, p) << endl;
    return EXIT_SUCCESS;
}
bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    dp[0][0] = true;
    for (int i = 1; i <= n; ++ i){
        dp[i][0] = false;
    }
    dp[0][1] = false;
    for (int j = 2; j <= m; ++ j){
        if (p[j - 1] == '*'){
            dp[0][j] = dp[0][j - 2];
        }
        else{
            dp[0][j] = false;
        }
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.'){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*' && (p[j - 2] == '.' || p[j - 2] == s[i - 1])){
                dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
            }
            else if (p[j - 1] == '*'){
                dp[i][j] = dp[i][j - 2];
            }
            else{
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}