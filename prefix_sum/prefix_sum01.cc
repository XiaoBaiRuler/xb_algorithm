#define PATH 1
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) : matri(matrix){
        int n = matri.size(), m = matri[0].size();
        for (int i = 0; i < n; ++ i){
            for (int j = 1; j < m; ++ j){
                matri[i][j] += matri[i][j - 1]; 
            }
        }
        for (int i = 1; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                matri[i][j] += matri[i - 1][j];
            }
        }
    }
    /**
     * @brief 304. 二维区域和检索 - 矩阵不可变
     * https://leetcode.cn/problems/range-sum-query-2d-immutable/
     * 
     * 二维数组前缀和
     * 
     * (row2, col2) + (row1 - 1, col1 - 1) - (row2, col1 - 1) - (row1 - 1)(col2)
     * @param row1 
     * @param col1 
     * @param row2 
     * @param col2 
     * @return int 
     */
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0){
            return matri[row2][col2];
        }
        else if (row1 == 0){
            return matri[row2][col2] - matri[row2][col1 - 1];
        }
        else if (col1 == 0){
            return matri[row2][col2] - matri[row1 - 1][col2];
        }
        else {
            return matri[row2][col2] + matri[row1 - 1][col1 - 1] - matri[row2][col1 - 1] - matri[row1 - 1][col2];
        }
    }
    vector<vector<int>> matri;
};
int main(){
    vector<vector<int>> matrix = {
        {3,0,1,4,2},
        {5,6,3,2,1},
        {1,2,0,1,5},
        {4,1,0,1,7}
    };
    NumMatrix nm(matrix);
    cout << nm.sumRegion(1,2,2,4) << endl;
    return EXIT_SUCCESS;
}
