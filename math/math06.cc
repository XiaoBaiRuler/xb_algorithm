#define PATH 2
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 497. 非重叠矩形中的随机点
 * https://leetcode.cn/problems/random-point-in-non-overlapping-rectangles/
 * 
 * 把每个整数点编号，然后随机编号 
 * => 编号 在前序和基础上二分查找索引
 * => 根据索引和编号反推点的位置 
 */
class Solution {
public:
    Solution(vector<vector<int>>& rects)  : rec(rects){
        hash.push_back(0);
        for (vector<int> &re : rects){
            max += (re[2] - re[0] + 1) * (re[3] - re[1] + 1);
            hash.push_back(max);
        }
        rec = rects;
    }
    
    vector<int> pick() {
        uniform_int_distribution<int> dis(0, max - 1);
        int i = dis(gen) % max;
        int mid = upper_bound(hash.begin(), hash.end(), i) - hash.begin() - 1;
        i = i - hash[mid];
        vector<int>& re = rec[mid];
        int x = re[3] - re[1] + 1;
        vector<int> res = {i / x + re[0], i % x + re[1]};
        return res;
    }
private:
    vector<int> hash;
    vector<vector<int>> &rec;
    int max = 0;
    mt19937 gen{random_device{}()};
};
int main(){
    vector<vector<int>> res = {{-2, -2, 1, 1}, {2, 2, 4, 6}};
    Solution s(res);
    int n = 5;
    for (int i = 0; i < n; ++ i){
        vector<int> item = s.pick();
        cout << "(" << item[0] << "," << item[1] << ")" << " ";
    }
    return EXIT_SUCCESS;
}