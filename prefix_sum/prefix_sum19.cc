#include "..//common//common.h"
/**
 * @brief 1422. 分割字符串的最大得分
 * https://leetcode.cn/problems/maximum-score-after-splitting-a-string/
 * 
 * 后序和 + 前序和
 * @param s 
 * @return int 
 */
int maxScore(string s);
int main(){
    cout << maxScore("11000111") << endl;
    return EXIT_SUCCESS;
}
int maxScore(string s) {
    int n = s.size();
    vector<int> pre(n);
    for (int i = n - 1, tmp = 0; i > -1; -- i){
        tmp += s[i] == '1';
        pre[i] = tmp;
    }
    int res = 0;
    for (int i = 0, tmp = 0; i < n - 1; ++ i){
        tmp += s[i] == '0';
        res = max(res, tmp + pre[i + 1]);
    }
    return res;
}