#include "../common/common.h"
/**
 * @brief 1306. 跳跃游戏 III
 * https://leetcode.cn/problems/jump-game-iii/
 */
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);
        deque<int> dq;
        vis[start] = true;
        dq.emplace_back(start);
        while (!dq.empty()){
            int m = dq.size();
            for (int i = 0; i < m; ++ i){
                int now = dq.front();
                dq.pop_front();
                if (arr[now] == 0){
                    return true;
                }
                int add = now + arr[now];
                if (add < n && !vis[add]){
                    dq.emplace_back(add);
                    vis[now] = true;
                }
                int reduce = now - arr[now];
                if (reduce > -1 && !vis[reduce]){
                    dq.emplace_back(reduce);
                    vis[reduce] = true;
                }
            }
        }
        return false;
    }
};
int main(){
    vector<int> nums = {4,2,3,0,3,1,2};
    cout << Solution().canReach(nums, 5) << endl;
    return EXIT_SUCCESS;
}