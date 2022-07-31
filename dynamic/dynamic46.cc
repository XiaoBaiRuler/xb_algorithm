#define PATH 1
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 516. 最长回文子序列
 * https://leetcode.cn/problems/longest-palindromic-subsequence/
 * 
 * 设(l, r)表示l - r所能达成的最大序列大小
 * - 当s[l] == s[r]时 => (l + 1, r - 1) + 2
 * - 当s[l] != s[r]时，那么可以删除一个字符: max((l + 1, r), (l, r - 1))
 * @param s 
 * @return int 
 */
int longestPalindromeSubseq(string s);
int main(){
    cout << longestPalindromeSubseq("bbbab") << endl;
    return EXIT_SUCCESS;
}
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int r = 0; r < n; r ++) {
        dp[r][r] = 1;
        for (int l = r - 1; l >= 0; l --) {
            if (s[l] == s[r]) {
                dp[l][r] = dp[l + 1][r - 1] + 2;
            }
            else{
                dp[l][r] = max(dp[l][r - 1], dp[l + 1][r]);
            }
        }
    }
    return dp[0][n - 1];
}