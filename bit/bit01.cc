#include "../common/common.h"
/**
 * @brief 201. 数字范围按位与
 * https://leetcode.cn/problems/bitwise-and-of-numbers-range/
 * 
 * eg: [5, 7]: 
 * b[0000 1001]
 * e[0000 1011] 如果当前位之前不相等，那么该位在范围内必然存在0
 * r[0000 10xx]
 */
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i = 0;
        while (left != right){
            left >>= 1;
            right >>= 1;
            ++ i;
        }
        return left << i;
    }
};
int main(){
    cout << Solution().rangeBitwiseAnd(5, 7) << endl;
    return EXIT_SUCCESS;
}