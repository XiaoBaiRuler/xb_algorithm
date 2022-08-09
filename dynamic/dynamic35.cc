#include "..//common//common.h"
/**
 * @brief 87. 扰乱字符串
 * https://leetcode.cn/problems/scramble-string/
 * 
 * 双串加维度系列(i, j, k): s1在i开始的k个字符是否经过扰动能和s2在j开始的k个字符相等
 * 注意: 从i开始，包含i的
 * 
 * // 1. 不同扰乱长度下的: dp[i][j][k]
 * // 2. 当按照l长度扰乱，但是不交换: dp[i][j][l] and dp[i][j][k - l]
 * // 3. 当按照l长度扰乱，并且交换: dp[i + l][j][k - l] and dp[i][j + k - l][l];
 * 
 * @param s1 
 * @param s2 
 * @return true 
 * @return false 
 */
bool isScramble(string s1, string s2);
int main(){
    string s1 = "great", s2 = "rgeat";
    cout << isScramble(s1, s2) << endl;
    return EXIT_SUCCESS;
}
bool isScramble(string s1, string s2) {
    int n = s1.size();
    vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            dp[i][j][1] = s1[i] == s2[j];
        }
    }
    for (int k = 2; k <= n; ++ k){
        for (int i = 0, ei = n - k; i <= ei; ++ i){
            for (int j = 0, ej = n - k; j <= ej; ++ j){
                for (int l = 1; l < k; ++ l){
                    dp[i][j][k] = dp[i][j][k] || (dp[i][j][l] && dp[i + l][j + l][k - l]) || (dp[i + l][j][k - l] && dp[i][j + k - l][l]);
                }
            }
        }
    }
    return dp[0][0][n];
}