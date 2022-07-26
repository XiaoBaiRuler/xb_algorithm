#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 1477. 找两个和为目标值且不重叠的子数组
 * https://leetcode.cn/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
 * 前缀和 + 后缀和
 * 
 * @param arr 
 * @param target 
 * @return int 
 */
int minSumOfLengths(vector<int>& arr, int target);
int main(){
    vector<int> arr = {3, 2, 3, 4, 3};
    cout << minSumOfLengths(arr, 3) << endl;
    return EXIT_SUCCESS;
}
int minSumOfLengths(vector<int>& arr, int target) {
    int n = arr.size(), now = 0, l = INT_MAX, res = INT_MAX;
    unordered_map<int, int> map;
    map[0] = n;
    vector<int> index(n);
    for (int i = n - 1; i > -1; -- i){
        now += arr[i];
        if (map.find(now - target) != map.end()){
            l = min(map[now - target] - i, l);
        }
        index[i] = l;
        map[now] = i;
    }
    now = 0;
    l = INT_MAX;
    map.clear();
    map[0] = -1;
    for (int i = 0, e = n - 1; i < e; ++ i){
        now += arr[i];
        if (map.find(now - target) != map.end()){
            l = min(i - map[now - target], l);
        }
        if (l != INT_MAX && index[i + 1] != INT_MAX){
            res = min(l + index[i + 1], res);
        }
        map[now] = i;
    }
    return res == INT_MAX ? -1 : res;
}