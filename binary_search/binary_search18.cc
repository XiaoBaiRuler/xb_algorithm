#include "../common/common.h"
class Solution {
public:
    /**
     * @brief 410. 分割数组的最大值
     * https://leetcode.cn/problems/split-array-largest-sum/
     * 
     * 找出结果可能的值为[max(nums), sum(nums)] = [l, r]
     * 取其中间值mid = l + ((r - l) >> 1)
     * 设是否以最大值为mid可以构成m个数组为f(x)函数
     * 1. 当f(mid) && !f(mid - 1)时 mid为结果
     * 2. 否则，当!f(mid)时, r = mid + 1;
     * 3. 其他，l = mid;
     * 
     * @param nums 
     * @param m 
     * @return int 
     */
    int splitArray(vector<int>& nums, int m) {
        n = nums.size() - 1;
        t = m;
        int ll = 0, rr = 0;
        for (int i : nums){
            if (i > ll){
                ll = i;
            }
            rr += i;
        }
        if (check(nums, ll)){
            return ll;
        }
        while (ll < rr){
            int mid = ll + ((rr - ll) >> 1);
            bool f = check(nums, mid);
            if (f && !check(nums, mid - 1)){
                return mid;
            }
            else if (!f){
                ll = mid + 1;
            }
            else{
                rr = mid;
            }
        }
        return ll;
    }
    /**
     * @brief 
     * 贪心估算它在最坏情况下，即每个数组都在刚刚好小于或等于x时，所有数组的个数为c
     * 如果c小于或等于m时，才成功；否则失败
     * 
     * @param nums 
     * @param x 
     * @return true 
     * @return false 
     */
    bool check(vector<int>& nums, int x){
        int now = 0, c = 1;
        for (int i = 0; i <= n; ++ i){
            if (now + nums[i] > x){
                now = nums[i];
                ++ c;
            }
            else{
                now += nums[i];
            }
        }
        return c <= t;
    }
private:
    int n, t;
};
int main(){
    vector<int> nums = {1,2,3,4,5};
    Solution s;
    cout << s.splitArray(nums, 2) << endl;
    return EXIT_SUCCESS;
}