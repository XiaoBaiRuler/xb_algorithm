#define PATH 1
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 1314. 矩阵区域和
 * https://leetcode.cn/problems/matrix-block-sum/
 * 
 * 前缀和
 * @param mat 
 * @param k 
 * @return vector<vector<int>> 
 */
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k);
int main(){
    vector<vector<int>> mat  = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int>> res = matrixBlockSum(mat, 1);
    for (vector<int> &r : res){
        for (int i : r){
            cout << i << " ";
        }
        cout << endl;
    }
    return EXIT_SUCCESS;
}
vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> pre(n + 1, vector<int>(m + 1));
    for (int j = 0; j <= m; ++ j){
        pre[0][j] = 0;
    }
    for (int i = 1; i <= n; ++ i){
        pre[i][0] = 0;
        for(int j = 1; j <= m; ++ j){
            pre[i][j] = pre[i][j - 1] + mat[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            pre[i][j] += pre[i - 1][j];
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            int a = i + k + 1 > n ? n : i + k + 1;
            int b = j + k + 1 > m ? m : j + k + 1;
            int c = i - k < 0 ? 0 : i - k;
            int d = j - k < 0 ? 0 : j - k;
            mat[i][j] = pre[a][b] + pre[c][d] - pre[a][d] - pre[c][b];
        }
    }
    return mat;
}