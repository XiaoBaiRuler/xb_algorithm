#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 363. 矩形区域不超过 K 的最大数值和
 * https://leetcode.cn/submissions/detail/291833852/
 * 
 * 1. 枚举上下边界n^2
 * 2. 计算前序和v, 通过set查询出第一个比s - k大的数字 nlogn
 * @param matrix 
 * @param k 
 * @return int 
 */
int maxSumSubmatrix(vector<vector<int>>& matrix, int k);
/**
 * @brief 枚举上下边角，超时
 * 
 * @param matrix 
 * @param k 
 * @return int 
 */
int maxSumSubmatrixOld(vector<vector<int>>& matrix, int k);
int main(){
    vector<vector<int>> matrix = {
        {1, 0, 1},
        {0, -2, 3}
    };
    cout << maxSumSubmatrix(matrix, 2) << endl;
    return EXIT_SUCCESS;
}
int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int ans = INT_MIN;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; ++i) { // 枚举上边界
        vector<int> sum(n);
        for (int j = i; j < m; ++j) { // 枚举下边界
            for (int c = 0; c < n; ++c) {
                sum[c] += matrix[j][c]; // 更新每列的元素和
            }
            set<int> sumSet{0};
            int s = 0;
            for (int v : sum) {
                s += v;
                auto lb = sumSet.lower_bound(s - k);
                if (lb != sumSet.end()) {
                    ans = max(ans, s - *lb);
                }
                sumSet.insert(s);
            }
        }
    }
    return ans;
}
int maxSumSubmatrixOld(vector<vector<int>>& matrix, int k) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            pre[i][j] = pre[i][j - 1] + matrix[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            pre[i][j] += pre[i - 1][j];
        }
    }
    bool f = k > 0;
    int max = INT_MIN;
    for (int i = 0; i < n; ++ i){
        for (int j = i; j < n; ++ j){
            int now, l = 0;
            while (l < m){
                for (int r = l; r < m; ++ r){
                    now = pre[j + 1][r + 1] + pre[i][l] - pre[j + 1][l] - pre[i][r + 1];
                    if (now == k){
                        return k;
                    }
                    if (now < k && now > max){
                        max = now;
                    }
                }
                ++ l;
            }
        }
    }
    return max;
}