#include "..//common//common.h"
/**
 * @brief 面试题 17.24. 最大子矩阵
 * https://leetcode.cn/problems/max-submatrix-lcci/
 * 
 * 前序和 + 枚举两个端点
 * @param matrix 
 * @return vector<int> 
 */
vector<int> getMaxMatrix(vector<vector<int>>& matrix);
int main(){
    vector<vector<int>> matrix = {
        {-1, 0},
        {0, -1}
    };
    vector<int> res = getMaxMatrix(matrix); 
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> all(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            all[i][j] = all[i][j - 1] + matrix[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= m; ++ i){
        for (int j = 1; j <= n; ++ j){
            all[j][i] += all[j - 1][i];
        }
    }
    vector<int> res(4, 0);
    int max = INT_MIN;
    for (int i = 0; i < n; ++ i){
        for (int j = i; j < n; ++ j){
            int nowMax = 0, l = 0;
            for (int r = 0; r < m; ++ r){
                nowMax = all[j + 1][r + 1] + all[i][l] - all[j + 1][l] - all[i][r + 1];
                if (max < nowMax){
                    max = nowMax;
                    res[0] = i;
                    res[1] = l;
                    res[2] = j;
                    res[3] = r;
                }
                // 当左侧值小于0，那么对于接下来的求最大值，都是负资产
                if (nowMax < 0){
                    nowMax = 0;
                    l = r + 1;
                }
            }
        }
    }
    return res;
}