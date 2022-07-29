#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 1310. 子数组异或查询
 * https://leetcode.cn/problems/xor-queries-of-a-subarray/
 * 
 * => a ^ b ^ c = d
 * => b ^ c = d ^ a
 * @param arr 
 * @param queries 
 * @return vector<int> 
 */
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries);
int main(){
    vector<int> arr = {1, 3, 4, 8};
    vector<vector<int>> queries = {
        {0, 1}, {1, 2}, {0, 3}, {3, 3}
    };
    vector<int> res = xorQueries(arr, queries);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size(), pre = 0, now = 0;
    for (int i = 0; i < n; ++ i){
        now ^= arr[i];
        arr[i] = pre;
        pre = now;
    }
    arr.push_back(pre);
    vector<int> res;
    for (vector<int>& q : queries){
        res.push_back(arr[q[1] + 1] ^ arr[q[0]]);
    }
    return res;
}