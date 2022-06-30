#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 97. 交错字符串
 * https://leetcode.cn/problems/interleaving-string/
 * 
 * 双串系列(i, j): i之前的s1字符，j之前的s2字符，能否交错组成s3
 * 两种情况:
 * 1. 当s1的i字符和s3的i + j字符比较时 = (i - 1, j) && s1[i] == s3[i + j]
 * 2. 当s2的j字符和s3的i + j字符比较时 = (i, j - 1) && s2[j] == s3[i + j] 
 * @param s1 
 * @param s2 
 * @param s3 
 * @return true 
 * @return false 
 */
bool isInterleave(string s1, string s2, string s3);
int main(){
    string s1 = "abc", s2 = "def", s3 = "abcdef";
    cout << isInterleave(s1, s2, s3) << endl;
    return EXIT_SUCCESS;
}
bool isInterleave(string s1, string s2, string s3) {
    int n = s1.size(), m = s2.size(), t = s3.size();
    if (n + m != t){
        return false;
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    dp[0][0] = true;
    for (int i = 1; i <= n; ++ i){
        dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
    } 
    for (int j = 1; j <= m; ++ j){
        dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }
    return dp[n][m];
}