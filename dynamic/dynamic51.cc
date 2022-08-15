#include "..//common//common.h"
int calculatePoints(vector<int>& boxes, int l, int r, int k);
/**
 * @brief 546. 移除盒子
 * https://leetcode.cn/problems/remove-boxes/
 * 
 * (i,j,k)表示: 范围为 [i,j]，再加上 j 之后 k 个与 j 颜色相同的方块构成的最大分数
 * => 策略1: (i, j, 0) + (k + 1) * (k + 1)
 * => 策略2: a从[i, j), 如果和j位置的颜色相同，那么以该位置分割
 *      左边: (i, a, k + 1)
 *      右边: (a + 1, r - 1, 0)
 *      
 * @param boxes 
 * @return int 
 */
int removeBoxes(vector<int>& boxes);
int main(){
    vector<int> boxes = {1,3,2,2,2,3,4,3,1};
    cout << removeBoxes(boxes) << endl;
    return EXIT_SUCCESS;
}
vector<vector<vector<int>>> dp;
int removeBoxes(vector<int>& boxes) {
    int n = min(100, (int)boxes.size());
    dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, 0)));
    return calculatePoints(boxes, 0, n - 1, 0);
}

int calculatePoints(vector<int>& boxes, int l, int r, int k) {
    // 0序列
    if (l > r) {
        return 0;
    }
    // 已经计算
    if (dp[l][r][k] != 0){
        return dp[l][r][k];
    }
    // 尽可能获取最大的长度
    int rr = r, kk = k;
    while (l < rr && boxes[rr] == boxes[rr - 1]){
        -- rr;
        ++ kk;
    }
    // 第一种策略
    dp[l][r][k] = calculatePoints(boxes, l, rr - 1, 0) + (kk + 1) * (kk + 1);
    // 其他策略
    for (int i = l; i < rr; i++) {
        if (boxes[i] == boxes[rr]) {
            dp[l][r][k] = max(dp[l][r][k], calculatePoints(boxes, i + 1, rr - 1, 0) + calculatePoints(boxes, l, i, kk + 1));
        }
    }
    return dp[l][r][k];
}