#include "..//common//common.h"
/**
 * @brief 871. 最低加油次数
 * https://leetcode.cn/problems/minimum-number-of-refueling-stops/
 * 
 * 结果是求最低加油次数，那么就用i次加油后可以最大行驶距离作为dp
 * => 那么有[0, N]种情况， dp[0] = startFuel
 * => i地方的油是否加，取决于它前面[i,0]处的最大行驶距离是否大于或等于stations[i][0]距离
 * => 如果符合以上条件，那么就可以加这次油量后，
 *      dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
 * 
 * @param target 
 * @param startFuel 
 * @param stations 
 * @return int 
 */
int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations);

int main(){
    vector<vector<int>> stations = {
        {10,60},{20,30},{30, 30},{60,40}
    };
    cout << minRefuelStops(100, 10, stations) << endl;
    return EXIT_SUCCESS;
}

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int n = stations.size();
    vector<long long> dp(n + 1);
    dp[0] = startFuel;
    for (int i = 0; i < n; ++ i){
        for (int j = i; j >= 0; --j){
            if (dp[j] >= stations[i][0]){
                dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
            }
        }
    }
    for (int i = 0; i <= n; ++ i){
        if (dp[i] >= target){
            return i;
        }
    }
    return -1;
}