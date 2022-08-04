#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 730. 统计不同回文子序列
 * https://leetcode.cn/problems/count-different-palindromic-subsequences/
 * 
 * 类似统计回文子序列，区间动态规划: i - j范围内的最大不同回文子序列
 * 
 * 1. 由于字符只有'a''b''c''d', 那么可以根据各个字符作为边界[l, r]时，进行统计(不会出现重复)
 * 1.1. l == r时， 单个字符(k) + 1
 * 1.2. l == r - 1时，两个字符(k / kk) + 2
 * 1.3. 不存在该字符时，+ 0
 * 1.4. 其他情况kxxxk时，+ dp[l + 1][r - 1] + 2;
 * 
 * @param s 
 * @return int 
 */
int countPalindromicSubsequences(string s);
int main(){
    cout << countPalindromicSubsequences("bccb") << endl;
    return EXIT_SUCCESS;
}
int countPalindromicSubsequences(string s) {
    int n = s.size(), max = 1000000007;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    array<int, 4> l, r;
    fill(l.begin(), l.end(), -1);
    for (int i = n - 1; i > -1; -- i){
        l[s[i] - 97] = i;
        fill(r.begin(), r.end(), -1);
        for (int j = i; j < n; ++ j){
            r[s[j] - 97] = j;
            for (int k = 0; k < 4; ++ k){
                if (l[k] != -1 && r[k] != -1){
                    if (l[k] == r[k]){
                        dp[i][j] = (dp[i][j] + 1) % max;
                    }    
                    else if (l[k] == r[k] - 1){
                        dp[i][j] = (dp[i][j] + 2) % max;
                    }
                    else{
                        dp[i][j] = (dp[i][j] + dp[l[k] + 1][r[k] - 1] + 2) % max; 
                    }
                }
            }
        }
    }
    return dp[0][n - 1];
}