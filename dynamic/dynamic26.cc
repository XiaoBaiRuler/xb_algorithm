#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 1143. 最长公共子序列
 * https://leetcode.cn/problems/longest-common-subsequence/
 * 
 * 双串类问题i, j
 * 1. 当i,j 位置的text字符相同
 * 1.1. = (i - 1, j - 1) + 1
 * 2. 当i,j 位置的text字符不同
 * 2.1. = max((i - 1, j), (i, j - 1))
 * 
 * @param text1 
 * @param text2 
 * @return int 
 */
int longestCommonSubsequence(string text1, string text2);
int main(){
    vector<string> text1 = {
        "abcde", "abc", "abc"
    };
    vector<string> text2 = {
        "ace", "abc", "def"
    };
    int n = text1.size();
    for (int i = 0; i < n; ++ i){
        cout << longestCommonSubsequence(text1[i], text2[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
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