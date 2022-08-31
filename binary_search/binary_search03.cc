#include "../common/common.h"
int guess(int num);
/**
 * @brief 374. 猜数字大小
 * https://leetcode.cn/problems/guess-number-higher-or-lower/
 * 
 * 范围: [1, n]
 * mid: l + ((n - l) >> 1)
 * @param n 
 * @return int 
 */
int guessNumber(int n);
int pick;
int main(){
    pick = 6;
    cout << guessNumber(100) << endl;
    return EXIT_SUCCESS;
}
int guessNumber(int n) {
    int l = 1, mid, tmp;
    while (l <= n){
        mid = l + ((n - l) >> 1);
        tmp = guess(mid);
        if (tmp == 0){
            return mid;
        }
        else if (tmp == 1){
            l = mid + 1;
        }
        else{
            n = mid - 1;
        }
    }
    return n;
}
int guess(int num){
    if (num == pick){
        return 0;
    }
    return num < pick ? 1 : -1;
}