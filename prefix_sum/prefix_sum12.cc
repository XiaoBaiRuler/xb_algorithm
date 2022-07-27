#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 1074. 元素和为目标值的子矩阵数量
 * https://leetcode.cn/problems/number-of-submatrices-that-sum-to-target/
 * 双维度 + 从上到下的前缀和(数组) + 从左到右的前缀和(map)
 * @param matrix 
 * @param target 
 * @return int 
 */
int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target);
int main(){
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };
    cout << numSubmatrixSumTarget(matrix, 0) << endl;
    return EXIT_SUCCESS;
}
int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size(), res = 0;
    for (int i = 0; i < n; ++ i){
        vector<int> pre(m, 0);
        for (int j = i; j < n; ++ j){
            unordered_map<int, int> map;
            map[0] = 1;
            for (int l = 0, now = 0; l < m; ++ l){
                pre[l] += matrix[j][l];
                now += pre[l];
                if (map.find(now - target) != map.end()){
                    res += map[now - target];
                }
                map[now] += 1;
            }
        }
    }
    return res;
}