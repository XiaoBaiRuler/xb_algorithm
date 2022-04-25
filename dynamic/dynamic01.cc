#include "G:\algorithm\xb_algorithm\common\common.h"
/**
 * @brief 873. 最长的斐波那契子序列的长度
 * https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence/
 *  
 * 动态规划方程
 * id 为 arr在(j, n)内的(arr[i] + arr[j])的索引 
 * dp[i][j] = d[j][id] + 1
 * 
 * 1. 由于dp[i][j]可能存在值的地方很少，是稀疏矩阵 
 * => 使用unordered_map来减少内存使用
 * 
 * 2. 由于没有重复的元素，可以使用一个unordered_map表示<值:索引>
 * 
 * 时间复杂度 O(N^2)
 * 空间复杂度 O(N) - O(N^2) 偏向于O(N)
 * 
 * @param arr 
 * @return int 
 */
int lenLongestFibSubseq(vector<int>& arr);
int main(){
    vector<int> arr = {1, 2, 3, 5, 8};
    cout << lenLongestFibSubseq(arr) << endl;
    return EXIT_SUCCESS;
}
int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size(), res = 0, m = n - 1;
    unordered_map<int, int> maps;
    for (int i = 0; i < n; ++i){
        maps[arr[i]] = i;
    }
    unordered_map<int, int> pre;
    for (int i = n - 3; i > -1; -- i)
        for (int j = i + 1; j < m; ++j) {
            int tmp = arr[i] + arr[j], id;
            if (tmp < arr[j + 1]){
                continue;
            }
            if (maps.find(tmp) != maps.end() && (id = maps[tmp]) > j){
                tmp = j * n + id;
                tmp = (pre.find(tmp) != pre.end()) ? pre[tmp] + 1 : 1;
                pre[i * n + j] = tmp;
                if (tmp + 2 > res){
                    res = tmp + 2;
                }
            }
        }

    return res;
}