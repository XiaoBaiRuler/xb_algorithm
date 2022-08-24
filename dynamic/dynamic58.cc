#include "../common/common.h"
int MAX = 2123366400;
/**
 * @brief 264. 丑数 II
 * https://leetcode.cn/problems/ugly-number-ii/
 * 
 * 设(i)为对应第i个的值
 * 1. 1                 c2,c3,c5=1,1,1
 * 2. 2 (c2) * 2        c2,c3,c5=2,1,1
 * 3. 3 (c3) * 3        c2,c3,c5=2,2,1
 * 4. 4 (c2) * 2        c2,c3,c5=3,2,1
 * 5. 5 (c5) * 5        c2,c3,c5=3,2,2
 * 6. 6 (c2) * 3        c2,c3,c5=4,2,2
 * 7. 8 (c2) * 2        c2,c3,c5=5,2,2
 * 
 * 那么对应2, 3, 5对应之前最小值c2 = 1, c3 = 1, c5 = 1
 * => 当前值: (c2) * 2, (c3) * 3, (c5) * 5 中的最小值
 * => 选定值后，对应的值也要加 + 1
 * @param n 
 * @return int 
 */
int nthUglyNumber(int n);
int main(){
    cout << nthUglyNumber(37) << endl;
    return EXIT_SUCCESS;
}
int nthUglyNumber(int n) {
    vector<int> dp(n + 1);
    dp[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; i++) {
        int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
        dp[i] = min(min(num2, num3), num5);
        if (dp[i] == num2) {
            p2++;
        }
        if (dp[i] == num3) {
            p3++;
        }
        if (dp[i] == num5) {
            p5++;
        }
    }
    return dp[n];
}