#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 1252. 奇数值单元格的数目
 * https://leetcode.cn/problems/cells-with-odd-values-in-a-matrix/
 * 
 * 简单索引的使用
 * @param m 
 * @param n 
 * @param indices 
 * @return int 
 */
int oddCells(int m, int n, vector<vector<int>>& indices);
int main(){
    vector<vector<int>> indices = {{0, 1}, {1, 1}};
    cout << oddCells(2, 3, indices) << endl; 
    return EXIT_SUCCESS;
}
int oddCells(int m, int n, vector<vector<int>>& indices) {
    vector<int> h(m, 0), w(n, 0);
    for (auto it : indices){
        ++ h[it[0]];
        ++ w[it[1]]; 
    }
    int j1 = 0, o1 = 0;
    for (int i : h){
        j1 += i & 1;
        o1 += (i & 1) ^ 1;
    }
    int j2 = 0, o2 = 0;
    for (int j : w){
        j2 += j & 1;
        o2 += (j & 1) ^ 1;
    }
    return j1 * o2 + j2 * o1;
}