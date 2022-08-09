#include "..//common//common.h"
/**
 * @brief  975. 奇偶跳
 * https://leetcode.cn/problems/odd-even-jump/
 * 
 * // 奇跳: 找比他最近的大于或等于的值
 * // 偶跳: 找比他最近的小于或等于的值
 * 
 * 1. 不妨设，在某个位置奇跳或偶跳能不能到达终点, dp[n][2] 
 * => 那么终点是奇跳和偶跳都能成功
 * => 当前进行奇跳, 那么当前是否到达终点，取决于之前第一个大于或等于值中的偶跳能不能达到终点
 * => 当前进行偶跳，那么当前是否达到终点，取决于之前第一个小于或等于值中的奇跳能不能达到终点
 * 
 * => 如果当前的奇跳能到达终点，那么结果 + 1
 * 
 * 2. 那么怎样求第一个比当前值 大于或等于? 小于或等于?
 * 
 * => 借助C++的map
 * => map::lower_bound(key):返回map中第一个大于或等于key的迭代器指针
 * => map::upper_bound(key):返回map中第一个大于key的迭代器指针, 倒退一个就是小于或等于
 * 
 * @param arr 
 * @return int 
 */
int oddEvenJumps(vector<int>& arr);
int main(){
    vector<vector<int>> arrs = {
        {10,13,12,14,15},
        {2,3,1,1,4},
        {5,1,3,4,2}
    };
    int n = arrs.size();
    for (int i = 0; i < n; ++ i){
        cout << oddEvenJumps(arrs[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}

int oddEvenJumps(vector<int>& arr) {
    int n = arr.size(), res = 1;
    map<int, int> ma;
    vector<vector<bool>> dp(n, vector<bool>(2));
    dp[n - 1][0] = dp[n - 1][1] = true;
    ma[arr[n - 1]] = n - 1;
    for (int i = n - 2; i > -1; -- i){
        // 奇跳: 最近比他大的或等于
        auto it = ma.lower_bound(arr[i]);
        if (it != ma.end()){
            dp[i][1] = dp[it -> second][0];
        }
        // 偶跳: 最近比他小的或等于
        it = ma.upper_bound(arr[i]);
        if (it != ma.begin()){
            it --;
            dp[i][0] = dp[it -> second][1];
        }
        ma[arr[i]] = i;
        if (dp[i][1]){
            ++ res;
        }
    }
    return res;
}