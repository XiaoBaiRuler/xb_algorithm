#define PATH 1
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 712. 两个字符串的最小ASCII删除和
 * https://leetcode.cn/problems/minimum-ascii-delete-sum-for-two-strings/
 * 
 * 1. 总和 - 最大公共部分之和
 * 2. 求最大公共部分 => 双串类问题i, j
 * 2.1. 当i,j 位置的text字符相同
 * 2.1.1. = (i - 1, j - 1) + s1[i]
 * 2.2. 当i,j 位置的text字符不同
 * 2.2.1. = max((i - 1, j), (i, j - 1))
 *
 * @param s1 
 * @param s2 
 * @return int 
 */
int minimumDeleteSum(string s1, string s2);
int main(){
    vector<string> s1 = {"sea", "delete"};
    vector<string> s2 = {"eat", "leet"};
    int n = s1.size();
    for (int i = 0; i < n; ++ i){
        cout << minimumDeleteSum(s1[i], s2[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
int minimumDeleteSum(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    int res = s1[0] + s2[0];
    vector<vector<int>> dp(n, vector<int>(m));
    dp[0][0] = s1[0] == s2[0] ? s1[0] : 0;
    for (int i = 1; i < n; ++ i){
        res += s1[i];
        dp[i][0] = s1[i] == s2[0] ? s2[0] : dp[i - 1][0];
    }
    for (int j = 1; j < m; ++ j){
        res += s2[j];
        dp[0][j] = s1[0] == s2[j] ? s1[0] : dp[0][j - 1];
    }
    for (int i = 1; i < n; ++ i){
        for (int j = 1; j < m; ++ j){
            if (s1[i] == s2[j]){
                dp[i][j] = dp[i - 1][j - 1] + s1[i];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return res - dp[n - 1][m - 1] * 2;
}