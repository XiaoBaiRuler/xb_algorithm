#define PATH 1
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 370. 区间加法
 * https://leetcode.cn/problems/range-addition/
 * @param length 
 * @param updates 
 * @return vector<int> 
 */
vector<int> getModifiedArray(int length, vector<vector<int>>& updates);
int main(){
    vector<vector<int>> updates = {
        {1, 3, 2},
        {2, 4, 3},
        {0, 2, -2}
    };
    vector<int> res = getModifiedArray(5, updates);
    for (int i : res){
        cout << i << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    vector<int> res(length, 0);
    for (vector<int> &up : updates){
        res[up[0]] += up[2];
        if (up[1] + 1 < length){
            res[up[1] + 1] -= up[2];
        }
    }
    for (int i = 1; i < length; ++ i){
        res[i] += res[i - 1];
    }
    return res;
}