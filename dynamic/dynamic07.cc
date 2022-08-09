#include "..//common//common.h"
/**
 * @brief 583. 两个字符串的删除操作
 * https://leetcode-cn.com/problems/delete-operation-for-two-strings/
 * 
 * 求两个字符串删除最少个字符后相同
 * => n1 + n2 - 2 * 两个字符串的最多公共部分
 * => 两个字符串的最多公共部分
 *  => 第一个字符串，以i结尾的最多部分[0, n)
 *  => 第二个字符串，以j结尾的最多部分[0, n)
 *  => dp[i][j] = word1[i - 1] == word2[j - 1] 
 *      ? dp[i - 1][j - 1] + 1
 *      : max(dp[i - 1][j], dp[i][j - 1]);
 * 
 * @param word1 
 * @param word2 
 * @return int 
 */
int minDistance(string word1, string word2);
int main(){
    vector<string> word1 = {"sea", "leetcode"};
    vector<string> word2 = {"eat", "etco"};
    int n = word1.size();
    for (int i = 0; i < n; ++ i){
        cout << minDistance(word1[i], word2[i]) << " ";
    }
    cout << endl;
    return 0;
}

int minDistance(string word1, string word2) {
    int s1 = word1.size();
    int s2 = word2.size();
    vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
    for (int i = 1; i <= s1; i ++){
        for (int j = 1; j <= s2; j ++){
                dp[i][j] = word1[i - 1] == word2[j - 1] ? 
                    dp[i - 1][j - 1] + 1 :
                    max(dp[i - 1][j], dp[i][j - 1]); 
        }
    }
    return s1 + s2 - 2 * dp[s1][s2];
}