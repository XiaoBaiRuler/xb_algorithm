#include "..//common//common.h"
/**
 * @brief 132. 分割回文串 II
 * https://leetcode.cn/problems/palindrome-partitioning-ii/
 * 
 * 1. 构建l - r 范围内是否是回文串的数组
 *    => g[l][r] 代表 [l,r] 这一段是否为回文串
 *       1. 如果只有一个字符，则[l,r]属于回文
 *       2. 在 l 和 r 字符相同的前提下，如果 l 和 r 长度只有 2；或者 [l+1,r-1] 这一段满足回文，则[l,r]属于回文
 * 2. dp[r] 代表将 [1,r] 这一段分割成若干回文子串所需要的最小分割次数
 * => 如果 [1,r] 满足回文，不需要分割
 * => 在所有符合 [l,r] 回文的方案中取最小值
 * 
 * @param s 
 * @return public 
 */
int minCut(string s);
int main(){
    vector<string> s = {
        "aab", "a", "ab"
    };
    int n = s.size();
    for (int i = 0; i < n; ++ i){
        cout << minCut(s[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
int minCut(string s) {
    int n = s.size();
    vector<vector<bool>> g(n + 1, vector<bool>(n + 1, false));
    for (int r = 1; r <= n; r++) {
        for (int l = r; l >= 1; l--) {
            if (l == r) {
                g[l][r] = true;
            } else {
                if (s[l - 1] == s[r - 1]) {
                    if (r - l == 1 || g[l + 1][r - 1]) {
                        g[l][r] = true;
                    }
                }
            }
        }
    }
    vector<int> dp(n + 1, 0);
    for (int r = 1; r <= n; r++) {
        if (g[1][r]) {
            dp[r] = 0;
        } else {
            dp[r] = r - 1;
            for (int l = 1; l <= r; l++) {
                if (g[l][r]) dp[r] = min(dp[r], dp[l - 1] + 1);
            }   
        }
    }

    return dp[n];
}