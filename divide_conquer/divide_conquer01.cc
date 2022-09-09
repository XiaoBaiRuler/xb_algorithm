#include "../common/common.h"
/**
 * @brief 50. Pow(x, n)
 * https://leetcode.cn/problems/powx-n/
 * 
 * 由a^2b = a^b * a^b
 * 可以通过分治方法推导到结果
 * 注意奇数
 */
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0){
            return 1;
        }
        b = x;
        return circle(n);
    }
    double circle(int n){
        if (n == 1){
            return b;
        }
        if (n == -1){
            return 1 / b;
        }
        double next = circle(n >> 1);
        next *= next;
        return (n & 1) ? next * b : next;
    }
private:
    double b;
};
int main(){
    Solution t;
    cout << t.myPow(2, 10) << endl;
    cout << t.myPow(2, -3) << endl; 
    return EXIT_SUCCESS;
}