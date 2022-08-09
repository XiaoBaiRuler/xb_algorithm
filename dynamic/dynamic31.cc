#include "..//common//common.h"
/**
 * @brief 44. 通配符匹配
 * https://leetcode.cn/problems/wildcard-matching/
 * 
 * 双串系列(i, j): i之前的字符串，j之前的字符串经过正则变换之后，是否匹配
 * 
 * 1. 当前字符相同: ? / 相同
 * 1.1. 和(i - 1, j - 1)同
 * 2. j所对应字符为*: 那么j可以对应少一个字符或多一个字符
 * 2.1. (i - 1, j) or (i, j - 1)
 * 3. 其他
 * 3.1 不匹配
 * 
 * @param s 
 * @param p 
 * @return true 
 * @return false 
 */
bool isMatch(string s, string p);
int main(){
    string s = "aa";
    string p = "?*";
    cout << isMatch(s, p) << endl;
    return EXIT_SUCCESS;
}
bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = true;
    for (int i = 1; i <= n; ++ i){
        dp[i][0] = false;
    }
    for (int j = 1; j <= m; ++ j){
        if (p[j - 1] == '*'){
            dp[0][j] = dp[0][j - 1];
        }
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*'){
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
            else{
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}