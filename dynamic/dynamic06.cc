#include "..//common//common.h"
/**
 * @brief 91. 解码方法
 * https://leetcode-cn.com/problems/decode-ways/
 * 
 * 1. 当选一个字符时, 非0时, dp[i] += dp[i - 1]
 * 2. 当选两个字符时，第一个字符不为0，并且两个字符组成的数 <= 26时，dp[i] += dp[i - 2]
 * 一直选到最后一个字符
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 * @param s 
 * @return int 
 */
int numDecodings(string s);
/**
 * @brief 
 * 
 * 时间复杂度: O(n)
 * 空间复杂度: O(1)
 * 
 * @param s 
 * @return int 
 */
int numDecodingsChange(string s);
int main(){
    vector<string> s = {
        "12", "226", "0"
    };
    int n = s.size();
    for (int i = 0; i < n; ++ i){
        cout << numDecodingsChange(s[i]) << " ";
    }
    return EXIT_SUCCESS;
}
int numDecodings(string s) {
    int n = s.size(), pre1, pre2;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++ i){
        pre1 = s[i - 1] - '0';
        pre2 = i > 1 ? s[i - 2] - '0' : 3;
        if (pre1 != 0){
            dp[i] += dp[i - 1];
        }
        if (pre2 != 0 && (pre2 * 10 + pre1) <= 26){
            dp[i] += dp[i - 2];
        }
    }
    return dp[n];
}
int numDecodingsChange(string s){
    int n = s.size(), pre1, pre2, p1 = 1, p2, now;
    for (int i = 1; i <= n; ++ i){
        now = 0;
        pre1 = s[i - 1] - '0';
        pre2 = i > 1 ? s[i - 2] - '0' : 3;
        if (pre1 != 0){
            now += p1;
        }
        if (pre2 != 0 && (pre2 * 10 + pre1) <= 26){
            now += p2;
        }
        p2 = p1;
        p1 = now;
    }
    return now;
}