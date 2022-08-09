#include "..//common//common.h"
/**
 * @brief 72. 编辑距离
 * https://leetcode.cn/problems/edit-distance/
 * 
 * 双串类型: i, j; 代表i之前字符串，需要j之前字符串操作最小次数能转换
 * 1. 当i, j 位置字符相同
 * 1.1 = (i - 1, j - 1)
 * 2. 当i, j 位置字符不同, 三种操作中最小的操作
 * 2.1 可以添加= (i - 1, j) + 1
 * 2.2 可以删除= (i, j - 1) + 1
 * 2.3 可以替换= (i - 1，j - 1) + 1
 * 
 * 注意起始
 * 
 * @param word1 
 * @param word2 
 * @return int 
 */
int minDistance(string word1, string word2);
int main(){
    vector<string> word1 = {"horse", "intention"};
    vector<string> word2 = {"ros", "execution"};
    int n = word1.size();
    for (int i = 0; i < n; ++ i){
        cout << minDistance(word1[i], word2[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++ i){
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; ++ j){
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            if (word1[i - 1] == word2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    return dp[n][m];
}