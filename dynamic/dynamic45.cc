#define PATH 1
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 647. 回文子串
 * https://leetcode.cn/problems/palindromic-substrings/
 * 
 * 设(l, r)表示l - r能不能构成回文串
 * 1. 当s[l] == s[r]时
 *      1.1 如果r - l = 1，那么构成ABA形式的回文串
 *      1.2 如果(l + 1, r - 1)也是回文串, 那么构成AB*BA形式的回文串
 * @param s 
 * @return int 
 */
int countSubstrings(string s);
int main(){
    cout << countSubstrings("aaa") << endl;
    return EXIT_SUCCESS;
}
int countSubstrings(string s) {
    int n = s.size(), res = 0;
    vector<vector<bool>> g(n, vector<bool>(n, false));
    for (int r = 0; r < n; r ++) {
        g[r][r] = true;
        res += 1;
        for (int l = r - 1; l >= 0; l --) {
            if (s[l] == s[r]) {
                g[l][r] = r - l == 1 || g[l + 1][r - 1];
                res += g[l][r];
            }
        }
    }
    return res;
}