#include "../common/common.h"
/**
 * @brief 132. 分割回文串 II
 * https://leetcode.cn/problems/palindrome-partitioning-ii/
 * 
 * 1. 先判断字符串中那个子串能够构成回文串
 * => 设(l, r) 表示l - r能不能构成回文串
 * => s[l] == s[r]
 *  1. l - r == 0: 单个字符 必为回文串
 *  2. l - r == 1: 两个相同字符 必为回文串
 *  3. other: 取决于dp[l + 1][r - 1]
 * 
 * 2. 再计算分割的最少次数
 * => 设(r) 表示0 - r 分割的最少次数
 * => 那么可以分割的可能方案就是l [0, r]
 * => (r) = min((r), (l - 1) + 1)
 * @param s 
 * @return int 
 */
int minCut(string s);
int main(){
    cout << minCut("aab") << endl;
    return EXIT_SUCCESS;
}
int minCut(string s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int i = 0; i < n; ++ i){
        dp[i][i] = true;
    }
    for (int r = 1; r < n; ++ r){
        for (int l = r - 1; l > -1; -- l){
            if (s[l] == s[r]){
                dp[l][r] = r - l == 1 || dp[l + 1][r - 1];
            }
        }
    }
    //f[r] 代表将 [0,r] 这一段分割成若干回文子串所需要的最小分割次数
    vector<int> f(n);
    for (int r = 0; r < n; ++ r){
        f[r] = dp[0][r] ? 0 : r;
    }
    for (int r = 1; r < n; ++ r){
        for (int l = 1; l <= r; ++ l) {
            if (dp[l][r]) {
                f[r] = min(f[r], f[l - 1] + 1);
            }
        }   
    }
    return f[n - 1];
}