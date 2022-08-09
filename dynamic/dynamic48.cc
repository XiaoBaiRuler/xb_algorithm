#include "..//common//common.h"
/**
 * @brief 664. 奇怪的打印机
 * https://leetcode.cn/problems/strange-printer/
 * 区间动态规划: 设l - r处需要的最少打印次数
 * 1. 先枚举右边界r [1, n]
 * 2. 再枚举左边界l [r - 1, -1] 由小范围 -> 大范围
 * 3. 之后枚举r - l可能出现变动的位置k [l + 1, r]
 * 3.1. 当s[l] == s[k]时，那么k处打印附属与l + 1到k的打印: dp[l + 1][k] + dp[k + 1][r]
 * 
 * 4. 如果s[l] == s[r]，那么可能l处打印是附属于l + 1到r的打印: dp[l + 1][r]
 * 
 * 注意当不存在附属于其他部分的打印时，只能单独打印dp[l + 1][r] + 1;
 * @param s 
 * @return int 
 */
int strangePrinter(string s);
int main(){
    string s = "aba";
    cout << strangePrinter(s) << endl;
    return EXIT_SUCCESS;
}
int strangePrinter(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; ++ i){
        dp[i][i] = 1;
    }
    for (int r = 1; r < n; ++ r){
        for (int l = r - 1; l > -1; -- l){
            dp[l][r] = dp[l + 1][r] + 1;
            for (int k = l + 1; k < r; ++ k){
                if (s[l] == s[k]){
                    dp[l][r] = min(dp[l + 1][k] + dp[k + 1][r], dp[l][r]);
                }
            }
            if (s[l] == s[r]){
                dp[l][r] = min(dp[l][r], dp[l + 1][r]);
            }
        }
    }
    return dp[0][n - 1];
}