#include "..//common//common.h"
/**
 * @brief 403. 青蛙过河
 * https://leetcode.cn/problems/frog-jump/
 * 
 * 0位置，青蛙只能跳到1
 * 1位置，青蛙能跳到1 + 1, 1 + 2
 * 
 * 那么不妨设，青蛙跳到i位置时，的跳跃长度为set{j...}
 * - 那么遍历石头的，之前的跳跃长度列表，逐个+ 1, + 0, - 1; 所得值大于当前位置，给对应位置添加当前跳跃长度
 * - 那么当最后一个石头，所在位置的跳跃长度不为空时，即可以跳到，否则，反之。
 * 
 * 时间复杂度: O(n^2)
 * 空间复杂度: O(n^2)
 * @param stones 
 * @return true 
 * @return false 
 */
bool canCross(vector<int>& stones);
int main(){
    vector<vector<int>> stones = {
        {0,1,3,5,6,8,12,17},
        {0,1,2,3,4,8,9,11}
    };
    int n = stones.size();
    for (int i = 0; i < n; ++ i){
        cout << canCross(stones[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
bool canCross(vector<int>& stones) {
    unordered_map<int, unordered_set<int> *> ma;
    for (int i : stones){
        ma[i] = new unordered_set<int>();
    }
    unordered_set<int> * ps = ma[stones[0]];
    ps -> insert(0);
    int n = stones.size();
    for (int i = 0, tmp; i < n; ++ i){
        ps = ma[stones[i]];
        auto beg = ps -> begin(), end = ps -> end();
        for (; beg != end; ++ beg){
            tmp = stones[i] + (*beg) + 1;
            if (ma.find(tmp) != ma.end()){
                ma[tmp] -> insert((*beg) + 1);
            }
            tmp = stones[i] + (*beg);
            if (tmp > stones[i] && ma.find(tmp) != ma.end()){
                ma[tmp] -> insert((*beg));
            }
            tmp = stones[i] + (*beg) - 1;
            if (tmp > stones[i] && ma.find(tmp) != ma.end()){
                ma[tmp] -> insert((*beg) - 1);
            }
        }
    }
    return !(ma[stones[n - 1]] -> empty());
}