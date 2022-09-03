#include "../common/common.h"
bool isBadVersion(int t);
/**
 * @brief 278. 第一个错误的版本
 * https://leetcode.cn/problems/first-bad-version/
 * 
 * 范围: [1, n]
 * mid: l + ((r - l) >> 1)
 * 注意值1
 * @param n 
 * @return int 
 */
int firstBadVersion(int n);
int target = 2147483647;
int main(){
    cout << firstBadVersion(INT_MAX) << endl;
    return EXIT_SUCCESS;
}
int firstBadVersion(int n) {
    if (isBadVersion(1)){
        return 1;
    }
    int l = 2, mid;
    while (l <= n){
        mid = l + ((n - l) >> 1);
        bool f = isBadVersion(mid);
        if (f && !isBadVersion(mid - 1)){
            return mid;
        }
        else if (!f){
            l = mid + 1;
        }
        else{
            n = mid - 1;
        }
    }
    return n;
}
bool isBadVersion(int t){
    return t >= target;
}