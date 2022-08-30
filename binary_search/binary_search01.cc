#include "../common/common.h"
/**
 * @brief 69. x 的平方根 
 * https://leetcode.cn/problems/sqrtx/
 * 
 * 范围: [0, x]
 * 中间值: l + ((l - l) / 2)
 * 
 * @param x 
 * @return int 
 */
int mySqrt(int x);
int main(){
    cout << mySqrt(INT_MAX) << endl;
    return EXIT_SUCCESS;
}
int mySqrt(int x) {
    int l = 0, r = x;
    long long tmp, mid;
    while (l <= r){
        mid = l + ((r - l) >> 1);
        tmp = mid * mid;
        if (tmp == x){
            return mid;
        }
        else if (tmp > x){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return r;
}