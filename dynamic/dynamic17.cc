#include "..//common//common.h"
/**
 * @brief 1230. 抛掷硬币
 * https://leetcode.cn/problems/toss-strange-coins/
 * 
 * 先特例再一般
 * 
 * 1. 当一个正面硬币都没有时，i表示数组长度[0, n]
 * => 0 # 1 - prob[0]
 * => 1 # (1 - prob[0])(1 - prob[1])
 * => ....
 * => i # (1 - prob[0]) .... (1 - prob[i])
 * 
 * 2. 当仅仅只有一个硬币正面时，i位置的概率是多少?
 * => 当dp[1] = (选正面时: 在一个正面的硬币没有情况下，0处选反面的概率 * prob[0]) + (选反面时: 在一个正面的硬币没有情况下，0处选正面的概率 * (1 - prob[0]))
 * 
 * ....
 * 
 * 以此类推
 * 通过选i - 1个硬币的情况，推导到选i个硬币的情况
 * 不妨设，1是正面，0是反面
 * 推导公式是 dp[1][i] = dp[0][i - 1] * prob[i - 1] + dp[1][i - 1] * (1 - prob[i - 1])
 * 另外，为了减少边界判断，边界设为n
 * 
 * @param prob 
 * @param target 
 * @return double 
 */
double probabilityOfHeads(vector<double>& prob, int target);
int main(){
    vector<vector<double>> probs = {
        {0.4},
        {0.5,0.5,0.5,0.5,0.5},
        {0.5,0.5,0.5,0.5,0.5}
    };
    vector<int> target = {1, 0, 3};
    int n = probs.size();
    for (int i = 0; i < n; ++ i){
        cout << probabilityOfHeads(probs[i], target[i]) << " ";
    }
    cout << endl;
    return EXIT_SUCCESS;
}
double probabilityOfHeads(vector<double>& prob, int target) {
    int n = prob.size();
    vector<vector<double>> dp(2, vector<double>(n + 1));
    dp[0][1] = 1 - prob[0];
    for (int i = 2; i <= n; ++ i){
        dp[0][i] = (1 - prob[i - 1]) * dp[0][i - 1];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= target; ++ i){
        for (int j = i; j <= n; ++ j){
            dp[1][j] = dp[0][j - 1] * prob[j - 1] + dp[1][j - 1] * (1 - prob[j - 1]);
        }
        vector<double> &item = dp[0];
        dp[0] = dp[1];
        dp[1] = item;
        for (int j = i; j <= n; ++ j){
            dp[1][j] = 0;
        }
    }
    return dp[0][n];
}