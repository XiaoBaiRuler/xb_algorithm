#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 32. 最长有效括号
 * https://leetcode-cn.com/problems/longest-valid-parentheses/
 * 
 * 动态规划，考虑)结尾的情况
 * 1. (): dp[i] = dp[i - 2] + 2;
 * 2. xxx))
 * 2.1. ((xxx)) 也即是i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(': 就是更前面的)也要考虑
 *      => dp[i - dp[i - 1] - 2] + dp[i - 1] + 2
 * 2.2. (xxx)) dp[i - 1] + 2;
 * @param s 
 * @return int 
 */
int longestValidParentheses(string s);
int main(){
    vector<string> s = {
        "(()",
        ")()())",
        ""};
    int n = s.size();
    for (int i = 0; i < n; ++ i){
        cout << longestValidParentheses(s[i]) << " ";
    }
    cout << endl;
}
int longestValidParentheses(string s) {
    int n = s.size();
    if (n < 2){
        return 0;
    }
    vector<int> dp(n, 0);
    char pc = s[0];
    int res = 0;
    for (int i = 1; i < n; ++ i){
        char nc = s[i];
        if (nc == ')'){
            if (pc == '('){
                dp[i] = i > 1 ? dp[i - 2] + 2 : 2;
            }
            else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '('){
                dp[i] = dp[i - 1] + ((i - dp[i - 1]) > 1 ? dp[i - dp[i - 1] - 2] + 2 : 2);
            }
            res = max(res, dp[i]);
        }
        pc = nc;
    }
    return res;
}