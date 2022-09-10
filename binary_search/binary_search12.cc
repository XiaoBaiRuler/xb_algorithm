#include "../common/common.h"
/**
 * @brief 367. 有效的完全平方数
 * https://leetcode.cn/problems/valid-perfect-square/
 * 
 * 范围[r, sqrt(INT_MAX)]
 * mid: l + ((r - l) >> 1)
 * @param num 
 * @return true 
 * @return false 
 */
bool isPerfectSquare(int num);
int main(){
    cout << isPerfectSquare(2147395600) << endl;
    return EXIT_SUCCESS;
}
bool isPerfectSquare(int num) {
    int l = 1, r = num > 46340 ? 46340 : num;
    while(l <= r){
        int mid = l + ((r - l) >> 1);
        int tmp = mid * mid;
        if (tmp == num){
            return true;
        }
        else if (tmp > num){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return false;
}