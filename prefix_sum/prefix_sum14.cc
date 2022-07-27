#define PATH 1
#if PATH == 1
#include "E:\GitStore\xb_algorithm\common\common.h"
#else
#include "G:\algorithm\xb_algorithm\common\common.h"
#endif
/**
 * @brief 152. 乘积最大子数组
 * https://leetcode.cn/problems/maximum-product-subarray/
 * 
 * 正数: 记录最小值
 * 负数: 记录最大值
 * 注意当前缀积等于0会使状态变为0
 * @param nums 
 * @return int 
 */
int maxProduct(vector<int>& nums);
int main(){
    vector<int> nums = {2, 3, -2, 4};
    cout << maxProduct(nums) << endl;
    return EXIT_SUCCESS;
}
int maxProduct(vector<int>& nums) {
    int res = INT_MIN, mina = 1, minb = INT_MIN, now = 1;
    for (int i : nums){
        now *= i;
        if (now > 0){
            res = max(res, now / mina);
            mina = min(now, mina);
        }
        else if (now < 0){
            res = max(res, minb == INT_MIN ? now : now / minb);
            minb = max(now, minb);
        }
        else{
            res = max(res, 0);
            now = 1;
            minb = INT_MIN;
            mina = 1;
        }
    }
    return res;
}