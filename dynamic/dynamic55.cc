#include "../common/common.h"
int getCircleCnt(string &s);
/**
 * @brief 471. 编码最短长度的字符串
 * https://leetcode.cn/problems/encode-string-with-shortest-length/
 * 
 * (l, r) 表示范围l - r内编码最短长度的字符串
 * 1. l - r内范围为不断重复的一段 x[ss]
 * 2. l - r为一段中的一部分 (l, r) = (l, m) + (m + 1, r)
 * 
 * @param s 
 * @return string 
 */
string encode(string s);
int main(){
    cout << encode("abbbabbbcabbbabbbc") << endl;
    return EXIT_SUCCESS;
}
string encode(string s) {
    int n = s.size();
    vector<vector<string>> dp(n, vector<string>(n));
    for (int l = n - 1; l > -1; -- l){
        for (int r = l; r < n; ++ r){
            int len = r - l + 1;
            dp[l][r] = s.substr(l, len);
            if (len < 4){
                continue;
            }
            int rr = getCircleCnt(dp[l][r]);
            string tmp = to_string(len / rr) + "[" + dp[l][l + rr - 1] + "]";
            if (tmp.size() < dp[l][r].size()){
                dp[l][r] = tmp;
            }
            for (int m = l + 1; m < r; ++ m){
                tmp = dp[l][m] + dp[m + 1][r];
                if (tmp.size() < dp[l][r].size()){
                    dp[l][r] = tmp;
                }
            }
        }
    }
    return dp[0][n - 1];
}
int getCircleCnt(string &s){
    int n = s.size();
    for (int c = 1; c <= n; ++ c){
        int i = c, j;
        string tmp = s.substr(0, i);
        while ((j = s.find(tmp, i)) != string::npos && j == i){
            i += c;
        }
        if (i == n){
            return c;
        }
    }
    return -1;
}