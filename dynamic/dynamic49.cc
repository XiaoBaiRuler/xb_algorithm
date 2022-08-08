#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
int longestCommonSubsequence(string text1, string text2);
/**
 * @brief 1312. 让字符串成为回文串的最少插入次数
 * https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/
 * 
 * 最少的插入次数 => 总长 - 最长的回文子序列
 * 最长的回文子序列可以通过求，reverse字符串和当前字符串的最长公共子序列
 * @param s 
 * @return int 
 */
int minInsertions(string s);
int main(){
    cout << minInsertions("abc") << endl;
    return EXIT_SUCCESS;
}
int minInsertions(string s) {
    int n = s.size();
    string re;
    for (int i = n - 1; i > -1; -- i){
        re.push_back(s[i]);
    }
    return n - longestCommonSubsequence(s, re);
}
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = text1[0] == text2[0] ? 1 : 0;
    if (n > 1){
        for (int i = 1; i < n; ++ i){
            dp[i][0] = text1[i] == text2[0] ? 1 : dp[i - 1][0];
        }
    }
    if (m > 1){
        for (int j = 1; j < m; ++ j){
            dp[0][j] = text1[0] == text2[j] ? 1 : dp[0][j - 1];
        }
    }
    for (int i = 1; i < n; ++ i){
        for (int j = 1; j < m; ++ j){
            if (text1[i] == text2[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n - 1][m - 1];
}