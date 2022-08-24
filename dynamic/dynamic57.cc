#include "../common/common.h"
/**
 * @brief 343. 整数拆分
 * 
 * https://leetcode.cn/problems/integer-break/
 * 
 * 设(i)为对应值的拆分整数的最大值
 * 
 * 缩小规模:长度: c[2, n]
 * 
 * 当前得值
 * 1. j * (i - j)
 * 2. j * (c - j)
 * @param n 
 * @return int 
 */
int integerBreak(int n);
/**
 * @brief 
 * 数学方法:
 * 
 * 求函数y=(n/x)^x(x>0)的最大值，可得x=e时y最大，但只能分解成整数，故x取2或3
 * 
 * 3 * 3 * 3 * a
 * 
 * @param n 
 * @return int 
 */
int integerBreakMath(int n);
int main(){
    cout << integerBreak(36) << endl;
    cout << integerBreakMath(36) << endl; 
    return EXIT_SUCCESS;
}
int integerBreak(int n) {
    vector<int> dp(n + 1);
    for (int i = 2; i <= n; i++) {
        int curMax = 0;
        for (int j = 1; j < i; j++) {
            curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
        }
        dp[i] = curMax;
    }
    return dp[n];
}
int integerBreakMath(int n){
    if (n < 4){
        return n - 1;
    }
    int now = 1;
    while (n > 4){
        n -= 3;
        now *= 3;
    }
    return now * n;
}