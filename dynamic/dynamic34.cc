#include "..//common//common.h"
/**
 * @brief 115. 不同的子序列
 * https://leetcode.cn/problems/distinct-subsequences/
 * 
 * 双串系列(i, j): i之前的字符串1经过多少次变幻可以变成j之前的字符串2
 * 
 * 1. 当i, j 字符相同时，即可以删除一个字符或者什么都不做
 * 2. 当i, j 字符不同时，删除一个字符
 * @param s 
 * @param t 
 * @return int 
 */
int numDistinct(string s, string t);
int main(){
    string s = "rabbbit", t = "rabbit";
    cout << numDistinct(s, t) << endl;
    return EXIT_SUCCESS;
}
int numDistinct(string s, string t) {
    int n = s.size(), m = t.size(); 
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; ++ i){
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; ++ i){
        // 如果第二字符串长的话，就不可能相同
        for (int j = 1; j <= m && j <= i; ++ j){
            if (s[i - 1] == t[j - 1]){
                long long all = static_cast<long long>(dp[i - 1][j]) + dp[i - 1][j - 1];
                if (all >= INT_MAX){
                    all %= INT_MAX;
                } 
                dp[i][j] = all; 
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}