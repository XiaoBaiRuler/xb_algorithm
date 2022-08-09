#include "..//common//common.h"
class Solution {
public:
    /**
     * @brief 473. 火柴拼正方形
     * https://leetcode.cn/problems/matchsticks-to-square/
     * 
     * 类似四叉树的遍历，由于四条边的一致性，也就是和放那条边的位置无关
     * 
     * 1. 放第一条边: 当出现超过平均值时，换下一条边
     * 2. 放第二条边: 当出现超过平均值时，换下一条边
     * 3. 放第三条边: 当出现超过平均值时，换下一条边
     * 4. 放第四条边: 当出现超过平均值时，换下一条边
     * 
     * 另外，在放下一条边时，必须保证之前的边是不是放了
     * 
     * @param matchsticks 
     * @return true 
     * @return false 
     */
    bool makesquare(vector<int>& matchsticks) {
        int s = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        n = matchsticks.size();
        if (s % 4 != 0 || n < 4){
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end());
        item = s / 4;
        for (int i = n - 1; i > -1; -- i){
            if (matchsticks[i] > item){
                return false;
            }
            else{
                break;
            }
        }
        return dfs(matchsticks, 0, 0, 0, 0, 0);
    }
    bool dfs(vector<int>& matchsticks, int i, int t, int b, int l, int r){
        if (i == n){
            return true;
        }
        if (t + matchsticks[i] <= item && dfs(matchsticks, i + 1, t + matchsticks[i], b, l, r)){
            return true;
        }
        if (t == 0){
            return false;
        }
        if (b + matchsticks[i] <= item && dfs(matchsticks, i + 1, t, b + matchsticks[i], l, r)){
            return true;
        }
        if (b == 0){
            return false;
        }
        if (l + matchsticks[i] <= item && dfs(matchsticks, i + 1, t, b, l + matchsticks[i], r)){
            return true;
        }
        if (l == 0){
            return false;
        }
        if (r + matchsticks[i] <= item && dfs(matchsticks, i + 1, t, b, l, r + matchsticks[i])){
            return true;
        }
        return false;
    }
private:
    int n, item;
};
int main(){
    vector<vector<int>> matchsticks = {
        {1,1,2,2,2},
        {3,3,3,3,4}
    };
    int n = matchsticks.size();
    for (int i = 0; i < n; ++ i){
        Solution t;
        cout << t.makesquare(matchsticks[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}