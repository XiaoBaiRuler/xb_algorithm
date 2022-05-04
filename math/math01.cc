#include "E:\GitStore\xb_algorithm\common\common.h"
/**
 * @brief 1823. 找出游戏的获胜者
 * https://leetcode-cn.com/problems/find-the-winner-of-the-circular-game/
 * 
 * 解决方法:约瑟夫环——公式法（递推公式）
 * https://blog.csdn.net/u011500062/article/details/72855826
 * @param n 
 * @param k 
 * @return int 
 */
int findTheWinner(int n, int k);
int main(){
    vector<int> n = {5, 6};
    vector<int> k = {2, 5};
    int s = n.size();
    for (int i = 0; i < s; ++ i){
        cout << findTheWinner(n[i], k[i]) << " ";
    }
    return 0;
}
int findTheWinner(int n, int k) {
    int p = 0;
    for(int i = 2; i <= n; ++ i){
        p = (p + k) % i;
    }
    return p + 1;
}